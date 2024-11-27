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

/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 0a22cec1d02ec5be6ad60fc69b129d39cca236fa */

// cppcheck-suppress unknownMacro
ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hdkcpx_open, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, config_file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, port, IS_LONG, 0, "8031")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cuk, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rejoin, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rejoin_forever, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, clear_backup, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_set_value, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, clearSubkeys, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkeys, IS_ARRAY, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expirationDuration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_get_value, 0, 2, IS_STRING, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_add_subkey, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subval, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hdkcpx_cas_get, 0, 2, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_cas_decrement, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_k2hdkcpx_cas_increment arginfo_k2hdkcpx_cas_decrement

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_cas_init, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_cas_set, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, old_val, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, new_val, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_clear_subkeys, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_close, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_clean_bup, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_get_attributes, 0, 2, IS_ARRAY, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hdkcpx_get_subkeys arginfo_k2hdkcpx_get_attributes

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_queue_get, 0, 2, IS_STRING, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_queue_put, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_key_queue_get, 0, 2, IS_ARRAY, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_key_queue_put, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_remove, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_remove_subkeys, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkeys, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, nested, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_rename, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, new_key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parent_key, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_set_subkeys, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkeys, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_bump_debug_level, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hdkcpx_set_debug_level_silent arginfo_k2hdkcpx_bump_debug_level

#define arginfo_k2hdkcpx_set_debug_level_error arginfo_k2hdkcpx_bump_debug_level

#define arginfo_k2hdkcpx_set_debug_level_warning arginfo_k2hdkcpx_bump_debug_level

#define arginfo_k2hdkcpx_set_debug_level_message arginfo_k2hdkcpx_bump_debug_level

#define arginfo_k2hdkcpx_set_debug_level_dump arginfo_k2hdkcpx_bump_debug_level

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_set_debug_file, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hdkcpx_unset_debug_file arginfo_k2hdkcpx_bump_debug_level

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hdkcpx_load_debug_env, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hdkcpx_is_enable_comlog arginfo_k2hdkcpx_load_debug_env

#define arginfo_k2hdkcpx_enable_comlog arginfo_k2hdkcpx_load_debug_env

#define arginfo_k2hdkcpx_disable_comlog arginfo_k2hdkcpx_load_debug_env

#define arginfo_k2hdkcpx_toggle_comlog arginfo_k2hdkcpx_load_debug_env

