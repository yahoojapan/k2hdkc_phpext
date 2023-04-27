---
layout: contents
language: en-us
title: k2hdkcpx_remove_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_remove_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_remove.html
prev_string: k2hdkcpx_remove
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_rename.html
next_string: k2hdkcpx_rename
---

# k2hdkcpx_remove_subkeys
Removes subkeys

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_remove_subkeys(
    $handle_res,
    string $key,
    array $subkeys,
    bool $nested = false): bool {}
```

Removes subkeys.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- subkey  
Specify the subkeys that is associated with the key.
- nested  
Specify `true` if remove subkeys recursively.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::removeSubkeys](k2hdkc_class_removesubkeys.html) - Removes subkeys
