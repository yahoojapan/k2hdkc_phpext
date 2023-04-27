---
layout: contents
language: en-us
title: k2hdkcpx_rename
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_renameja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_remove_subkeys.html
prev_string: k2hdkcpx_remove_subkeys
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_subkeys.html
next_string: k2hdkcpx_set_subkeys
---

# k2hdkcpx_rename
Renames a pair of the key/value

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_rename(
    $handle_res,
    string $key,
    string $new_key,
    string $parent_key = null,
    bool $is_check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

Renames a pair of the key/value.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- new_key  
Specify the new key.
- parent_key  
Specify the parent key.
- is_check_attr  
Specify `true` to check the passphrase and expiration of the parent key.
- password  
Specify the password that is associated with the key.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::rename](k2hdkc_class_rename.html) - Renames a key
