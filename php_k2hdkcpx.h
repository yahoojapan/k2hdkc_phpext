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

#ifndef PHP_K2HDKCPX_H
# define PHP_K2HDKCPX_H

#include "k2hdkc.h"
#include "config.h"

# define DEFAULT_PORT 8031

// cppcheck-suppress unknownMacro
ZEND_BEGIN_MODULE_GLOBALS(k2hdkcpx);
char* k2hdkcpx_debug;
// cppcheck-suppress unknownMacro
ZEND_END_MODULE_GLOBALS(k2hdkcpx);

ZEND_EXTERN_MODULE_GLOBALS(k2hdkcpx);

#define K2HDKCPX_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(k2hdkcpx, v);

extern zend_module_entry k2hdkcpx_module_entry;
# define phpext_k2hdkcpx_ptr &k2hdkcpx_module_entry

extern int k2hdkcpx_handle_resource_number;

zval* k2hdkcpx_read_property_resource(zend_class_entry* scope, zval* object, const char* name);
void k2hdkcpx_update_property_resource(zend_class_entry* scope, zval* object, const char* name, size_t name_length, zval* value);

// # define PHP_K2HDKCPX_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_K2HDKCPX)
// cppcheck-suppress unknownMacro
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_K2HDKCPX_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
