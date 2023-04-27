---
layout: contents
language: en-us
title: k2hdkcpx_close
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_closeja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_clear_subkeys.html
prev_string: k2hdkcpx_clear_subkeys
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_get_attributes.html
next_string: k2hdkcpx_get_attributes
---

# k2hdkcpx_close
Closes a connection with the K2hdkc cluster

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_close(
    $handle_res,
    bool $is_clean_bup = true): bool {}
```

Closes a connection with the K2hdkc cluster.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- is_clean_bup  
Specify `true` when removing the temporary files


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::close](k2hdkc_class_close.html) - Closes a connection with the K2hdkc cluste
