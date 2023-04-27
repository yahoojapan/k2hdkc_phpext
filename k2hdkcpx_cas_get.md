---
layout: contents
language: en-us
title: k2hdkcpx_cas_get
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_getja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_cas_decrement.html
prev_string: k2hdkcpx_cas_decrement
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_increment.html
next_string: k2hdkcpx_cas_increment
---

# k2hdkcpx_cas_get
Gets a variable from a cluster using a CAS operation

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_get(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): int {}
```

Gets a variable from a cluster using a CAS operation.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- subval  
Specify the value.
- check_attr  
Specify `true` when encryption 


## Return Values
Returns the value on success, otherwise 0(false).

## See Also
- [K2hdkc::casGet](k2hdkc_class_casget.html) - Gets a value using CAS operation
