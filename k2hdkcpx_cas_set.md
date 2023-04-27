---
layout: contents
language: en-us
title: k2hdkcpx_cas_set
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_setja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_cas_init.html
prev_string: k2hdkcpx_cas_init
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_clear_subkeys.html
next_string: k2hdkcpx_clear_subkeys
---

# k2hdkcpx_cas_set
Sets a value using CAS operation

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_set(
    $handle_res,
    string $key,
    int $old_val,
    int $new_val,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

Sets a value using CAS operation.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- old_val  
Specify the old value of the key.
- new_val  
Specify the new value of the key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success, otherwise `false`. 


## See Also
- [K2hdkc::casSet](k2hdkc_class_casset.html) - Sets a value using CAS operation