#define arginfo_class_K2hdkc___construct arginfo_k2hdkcpx_open

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hdkc___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_setValue, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, clear_subkeys, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkeys, IS_ARRAY, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_getValue, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_addSubkey, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subval, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hdkc_casGet, 0, 1, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_casDecrement, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hdkc_casIncrement arginfo_class_K2hdkc_casDecrement

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_casInit, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_casSet, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, old_val, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, new_val, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_clearSubkeys, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_K2hdkc_close arginfo_k2hdkcpx_load_debug_env

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_getAttrs, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_K2hdkc_getSubkeys arginfo_class_K2hdkc_getAttrs

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_queueGet, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_queuePut, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hdkc_keyQueueGet, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_keyQueuePut, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_remove, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_removeSubkeys, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkeys, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, nested, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_rename, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, new_key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parent_key, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_check_attr, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, password, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expiration_duration, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hdkc_setSubkeys, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkeys, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(k2hdkcpx_open);
ZEND_FUNCTION(k2hdkcpx_set_value);
ZEND_FUNCTION(k2hdkcpx_get_value);
ZEND_FUNCTION(k2hdkcpx_add_subkey);
ZEND_FUNCTION(k2hdkcpx_cas_get);
ZEND_FUNCTION(k2hdkcpx_cas_decrement);
ZEND_FUNCTION(k2hdkcpx_cas_increment);
ZEND_FUNCTION(k2hdkcpx_cas_init);
ZEND_FUNCTION(k2hdkcpx_cas_set);
ZEND_FUNCTION(k2hdkcpx_clear_subkeys);
ZEND_FUNCTION(k2hdkcpx_close);
ZEND_FUNCTION(k2hdkcpx_get_attributes);
ZEND_FUNCTION(k2hdkcpx_get_subkeys);
ZEND_FUNCTION(k2hdkcpx_queue_get);
ZEND_FUNCTION(k2hdkcpx_queue_put);
ZEND_FUNCTION(k2hdkcpx_key_queue_get);
ZEND_FUNCTION(k2hdkcpx_key_queue_put);
ZEND_FUNCTION(k2hdkcpx_remove);
ZEND_FUNCTION(k2hdkcpx_remove_subkeys);
ZEND_FUNCTION(k2hdkcpx_rename);
ZEND_FUNCTION(k2hdkcpx_set_subkeys);
ZEND_FUNCTION(k2hdkcpx_bump_debug_level);
ZEND_FUNCTION(k2hdkcpx_set_debug_level_silent);
ZEND_FUNCTION(k2hdkcpx_set_debug_level_error);
ZEND_FUNCTION(k2hdkcpx_set_debug_level_warning);
ZEND_FUNCTION(k2hdkcpx_set_debug_level_message);
ZEND_FUNCTION(k2hdkcpx_set_debug_level_dump);
ZEND_FUNCTION(k2hdkcpx_set_debug_file);
ZEND_FUNCTION(k2hdkcpx_unset_debug_file);
ZEND_FUNCTION(k2hdkcpx_load_debug_env);
ZEND_FUNCTION(k2hdkcpx_is_enable_comlog);
ZEND_FUNCTION(k2hdkcpx_enable_comlog);
ZEND_FUNCTION(k2hdkcpx_disable_comlog);
ZEND_FUNCTION(k2hdkcpx_toggle_comlog);
ZEND_METHOD(K2hdkc, __construct);
ZEND_METHOD(K2hdkc, __destruct);
ZEND_METHOD(K2hdkc, setValue);
ZEND_METHOD(K2hdkc, getValue);
ZEND_METHOD(K2hdkc, addSubkey);
ZEND_METHOD(K2hdkc, casGet);
ZEND_METHOD(K2hdkc, casDecrement);
ZEND_METHOD(K2hdkc, casIncrement);
ZEND_METHOD(K2hdkc, casInit);
ZEND_METHOD(K2hdkc, casSet);
ZEND_METHOD(K2hdkc, clearSubkeys);
ZEND_METHOD(K2hdkc, close);
ZEND_METHOD(K2hdkc, getAttrs);
ZEND_METHOD(K2hdkc, getSubkeys);
ZEND_METHOD(K2hdkc, queueGet);
ZEND_METHOD(K2hdkc, queuePut);
ZEND_METHOD(K2hdkc, keyQueueGet);
ZEND_METHOD(K2hdkc, keyQueuePut);
ZEND_METHOD(K2hdkc, remove);
ZEND_METHOD(K2hdkc, removeSubkeys);
ZEND_METHOD(K2hdkc, rename);
ZEND_METHOD(K2hdkc, setSubkeys);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(k2hdkcpx_open, arginfo_k2hdkcpx_open)
	ZEND_FE(k2hdkcpx_set_value, arginfo_k2hdkcpx_set_value)
	ZEND_FE(k2hdkcpx_get_value, arginfo_k2hdkcpx_get_value)
	ZEND_FE(k2hdkcpx_add_subkey, arginfo_k2hdkcpx_add_subkey)
	ZEND_FE(k2hdkcpx_cas_get, arginfo_k2hdkcpx_cas_get)
	ZEND_FE(k2hdkcpx_cas_decrement, arginfo_k2hdkcpx_cas_decrement)
	ZEND_FE(k2hdkcpx_cas_increment, arginfo_k2hdkcpx_cas_increment)
	ZEND_FE(k2hdkcpx_cas_init, arginfo_k2hdkcpx_cas_init)
	ZEND_FE(k2hdkcpx_cas_set, arginfo_k2hdkcpx_cas_set)
	ZEND_FE(k2hdkcpx_clear_subkeys, arginfo_k2hdkcpx_clear_subkeys)
	ZEND_FE(k2hdkcpx_close, arginfo_k2hdkcpx_close)
	ZEND_FE(k2hdkcpx_get_attributes, arginfo_k2hdkcpx_get_attributes)
	ZEND_FE(k2hdkcpx_get_subkeys, arginfo_k2hdkcpx_get_subkeys)
	ZEND_FE(k2hdkcpx_queue_get, arginfo_k2hdkcpx_queue_get)
	ZEND_FE(k2hdkcpx_queue_put, arginfo_k2hdkcpx_queue_put)
	ZEND_FE(k2hdkcpx_key_queue_get, arginfo_k2hdkcpx_key_queue_get)
	ZEND_FE(k2hdkcpx_key_queue_put, arginfo_k2hdkcpx_key_queue_put)
	ZEND_FE(k2hdkcpx_remove, arginfo_k2hdkcpx_remove)
	ZEND_FE(k2hdkcpx_remove_subkeys, arginfo_k2hdkcpx_remove_subkeys)
	ZEND_FE(k2hdkcpx_rename, arginfo_k2hdkcpx_rename)
	ZEND_FE(k2hdkcpx_set_subkeys, arginfo_k2hdkcpx_set_subkeys)
	ZEND_FE(k2hdkcpx_bump_debug_level, arginfo_k2hdkcpx_bump_debug_level)
	ZEND_FE(k2hdkcpx_set_debug_level_silent, arginfo_k2hdkcpx_set_debug_level_silent)
	ZEND_FE(k2hdkcpx_set_debug_level_error, arginfo_k2hdkcpx_set_debug_level_error)
	ZEND_FE(k2hdkcpx_set_debug_level_warning, arginfo_k2hdkcpx_set_debug_level_warning)
	ZEND_FE(k2hdkcpx_set_debug_level_message, arginfo_k2hdkcpx_set_debug_level_message)
	ZEND_FE(k2hdkcpx_set_debug_level_dump, arginfo_k2hdkcpx_set_debug_level_dump)
	ZEND_FE(k2hdkcpx_set_debug_file, arginfo_k2hdkcpx_set_debug_file)
	ZEND_FE(k2hdkcpx_unset_debug_file, arginfo_k2hdkcpx_unset_debug_file)
	ZEND_FE(k2hdkcpx_load_debug_env, arginfo_k2hdkcpx_load_debug_env)
	ZEND_FE(k2hdkcpx_is_enable_comlog, arginfo_k2hdkcpx_is_enable_comlog)
	ZEND_FE(k2hdkcpx_enable_comlog, arginfo_k2hdkcpx_enable_comlog)
	ZEND_FE(k2hdkcpx_disable_comlog, arginfo_k2hdkcpx_disable_comlog)
	ZEND_FE(k2hdkcpx_toggle_comlog, arginfo_k2hdkcpx_toggle_comlog)
	ZEND_FE_END
};

