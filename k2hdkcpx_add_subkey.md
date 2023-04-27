---
layout: contents
language: en-us
title: k2hdkcpx_add_subkey
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_add_subkeyja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_decrement.html
next_string: k2hdkcpx_cas_decrement
---

# k2hdkcpx_add_subkey
Adds a new subkey to a key

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_add_subkey(
    $handle_res,
    string $key,
    string $subkey,
    string $subval,
    bool $check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

Associates the key with the other key. The key that is added to the other key is called 'subkey'. The key that adds the other key to is 'parent key'. A parent key can associates many subkeys. 

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- subkey  
Specify the subkey that is associated with the key.
- subval  
Specify the subval that is associated with the subkey.
- check_attr  
Specify `true` to check the passphrase and expiration of the parent key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::addSubkey](k2hdkc_class_addsubkey.html) - Associates the key with the other key
