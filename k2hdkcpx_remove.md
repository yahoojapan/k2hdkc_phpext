---
layout: contents
language: en-us
title: k2hdkcpx_remove
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_removeja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_queue_put.html
prev_string: k2hdkcpx_queue_put
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_remove_subkeys.html
next_string: k2hdkcpx_remove_subkeys
---

# k2hdkcpx_remove
Removes a pair of the key/value

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_remove(
    $handle_res,
    string $key,
    string $password = null): bool {}
```

Removes a pair of the key/value.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- password  
Specify the password that is associated with the key.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::remove](k2hdkc_class_remove.html) - Removes a pair of the key/value
