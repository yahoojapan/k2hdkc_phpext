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

PHP_METHOD(K2hdkc, __construct) {
	// declare_variables
	char* filepath = NULL;
	size_t filepath_len = 0;
	char* cuk = NULL;
	size_t cuk_len = 0;
	zend_long port = DEFAULT_PORT;
	zend_bool is_rejoin = true;
	zend_bool is_auto_rejoin = false;
	zend_bool is_clear_backup = false;

	// assign_after_declare
	// cppcheck-suppress unknownMacro
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STRING(filepath, filepath_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(port)
		Z_PARAM_STRING(cuk, cuk_len)
		Z_PARAM_BOOL(is_rejoin)
		Z_PARAM_BOOL(is_auto_rejoin)
		Z_PARAM_BOOL(is_clear_backup)
		ZEND_PARSE_PARAMETERS_END();

	// get_props or update_props
	// k2hdkc_chmpx_handle property
	// Firstly, create a k2hdkc_chmpx_handle
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = emalloc(sizeof(long));
	if (k2hdkc_chmpx_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		return;
	}
	*k2hdkc_chmpx_handle_ptr = k2hdkc_open_chmpx_full(filepath, port, cuk, is_rejoin, is_auto_rejoin, is_auto_rejoin);
	if (*k2hdkc_chmpx_handle_ptr == K2HDKC_INVALID_HANDLE) {
		php_error(E_ERROR, "k2hdkc_open_chmpx_full error");
		return;
	}

	// Secondarily, create a zend_resource with the k2hdkc handle
	zend_resource* my_k2hdkc_chmpx_handle_ptr = zend_register_resource(k2hdkc_chmpx_handle_ptr, k2hdkcpx_handle_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_new_k2hdkc_chmpx_handle;
	ZVAL_RES(&zval_new_k2hdkc_chmpx_handle, my_k2hdkc_chmpx_handle_ptr);
	// Finally, set the zend_resource with this object
	k2hdkcpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle", strlen("_handle"), &zval_new_k2hdkc_chmpx_handle);
}

PHP_METHOD(K2hdkc, __destruct) {
	// declare_variables
	// NOTICE: destruct accept no parameters

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_NONE();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);

	// call_some_functions after get_resources
	if (K2HDKC_INVALID_HANDLE != *k2hdkc_chmpx_handle_ptr) {
		// destroy handle
		bool bResult = k2hdkc_close_chmpx_ex(*k2hdkc_chmpx_handle_ptr, true);
		if (!bResult) {
			php_error(E_NOTICE, "k2hdkc_close_chmpx_ex should return true, but returned false");
		}
	}
	zval_dtor(zval_k2hdkc_chmpx_handle_ptr);

	// return_result after call_some_functions
	// NOTICE: destruct shoud return nothing
}

PHP_METHOD(K2hdkc, setValue) {
	// declare_variables
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
	ZEND_PARSE_PARAMETERS_START(2, 6)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_STRING(val, val_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(clear_subkeys)
		Z_PARAM_ARRAY(subkeys)
		Z_PARAM_STRING(password, password_len)
		Z_PARAM_LONG(expire)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	time_t* ptmexpire = NULL;
	if (expire > 0) {
		ptmexpire = (time_t*)&expire;
	}

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
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
		bResult = k2hdkc_pm_set_str_all_wa(*k2hdkc_chmpx_handle_ptr, key, val, (const char**)subkeys, password, ptmexpire);
	}
	// return_result after call_some_functions
	if (bResult) {
		RETURN_TRUE;	// RETVAL_TRUE; return;
	}
	RETURN_FALSE;
}

PHP_METHOD(K2hdkc, getValue) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// call_some_functions after get_resources
	// k2hdkc_pm_get_str_value_wp(session.getHandle(), this.key, this.pass, ppval);
	char* pval;
	if (!k2hdkc_pm_get_str_value_wp(*k2hdkc_chmpx_handle_ptr, key, password, &pval)) {
		// return_result after call_some_functions
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}
	zend_string* retval = strpprintf(0, "%s", pval);
	RETURN_STR(retval);
	// come here ???
	free(pval);
}

PHP_METHOD(K2hdkc, addSubkey) {
	// declare_variables
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
	ZEND_PARSE_PARAMETERS_START(3, 6)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, casGet) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool bResult = k2hdkc_pm_cas64_str_get_wa(*k2hdkc_chmpx_handle_ptr, key, NULL, (uint64_t*)&pval);
	int pval = 0;
	bool bResult = k2hdkc_pm_cas64_str_get_wa(*k2hdkc_chmpx_handle_ptr, key, password, (uint64_t*)&pval);
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkc_pm_cas64_str_get_wa false");
		RETURN_FALSE;
	}
	if (!pval) {
		// return_result after call_some_functions
		RETURN_LONG(0);	// RETVAL_LONG(l); return
	}
	RETURN_LONG(pval);
}

