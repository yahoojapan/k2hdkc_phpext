---
layout: contents
language: en-us
title: k2hdkcpx_get_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_get_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_close.html
prev_string: k2hdkcpx_get_attributes
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_get_value.html
next_string: k2hdkcpx_get_value
---

# k2hdkcpx_get_subkeys
Gets all subkeys of a key

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_subkeys(
    $handle_res,
    string $key): array|null {}
```

Gets all subkeys of the key.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.


## Return Values
Returns array on success or `null` on failure. 

## See Also
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeys.html) - Gets all subkeys of the key
