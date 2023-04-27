---
layout: contents
language: en-us
title: k2hdkcpx_set_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_rename.html
prev_string: k2hdkcpx_rename
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_value.html
next_string: k2hdkcpx_set_value
---

# k2hdkcpx_set_subkeys
Sets subkeys of a key

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_set_subkeys(
    $handle_res,
    string $key,
    array $subkeys): bool {}
```

Associates the key with the other key. The key that is added to the other key is called 'subkey'. The key that adds the other key to is 'parent key'. A parent key can associates many subkeys. 

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- key  
Specify the key.
- subkey  
Specify the subkeys that is associated with the key.


## Return Values
Returns `true` on success or `false` on failure. 

## See Also
- [K2hdkc::setSubkeys](k2hdkc_class_setsubkeys.html) - Sets subkeys of the key
