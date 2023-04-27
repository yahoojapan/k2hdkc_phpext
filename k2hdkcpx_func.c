/*
*
* K2HDKC PHP Extension library
* 
* Copyright 2023 Yahoo Japan Corporation.
* 
* K2HDKC is k2hash based distributed KVS cluster.
* K2HDKC uses K2HASH, CHMPX, FULLOCK libraries. K2HDKC supports
* distributed KVS cluster server program and client libraries.
* 
* For the full copyright and license information, please view
* the license file that was distributed with this source code.
*
* AUTHOR:   Hirotaka Wakabayashi
* CREATE:   Fri, Mar 31 2023
* REVISION:
*
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif


#include "php.h"
#include "ext/standard/info.h"
#include "php_k2hdkcpx.h"
#include "k2hdkcpx_compat.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE()			\
	ZEND_PARSE_PARAMETERS_START(0, 0)			\
	ZEND_PARSE_PARAMETERS_END()
#endif

// class entries
zend_class_entry* k2hdkcpx_class_entry;

zval* k2hdkcpx_read_property_resource(zend_class_entry* scope, zval* object, const char* name) {
	zval* pzval, tmp;
#if PHP_VERSION_ID < 80000
	pzval = zend_read_property(scope, object, name, strlen(name), 1, &tmp);
#else
	pzval = zend_read_property(scope, Z_OBJ_P(object), name, strlen(name), 1, &tmp);
#endif
	if(IS_RESOURCE != Z_TYPE_P(pzval)){
		php_error(E_ERROR, "The property(%s) is not a resource type.", name);
	}
	return pzval;
}

void k2hdkcpx_update_property_resource(zend_class_entry* scope, zval* object, const char* name, size_t name_length, zval* value) {
#if PHP_VERSION_ID < 80000
	zend_update_property(scope, object, name, name_length, value);
#else
	zend_update_property(scope, Z_OBJ_P(object), name, name_length, value);
#endif
}

int k2hdkcpx_handle_resource_number;
zend_resource* k2hdkcpx_handle_resource;
static void k2hdkcpx_handle_resource_dtor(zend_resource* rsrc)
{
	efree((k2hdkc_chmpx_h*)rsrc->ptr);
}

//
// PHP_FUNCTION ENTRIES START
//
PHP_FUNCTION(k2hdkcpx_open)
{
	// declare_variables
	char* config_file = NULL;
	size_t config_file_len = 0;
	zend_long port = 8031;
	char* cuk = NULL;
	size_t cuk_len = 0;
	zend_bool rejoin = true;
	zend_bool rejoin_forever = true;
	zend_bool clear_backup = true;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STRING(config_file, config_file_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(port)
		Z_PARAM_STRING(cuk, cuk_len)
		Z_PARAM_BOOL(rejoin)
		Z_PARAM_BOOL(rejoin_forever)
		Z_PARAM_BOOL(clear_backup)
		ZEND_PARSE_PARAMETERS_END();
	
	// validate_after_assign
	if(!config_file || 0 == config_file_len){
		php_error(E_ERROR, "k2hdkcpx_open: CHMPX configuration file path is empty.");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	k2hdkc_chmpx_h chmpx_handle = k2hdkc_open_chmpx_full(config_file, port, cuk, rejoin, rejoin_forever, clear_backup);
	if(CHM_INVALID_CHMPXHANDLE == chmpx_handle) {
		php_error(E_NOTICE, "k2hdkcpx_open: failed to open(join) CHMPX.");
		RETURN_FALSE;
	}
	
	// return_result after call_some_functions
	k2hdkc_chmpx_h* chmpx_handle_ptr = emalloc(sizeof(long)); // this resource destroy by using chmpx_handle_resource_dtor
	if (chmpx_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*chmpx_handle_ptr = chmpx_handle;
	RETURN_RES(zend_register_resource(chmpx_handle_ptr, k2hdkcpx_handle_resource_number)); // RETVAL_RES(r) and ZVAL_RES(return_value, r)
}

PHP_FUNCTION(k2hdkcpx_set_value)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* val = NULL;
	size_t val_len = 0;
	zend_bool clear_subkeys = false;
	zval* subkeys = NULL;	// NOTE: initial array of keys must be explicitly NULL to avoid SIGSEGV in Z_TYPE_P
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 7)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_STRING(val, val_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(clear_subkeys)
		Z_PARAM_ARRAY(subkeys)
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	
	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_k2hdkc_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_ERROR, "handle is empty.");
		RETURN_FALSE;
	}
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle_resource is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_set_str_all_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* pval, const char** pskeyarray, const char* encpass, const time_t* expire)
	bool bResult = false;
	if (subkeys && Z_TYPE_P(subkeys) == IS_ARRAY) {
		int skeypckcnt = zend_array_count(Z_ARR(*subkeys)); // returns number of elements in array.
		char** pskeyarray = (char**)calloc(skeypckcnt + 1, sizeof(char*));
		zend_ulong zulong_idx = 0;
		zend_string* zstring_key = NULL;
		zval* zv_val = NULL;

		ZEND_HASH_FOREACH_KEY_VAL(Z_ARR(*subkeys), zulong_idx, zstring_key, zv_val) {
			char* subkey = Z_STRVAL_P(zv_val);
			pskeyarray[zulong_idx] = (char*)malloc(strlen(subkey) + 1);
			memcpy(pskeyarray[zulong_idx], subkey, strlen(subkey));
			pskeyarray[zulong_idx][strlen(subkey)] = '\0';
		} ZEND_HASH_FOREACH_END();

		bResult = k2hdkc_pm_set_str_all_wa(*k2hdkc_chmpx_handle_ptr, key, val, (const char**)pskeyarray, password, ptmexpire);
		if (pskeyarray) {
			char** ptmp = NULL;
			for (ptmp = pskeyarray; *ptmp; ptmp++) {
				free(*ptmp);
			}
		}
	} else {
		bResult = k2hdkc_pm_set_str_all_wa(*k2hdkc_chmpx_handle_ptr, key, val, NULL, password, ptmexpire);
	}
	// return_result after call_some_functions
	if (bResult) {
		RETURN_TRUE;	// RETVAL_TRUE; return;
	}
	RETURN_FALSE;
}

// get
// bool k2hdkc_pm_get_str_value_wp(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, char** ppval);
PHP_FUNCTION(k2hdkcpx_get_value)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_k2hdkc_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_ERROR, "handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle_resource is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	
	// call_some_functions after get_resources
	//// k2hdkc_pm_get_str_value_wp(session.getHandle(), this.key, this.pass, ppval);
	char* pval;
	if (!k2hdkc_pm_get_str_value_wp(*k2hdkc_chmpx_handle_ptr, key, password, &pval)) {
		// return_result after call_some_functions
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}
	zend_string* retval = strpprintf(0, "%s", pval);
	free(pval);
    RETURN_STR(retval);
	// come here ???
}

// add_subkey
// bool k2hdkc_pm_set_str_subkey_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, const char* pskeyval, bool checkattr, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_add_subkey)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* subkey = NULL;
	size_t subkey_len = 0;
	char* subval = NULL;
	size_t subval_len = 0;
	zend_bool is_attr_checked = true;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(4, 7)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_STRING(subkey, subkey_len)
		Z_PARAM_STRING(subval, subval_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_attr_checked)
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	bool bResult = k2hdkc_pm_set_str_subkey_wa(*k2hdkc_chmpx_handle_ptr, key, subkey, subval, is_attr_checked, password, ptmexpire);
	// return_result after call_some_functions
	if (bResult) {
		RETURN_TRUE;	// RETVAL_TRUE; return;
	}
	RETURN_FALSE;

}

// cas_get
// bool k2hdkc_pm_cas64_str_get_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, uint64_t* pval)
PHP_FUNCTION(k2hdkcpx_cas_get)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool bResult = k2hdkc_pm_cas64_str_get_wa(*k2hdkc_chmpx_handle_ptr, key, NULL, (uint64_t*)&pval);
	int pval = 0;
	bool bResult = k2hdkc_pm_cas64_str_get_wa(*k2hdkc_chmpx_handle_ptr, key, NULL, (uint64_t*)&pval);
	if (!bResult || !pval) {
		// return_result after call_some_functions
		RETURN_FALSE;
	}
	RETURN_LONG(pval);
}

// cas_decrement
// bool k2hdkc_pm_cas_str_decrement_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_cas_decrement)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_cas_str_decrement_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_cas_str_decrement_wa(*k2hdkc_chmpx_handle_ptr, key, password, ptmexpire);
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_cas_str_decrement_wa should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// cas_increment
// bool k2hdkc_pm_cas_str_increment_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_cas_increment)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_cas_str_increment_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_cas_str_increment_wa(*k2hdkc_chmpx_handle_ptr, key, password, ptmexpire);
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_cas_str_increment_wa should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// cas_init
// bool k2hdkc_pm_cas8_str_init_wa(k2hdkc_chmpx_h handle, const char* pkey, uint8_t val, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_cas_init)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	zend_long val = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_LONG(val)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_cas64_str_init_wa(k2hdkc_chmpx_h handle, const char* pkey, uint64_t val, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_cas64_str_init_wa(*k2hdkc_chmpx_handle_ptr, key, (uint64_t)val, password, ptmexpire);
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_cas64_str_init_wa should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// cas_set
// bool k2hdkc_pm_cas8_str_set_wa(k2hdkc_chmpx_h handle, const char* pkey, uint8_t oldval, uint8_t newval, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_cas_set)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	zend_long old_val = 0;
	zend_long new_val = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(4, 6)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_LONG(old_val)
		Z_PARAM_LONG(new_val)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_cas64_str_set_wa(k2hdkc_chmpx_h handle, const char* pkey, uint64_t oldval, uint64_t newval, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_cas64_str_set_wa(*k2hdkc_chmpx_handle_ptr, key, old_val, new_val, password, ptmexpire);
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_cas64_str_set_wa should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// clear_subkeys
// bool k2hdkc_pm_clear_str_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
PHP_FUNCTION(k2hdkcpx_clear_subkeys)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	//// bool k2hdkc_pm_clear_str_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
	bool bResult = k2hdkc_pm_clear_str_subkeys(*k2hdkc_chmpx_handle_ptr, key);
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_clear_str_subkeys should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// bool k2hdkc_close_chmpx_ex(k2hdkc_chmpx_h handle, bool is_clean_bup)
PHP_FUNCTION(k2hdkcpx_close)
{
	// declare_variables
	zval* zval_k2hdkc_chmpx_handle_ptr = NULL;
	zend_bool clean_bup = true;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(clean_bup)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_k2hdkc_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_ERROR, "k2hdkcpx_close: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	k2hdkc_chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	
	// call_some_functions after get_resources
	k2hdkc_close_chmpx_ex(*chmpx_handle_ptr, clean_bup);
	
	// return_result after call_some_functions
	RETURN_TRUE;
}


// get_attributes
// PK2HDKCATTRPCK k2hdkc_pm_get_str_direct_attrs(k2hdkc_chmpx_h handle, const char* pkey, int* pattrspckcnt)
PHP_FUNCTION(k2hdkcpx_get_attributes)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// call_some_functions after get_resources
	//// PK2HDKCATTRPCK k2hdkc_pm_get_str_direct_attrs(k2hdkc_chmpx_h handle, const char* pkey, int* pattrspckcnt)
	int attrspckcnt = 0;
	PK2HDKCATTRPCK pattrs = k2hdkc_pm_get_str_direct_attrs(*k2hdkc_chmpx_handle_ptr, key, &attrspckcnt);
	if (pattrs && attrspckcnt > 0) {
		array_init(return_value);	// zval* return_value
		int	cnt;
		for(cnt = 0; cnt < attrspckcnt; ++cnt) {
			char*	pattrkey;
			if(NULL != (pattrkey = (char*)emalloc(pattrs[cnt].keylength + 1))) {
				memcpy(pattrkey, pattrs[cnt].pkey, pattrs[cnt].keylength);
				pattrkey[pattrs[cnt].keylength] = '\0';
				add_next_index_string(return_value, pattrkey);
				efree(pattrkey);
			}
		}
	}
	if(pattrs) {
		k2h_free_attrpack(pattrs, attrspckcnt);
	}
}
	
// get_subkeys
// PK2HDKCKEYPCK k2hdkc_pm_get_direct_subkeys(k2hdkc_chmpx_h handle, const unsigned char* pkey, size_t keylength, int* pskeypckcnt)
PHP_FUNCTION(k2hdkcpx_get_subkeys)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// call_some_functions after get_resources
	//// char** k2hdkc_pm_get_str_direct_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
	char** pskeyarray = k2hdkc_pm_get_str_direct_subkeys(*k2hdkc_chmpx_handle_ptr, key);
	array_init(return_value);	// zval* return_value
	if (pskeyarray) {
		char** ptmp = NULL;
		for (ptmp = pskeyarray; *ptmp; ptmp++) {
			add_next_index_str(return_value, strpprintf(0, "%s", *ptmp));
			free(*ptmp);
		}
	}
}

// queue_get
// bool k2hdkc_pm_q_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppval)
PHP_FUNCTION(k2hdkcpx_queue_get)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* prefix = NULL;
	size_t prefix_len = 0;
	zend_bool is_fifo = true;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(prefix, prefix_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_fifo)
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_q_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppval)
	const char* pval = NULL;
	bool bResult = k2hdkc_pm_q_str_pop_wp(*k2hdkc_chmpx_handle_ptr, prefix, is_fifo, NULL, &pval);
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkc_pm_q_str_pop_wp should return true, but false");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}
	zend_string* retval = strpprintf(0, "%s", pval);
	RETURN_STR(retval);
}

// queue_put
// bool k2hdkc_pm_q_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_queue_put)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* prefix = NULL;
	size_t prefix_len = 0;
	char* val = NULL;
	size_t val_len = 0;
	zend_bool is_fifo = true;
	zend_bool is_attr_checked = true;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 7)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(prefix, prefix_len)
		Z_PARAM_STRING(val, val_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_fifo)
		Z_PARAM_BOOL(is_attr_checked)
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_q_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_q_str_push_wa(*k2hdkc_chmpx_handle_ptr, prefix, val, is_fifo, is_attr_checked, password, ptmexpire);
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkc_pm_q_str_push_wa should return true but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// keyqueue_get
// bool k2hdkc_pm_keyq_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppkey, const char** ppval)
PHP_FUNCTION(k2hdkcpx_key_queue_get)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* prefix = NULL;
	size_t prefix_len = 0;
	zend_bool is_fifo = true;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(prefix, prefix_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_fifo)
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_keyq_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppkey, const char** ppval)
	const char* pkey = NULL;
	const char* pval = NULL;
	k2hdkc_pm_keyq_str_pop_wp(*k2hdkc_chmpx_handle_ptr, prefix, is_fifo, NULL, &pkey, &pval);
	array_init(return_value);	// zval* return_value
	if (pkey && pval) {
		add_assoc_string(return_value, pkey, pval);
	}
}

// keyqueue_put
// bool k2hdkc_pm_keyq_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pkey, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_key_queue_put)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* prefix = NULL;
	size_t prefix_len = 0;
	char* key = NULL;
	size_t key_len = 0;
	char* val = NULL;
	size_t val_len = 0;
	zend_bool is_fifo = true;
	zend_bool is_attr_checked = true;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(4, 8)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(prefix, prefix_len)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_STRING(val, val_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_fifo)
		Z_PARAM_BOOL(is_attr_checked)
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_keyq_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pkey, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_keyq_str_push_wa(*k2hdkc_chmpx_handle_ptr, prefix, key, val, is_fifo, is_attr_checked, password, ptmexpire);
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkc_pm_keyq_str_push_wa should return true but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}


// remove
// bool k2hdkc_pm_remove_str(k2hdkc_chmpx_h handle, const char* pkey)
PHP_FUNCTION(k2hdkcpx_remove)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	//// bool k2hdkc_pm_remove_str(k2hdkc_chmpx_h handle, const char* pkey)
	if (!k2hdkc_pm_remove_str(*k2hdkc_chmpx_handle_ptr, key)) {
		php_error(E_NOTICE, "k2hdkc_pm_remove_str should return true but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// remove_subkeys
// bool k2hdkc_pm_remove_str_subkey(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, size_t subkeylength, bool is_nest)
PHP_FUNCTION(k2hdkcpx_remove_subkeys)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	zval* subkeys = NULL;
	zend_bool is_nested = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_ARRAY(subkeys)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_nested)
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	//// bool k2hdkc_pm_remove_str_subkey(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, size_t subkeylength, bool is_nest)
	if (subkeys && Z_TYPE_P(subkeys) == IS_ARRAY) {
		zend_ulong zulong_idx= 0;
		zend_string* zstring_key = NULL;
		zval* zv_val = NULL;

		ZEND_HASH_FOREACH_KEY_VAL(Z_ARR(*subkeys), zulong_idx, zstring_key, zv_val) {
			char* subkey = Z_STRVAL_P(zv_val);
			bool bResult = k2hdkc_pm_remove_str_subkey(*k2hdkc_chmpx_handle_ptr, key, subkey, is_nested);
			if (!bResult) {
				// return_result after call_some_functions
				php_error(E_NOTICE, "k2hdkc_pm_remove_str_subkey should return true, but false");
				RETURN_FALSE;	// RETVAL_FALSE; return;
			}
		} ZEND_HASH_FOREACH_END();
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// rename
// bool k2hdkc_pm_rename_with_parent_str_wa(k2hdkc_chmpx_h handle, const char* poldkey, const char* pnewkey, const char* pparentkey, bool checkattr, const char* encpass, const time_t* expire)
PHP_FUNCTION(k2hdkcpx_rename)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	char* newKey = NULL;
	size_t newKey_len = 0;
	char* parentKey = NULL;
	size_t parentKey_len = 0;
	zend_bool is_attr_checked = true;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 7)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_STRING(newKey, newKey_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(parentKey, parentKey_len)
		Z_PARAM_BOOL(is_attr_checked)
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	//// bool k2hdkc_pm_rename_with_parent_str_wa(k2hdkc_chmpx_h handle, const char* poldkey, const char* pnewkey, const char* pparentkey, bool checkattr, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_rename_with_parent_str_wa(*k2hdkc_chmpx_handle_ptr, key, newKey, NULL, is_attr_checked, password, ptmexpire);
	// return_result after call_some_functions
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_rename_with_parent_str_wa should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

// set_subkeys
// bool k2hdkc_pm_set_subkeys(k2hdkc_chmpx_h handle, const unsigned char* pkey, size_t keylength, const PK2HDKCKEYPCK pskeypck, int skeypckcnt)
PHP_FUNCTION(k2hdkcpx_set_subkeys)
{
	// declare_variables
	zval * zval_k2hdkc_chmpx_handle_ptr = NULL;
	char* key = NULL;
	size_t key_len = 0;
	zval* subkeys = NULL;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_RESOURCE(zval_k2hdkc_chmpx_handle_ptr)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_ARRAY(subkeys)
		Z_PARAM_OPTIONAL
		ZEND_PARSE_PARAMETERS_END();

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "chmpx_handle_resource", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_set_str_subkeys(k2hdkc_chmpx_h handle, const char* pkey, const char** pskeyarray)
	bool bResult = false;
	if (subkeys && Z_TYPE_P(subkeys) == IS_ARRAY) {
		int skeypckcnt = zend_array_count(Z_ARR(*subkeys)); // returns number of elements in array. 
		char** pskeyarray = (char**)calloc(skeypckcnt + 1, sizeof(char*));
		zend_ulong zulong_idx = 0;
		zend_string* zstring_key = NULL;
		zval* zv_val = NULL;

		ZEND_HASH_FOREACH_KEY_VAL(Z_ARR(*subkeys), zulong_idx, zstring_key, zv_val) {
			char* subkey = Z_STRVAL_P(zv_val);
			pskeyarray[zulong_idx] = (char*)malloc(strlen(subkey) + 1);
			memcpy(pskeyarray[zulong_idx], subkey, strlen(subkey));
			pskeyarray[zulong_idx][strlen(subkey)] = '\0';	
		} ZEND_HASH_FOREACH_END();

		bResult = k2hdkc_pm_set_str_subkeys(*k2hdkc_chmpx_handle_ptr, key, (const char**)pskeyarray);
		if (pskeyarray) {
			char** ptmp = NULL;
			for (ptmp = pskeyarray; *ptmp; ptmp++) {
				free(*ptmp);
			}
		}
	}
	// return_result after call_some_functions
	if (bResult) {
		RETURN_TRUE;	// RETVAL_TRUE; return;
	}
	RETURN_FALSE;
}

// void k2hdkc_bump_debug_level(void)
PHP_FUNCTION(k2hdkcpx_bump_debug_level)
{
	k2hdkc_bump_debug_level();
}

// void k2hdkc_set_debug_level_silent(void)
PHP_FUNCTION(k2hdkcpx_set_debug_level_silent)
{
	k2hdkc_set_debug_level_silent();
}

// void k2hdkc_set_debug_level_error(void)
PHP_FUNCTION(k2hdkcpx_set_debug_level_error)
{
	k2hdkc_set_debug_level_error();
}

// void k2hdkc_set_debug_level_warning(void)
PHP_FUNCTION(k2hdkcpx_set_debug_level_warning)
{
	k2hdkc_set_debug_level_warning();
}

// void k2hdkc_set_debug_level_message(void)
PHP_FUNCTION(k2hdkcpx_set_debug_level_message)
{
	k2hdkc_set_debug_level_message();
}

// void k2hdkc_set_debug_level_dump(void)
PHP_FUNCTION(k2hdkcpx_set_debug_level_dump)
{
	k2hdkc_set_debug_level_dump();
}

// bool k2hdkc_set_debug_file(const char* filepath)
PHP_FUNCTION(k2hdkcpx_set_debug_file)
{
	// declare_variables
	char* filepath = NULL;
	size_t filepath_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(filepath, filepath_len)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "k2hdkcpx_set_debug_file: filepath is empty.");
		RETURN_FALSE;
	}
	
	// call_some_functions after get_resources
	bool bResult = k2hdkc_set_debug_file(filepath);
	
	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkcpxpx_set_debug_file: failed to set debugging file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

// bool k2hdkc_unset_debug_file(void)
PHP_FUNCTION(k2hdkcpx_unset_debug_file)
{
	if(!k2hdkc_unset_debug_file()){
		php_error(E_NOTICE, "k2hdkcpxpx_unset_debug_file: failed to unset debugging file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

// bool k2hdkc_load_debug_env(void)
PHP_FUNCTION(k2hdkcpx_load_debug_env)
{
	if(!k2hdkc_load_debug_env()){
		php_error(E_NOTICE, "k2hdkcpxpx_load_debug_env: failed to load environment about debugging.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

// bool k2hdkc_is_enable_comlog(void)
PHP_FUNCTION(k2hdkcpx_is_enable_comlog)
{
	if(!k2hdkc_is_enable_comlog()){
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

// void k2hdkc_enable_comlog(void)
PHP_FUNCTION(k2hdkcpx_enable_comlog)
{
	k2hdkc_enable_comlog();
	RETURN_TRUE;
}

// void k2hdkc_disable_comlog(void)
PHP_FUNCTION(k2hdkcpx_disable_comlog)
{
	k2hdkc_disable_comlog();
	RETURN_TRUE;
}

// void k2hdkc_toggle_comlog(void)
PHP_FUNCTION(k2hdkcpx_toggle_comlog)
{
	k2hdkc_toggle_comlog();
	RETURN_TRUE;
}

//
// PHP_FUNCTION ENTRIES END
//


//
// PHP MODULE MACROS START
//
// cppcheck-suppress unknownMacro
ZEND_DECLARE_MODULE_GLOBALS(k2hdkcpx);


PHP_INI_BEGIN()
STD_PHP_INI_ENTRY(
				  "k2hdkcpx.debug", /* configuration directive name */
				  "silent",         /* default value */
				  PHP_INI_ALL,      /* can be  modified at any time */
				  OnUpdateString,   /* callback function to set the string value of the directive */
				  k2hdkcpx_debug,   /* module global variable name */
				  zend_k2hdkcpx_globals, /* structure name to keep module global variables */
				  k2hdkcpx_globals  /* global variable to keep module global variables for a non-thread-safe build */
				  )
