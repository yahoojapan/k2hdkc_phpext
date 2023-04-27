---
layout: contents
language: en-us
title: k2hdkcpx_set_value
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_valueja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_set_subkeys.html
prev_string: k2hdkcpx_set_subkeys
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_bump_debug_level.html
next_string: k2hdkcpx_bump_debug_level
---

# k2hdkcpx_set_value
Sets a key/value pair

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_set_value(
	$handle_res,
	string $key,
	string $val,
	bool $clearSubkeys = false,
	array $subkeys = null,
	string $password = null,
	int $expirationDuration = 0): bool {}
```

Sets a key/value pair.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- val  
Specify the value.
- clear_subkeys  
Specify `true` when clearing the subkeys.
- subkeys  
Specify the subkeys.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Sets a pair of the key/value
