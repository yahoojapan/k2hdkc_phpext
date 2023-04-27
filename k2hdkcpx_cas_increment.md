---
layout: contents
language: en-us
title: k2hdkcpx_cas_increment
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_incrementja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_cas_get.html
prev_string: k2hdkcpx_cas_get
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_init.html
next_string: k2hdkcpx_cas_init
---

# k2hdkcpx_cas_increment
Increments a variable in a cluster by using a CAS operation

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

Increments a value using CAS operation.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success or `false` on failure. 


## See Also
- [K2hdkc::casIncrement](k2hdkc_class_casincrement.html) - Increments a value using CAS operation