PHP_INI_END()


PHP_MINIT_FUNCTION(k2hdkcpx)
{
	// register destructors
	// zend_register_list_destructors_ex must be called inside a PHP_MINIT function
	//
	//// k2hdkcpx_handle
	k2hdkcpx_handle_resource_number = zend_register_list_destructors_ex(k2hdkcpx_handle_resource_dtor, NULL, "k2hdkcpx_handle", module_number);

	// register class entries
	//// k2hdkcpx
	k2hdkcpx_class_entry = register_class_K2hdkc();	// referred by arginfo.h

#if defined(ZTS) && defined(COMPILE_DL_K2HDKCPX)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	// CONST_CS case sensitive
	// CONST_PERSISTENT persistent
	REGISTER_LONG_CONSTANT("K2HDKC_INVALID_HANDLE", K2HDKC_INVALID_HANDLE, CONST_CS | CONST_PERSISTENT);

	// INI
	REGISTER_INI_ENTRIES();

	return SUCCESS;
}

PHP_MINFO_FUNCTION(k2hdkcpx)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "k2hdkcpx support", "enabled");
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(k2hdkcpx)
{
#if defined(COMPILE_DL_BCMATH) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	k2hdkcpx_globals->k2hdkcpx_debug = "silent";
}

PHP_RINIT_FUNCTION(k2hdkcpx)
{
#if defined(ZTS) && defined(COMPILE_DL_K2HDKCPX)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	char* dbgmode = K2HDKCPX_G(k2hdkcpx_debug);
	if(!dbgmode || 0 == strcmp(dbgmode, "silent")) {
		k2hdkc_set_debug_level_silent();
	} else if(0 == strcmp(dbgmode, "message")) {
		k2hdkc_set_debug_level_message();
	} else if(0 == strcmp(dbgmode, "warning")) {
		k2hdkc_set_debug_level_warning();
	} else if(0 == strcmp(dbgmode, "error")) {
		k2hdkc_set_debug_level_error();
	} else {
		k2hdkc_set_debug_level_silent();
	}

	return SUCCESS;
}


zend_module_entry k2hdkcpx_module_entry = {
	STANDARD_MODULE_HEADER,
	"k2hdkcpx", /* Extension name */
	ext_functions, /* zend_function_entry */
	PHP_MINIT(k2hdkcpx), /* PHP_MINIT - Module initialization */
	NULL, /* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(k2hdkcpx), /* PHP_RINIT - Request initialization */
	NULL, /* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(k2hdkcpx), /* PHP_MINFO - Module info */
	PHP_K2HDKCPX_VERSION, /* Version */
	PHP_MODULE_GLOBALS(k2hdkcpx), /* Module globals */
	PHP_GINIT(k2hdkcpx), /* PHP_GINIT – Globals initialization */
	NULL, /* PHP_GSHUTDOWN – Globals shutdown */
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_K2HDKCPX
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(k2hdkcpx)
#endif

//
// PHP MODULE MACROS END
//

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
