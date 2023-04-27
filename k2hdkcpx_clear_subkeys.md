---
layout: contents
language: en-us
title: k2hdkcpx_clear_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_clear_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_cas_set.html
prev_string: k2hdkcpx_cas_set
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_close.html
next_string: k2hdkcpx_close
---

# K2hdkc::clearSubkey
Removes all subkeys of the key

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_clear_subkeys(
    $handle_res,
    string $key): bool {}
```

Removes all subkeys of the key.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key to remove all subkeys


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeys.html) - Removes all subkeys of the key
