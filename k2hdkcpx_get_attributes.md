---
layout: contents
language: en-us
title: k2hdkcpx_get_attributes
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_get_attributesja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_close.html
prev_string: k2hdkcpx_close
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_get_subkeys.html
next_string: k2hdkcpx_get_subkeys
---

# k2hdkcpx_get_attributes
Gets attribute information of the key

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_attributes(
    $handle_res,
    string $key): array|null {}
```

Gets attribute information of the key.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key to get attribute information

## Return Values
Returns arrays on success or `null` on failure. 

## See Also
- [K2hdkc::getAttrs](k2hdkc_class_getattrs.html) - Gets attribute information of the key
