---
layout: contents
language: en-us
title: k2hdkcpx_cas_decrement
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_decrementja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_add_subkey.html
prev_string: k2hdkcpx_add_subkey
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_get.html
next_string: k2hdkcpx_cas_get
---

# k2hdkcpx_cas_decrement
Decrements a value using CAS operation

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_decrement(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

Decrements a value using CAS operation.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key to decrement.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::casDecrement](k2hdkc_class_casdecrement.html) - Decrements a value using CAS operation

