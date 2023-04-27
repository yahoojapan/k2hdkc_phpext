---
layout: contents
language: en-us
title: k2hdkcpx_get_value
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_get_valueja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_get_subkeys.html
prev_string: k2hdkcpx_get_subkeys
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_key_queue_get.html
next_string: k2hdkcpx_key_queue_get
---

# k2hdkcpx_get_value
Gets a value associated with the key

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_value(
	$handle_res,
	string $key,
	string $password = null): string|null {}
```

Gets a value associated with the key.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- password  
Specify the passphrase for encrypting the value.


## Return Values
Returns the value of the key, otherwise null.


## See Also
- [K2hdkc::getValue](k2hdkc_class_getvalue.html) - Gets a value of the key