static const zend_function_entry class_K2hdkc_methods[] = {
	ZEND_ME(K2hdkc, __construct, arginfo_class_K2hdkc___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, __destruct, arginfo_class_K2hdkc___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, setValue, arginfo_class_K2hdkc_setValue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, getValue, arginfo_class_K2hdkc_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, addSubkey, arginfo_class_K2hdkc_addSubkey, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, casGet, arginfo_class_K2hdkc_casGet, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, casDecrement, arginfo_class_K2hdkc_casDecrement, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, casIncrement, arginfo_class_K2hdkc_casIncrement, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, casInit, arginfo_class_K2hdkc_casInit, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, casSet, arginfo_class_K2hdkc_casSet, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, clearSubkeys, arginfo_class_K2hdkc_clearSubkeys, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, close, arginfo_class_K2hdkc_close, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, getAttrs, arginfo_class_K2hdkc_getAttrs, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, getSubkeys, arginfo_class_K2hdkc_getSubkeys, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, queueGet, arginfo_class_K2hdkc_queueGet, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, queuePut, arginfo_class_K2hdkc_queuePut, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, keyQueueGet, arginfo_class_K2hdkc_keyQueueGet, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, keyQueuePut, arginfo_class_K2hdkc_keyQueuePut, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, remove, arginfo_class_K2hdkc_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, removeSubkeys, arginfo_class_K2hdkc_removeSubkeys, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, rename, arginfo_class_K2hdkc_rename, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hdkc, setSubkeys, arginfo_class_K2hdkc_setSubkeys, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_K2hdkc(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "K2hdkc", class_K2hdkc_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property__config_file_default_value;
	ZVAL_UNDEF(&property__config_file_default_value);
	zend_string *property__config_file_name = zend_string_init("_config_file", sizeof("_config_file") - 1, 1);
	zend_declare_typed_property(class_entry, property__config_file_name, &property__config_file_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property__config_file_name);

	zval property__port_default_value;
	ZVAL_UNDEF(&property__port_default_value);
	zend_string *property__port_name = zend_string_init("_port", sizeof("_port") - 1, 1);
	zend_declare_typed_property(class_entry, property__port_name, &property__port_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property__port_name);

	zval property__cuk_default_value;
	ZVAL_UNDEF(&property__cuk_default_value);
	zend_string *property__cuk_name = zend_string_init("_cuk", sizeof("_cuk") - 1, 1);
	zend_declare_typed_property(class_entry, property__cuk_name, &property__cuk_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property__cuk_name);

	zval property__rejoin_default_value;
	ZVAL_UNDEF(&property__rejoin_default_value);
	zend_string *property__rejoin_name = zend_string_init("_rejoin", sizeof("_rejoin") - 1, 1);
	zend_declare_typed_property(class_entry, property__rejoin_name, &property__rejoin_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property__rejoin_name);

	zval property__rejoin_forever_default_value;
	ZVAL_UNDEF(&property__rejoin_forever_default_value);
	zend_string *property__rejoin_forever_name = zend_string_init("_rejoin_forever", sizeof("_rejoin_forever") - 1, 1);
	zend_declare_typed_property(class_entry, property__rejoin_forever_name, &property__rejoin_forever_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property__rejoin_forever_name);

	zval property__clear_backup_default_value;
	ZVAL_UNDEF(&property__clear_backup_default_value);
	zend_string *property__clear_backup_name = zend_string_init("_clear_backup", sizeof("_clear_backup") - 1, 1);
	zend_declare_typed_property(class_entry, property__clear_backup_name, &property__clear_backup_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property__clear_backup_name);

	zval property__handle_default_value;
	ZVAL_NULL(&property__handle_default_value);
	zend_string *property__handle_name = zend_string_init("_handle", sizeof("_handle") - 1, 1);
	zend_declare_property_ex(class_entry, property__handle_name, &property__handle_default_value, ZEND_ACC_PRIVATE, NULL);
	zend_string_release(property__handle_name);

	return class_entry;
}
