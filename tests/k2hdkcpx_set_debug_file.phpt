--TEST--
k2hdkcpx_set_debug_file
--CREDITS--
K2HDKC PHP Extension library

Copyright 2023 Yahoo Japan Corporation.

K2HDKC is k2hash based distributed KVS cluster.
K2HDKC uses K2HASH, CHMPX, FULLOCK libraries. K2HDKC supports
distributed KVS cluster server program and client libraries.

For the full copyright and license information, please view
the license file that was distributed with this source code.
--EXTENSIONS--
k2hdkcpx
--FILE--
<?php
if(k2hdkcpx_set_debug_file('/dev/null')){
	echo "OK";
}else{
	echo "NG";
}
?>
--EXPECT--
OK
--DESCRIPTION--
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
