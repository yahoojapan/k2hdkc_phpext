---
layout: contents
language: en-us
title: k2hdkcpx_cas_init
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_initja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_cas_increment.html
prev_string: k2hdkcpx_cas_increment
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_set.html
next_string: k2hdkcpx_cas_set
---

# k2hdkcpx_cas_init
Initializes a value using CAS operation

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_increment(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

Initializes a value using CAS operation.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- val  
Specify the new value of the key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::casInit](k2hdkc_class_casinit.html) - Initializes a value using CAS operation