PHP_METHOD(K2hdkc, casDecrement) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, casIncrement) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, casInit) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	zend_long val = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, casSet) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	zend_long old_val = 0;
	zend_long new_val = 0;
	char* password = NULL;
	size_t password_len = 0;
	zend_long expire = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 5)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, clearSubkeys) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(key, key_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_clear_str_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
	bool bResult = k2hdkc_pm_clear_str_subkeys(*k2hdkc_chmpx_handle_ptr, key);
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_clear_str_subkeys should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

PHP_METHOD(K2hdkc, close) {
	// declare_variables

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_NONE();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	if (K2HDKC_INVALID_HANDLE != *k2hdkc_chmpx_handle_ptr) {
		bool bResult = k2hdkc_close_chmpx_ex(*k2hdkc_chmpx_handle_ptr, true);
		if (!bResult) {
			php_error(E_NOTICE, "k2hdkc_close_chmpx_ex should return true but false");
			RETURN_FALSE;	// RETVAL_FALSE; return;
		}
		*k2hdkc_chmpx_handle_ptr = K2HDKC_INVALID_HANDLE;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

PHP_METHOD(K2hdkc, getAttrs) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(key, key_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// call_some_functions after get_resources
	// PK2HDKCATTRPCK k2hdkc_pm_get_str_direct_attrs(k2hdkc_chmpx_h handle, const char* pkey, int* pattrspckcnt)
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

PHP_METHOD(K2hdkc, getSubkeys) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// call_some_functions after get_resources
	// char** k2hdkc_pm_get_str_direct_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
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

PHP_METHOD(K2hdkc, queueGet) {
	// declare_variables
	char* prefix = NULL;
	size_t prefix_len = 0;
	zend_bool is_fifo = true;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STRING(prefix, prefix_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_fifo)
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_q_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppval)
	const char* pval = NULL;
	bool bResult = k2hdkc_pm_q_str_pop_wp(*k2hdkc_chmpx_handle_ptr, prefix, is_fifo, password, &pval);
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkc_pm_q_str_pop_wp should return true, but false");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}
	zend_string* retval = strpprintf(0, "%s", pval);
	RETURN_STR(retval);
}

PHP_METHOD(K2hdkc, queuePut) {
	// declare_variables
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
	ZEND_PARSE_PARAMETERS_START(2, 6)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, keyQueueGet) {
	// declare_variables
	char* prefix = NULL;
	size_t prefix_len = 0;
	zend_bool is_fifo = true;
	char* password = NULL;
	size_t password_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STRING(prefix, prefix_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_fifo)
		Z_PARAM_STRING(password, password_len)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_keyq_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppkey, const char** ppval)
	const char* pkey = NULL;
	const char* pval = NULL;
	bool bResult = k2hdkc_pm_keyq_str_pop_wp(*k2hdkc_chmpx_handle_ptr, prefix, is_fifo, password, &pkey, &pval);
	if (!bResult) {
		php_error(E_NOTICE, "k2hdkc_pm_keyq_str_pop_wp false");
		RETURN_FALSE;
	}
	array_init(return_value);	// zval* return_value
	if (pkey && pval) {
		add_assoc_string(return_value, pkey, pval);
	}
}

PHP_METHOD(K2hdkc, keyQueuePut) {
	// declare_variables
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
	ZEND_PARSE_PARAMETERS_START(3, 7)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

PHP_METHOD(K2hdkc, remove) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_OPTIONAL
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_EMPTY_STRING();	// RETVAL_EMPTY_STRING(); return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr;
	k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_remove_str(k2hdkc_chmpx_h handle, const char* pkey)
	if (!k2hdkc_pm_remove_str(*k2hdkc_chmpx_handle_ptr, key)) {
		php_error(E_NOTICE, "k2hdkc_pm_remove_str should return true but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

PHP_METHOD(K2hdkc, removeSubkeys) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	zval* subkeys = NULL;
	zend_bool is_nested = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_ARRAY(subkeys)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_nested)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_remove_str_subkey(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, size_t subkeylength, bool is_nest)
	if (subkeys && Z_TYPE_P(subkeys) == IS_ARRAY) {
		zend_ulong zulong_idx = 0;
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
	RETURN_TRUE;
}

PHP_METHOD(K2hdkc, rename) {
	// declare_variables
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
	ZEND_PARSE_PARAMETERS_START(2, 6)
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

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
	if (K2HDKC_INVALID_HANDLE == *k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// call_some_functions after get_resources
	// bool k2hdkc_pm_rename_with_parent_str_wa(k2hdkc_chmpx_h handle, const char* poldkey, const char* pnewkey, const char* pparentkey, bool checkattr, const char* encpass, const time_t* expire)
	bool bResult = k2hdkc_pm_rename_with_parent_str_wa(*k2hdkc_chmpx_handle_ptr, key, newKey, NULL, is_attr_checked, password, ptmexpire);
	// return_result after call_some_functions
	if (!bResult) {
		// return_result after call_some_functions
		php_error(E_NOTICE, "k2hdkc_pm_rename_with_parent_str_wa should return true, but false");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}
	RETURN_TRUE;	// RETVAL_TRUE; return;
}

PHP_METHOD(K2hdkc, setSubkeys) {
	// declare_variables
	char* key = NULL;
	size_t key_len = 0;
	zval* subkeys = NULL;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(key, key_len)
		Z_PARAM_ARRAY(subkeys)
		Z_PARAM_OPTIONAL
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	zval* zval_k2hdkc_chmpx_handle_ptr = k2hdkcpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "_handle");
	if (!zval_k2hdkc_chmpx_handle_ptr) {
		php_error(E_NOTICE, "_handle property is invalid");
		RETURN_FALSE;	// RETVAL_FALSE; return;
	}

	// get_resources after get_props
	k2hdkc_chmpx_h* k2hdkc_chmpx_handle_ptr = (k2hdkc_chmpx_h *)zend_fetch_resource(Z_RES_P(zval_k2hdkc_chmpx_handle_ptr), "_handle", k2hdkcpx_handle_resource_number);
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

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
