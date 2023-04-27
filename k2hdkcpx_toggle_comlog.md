---
layout: contents
language: en-us
title: k2hdkcpx_toggle_comlog
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_toggle_comlogja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_set_debug_level_warning.html
prev_string: k2hdkcpx_set_debug_level_warning
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_unset_debug_file.html
next_string: k2hdkcpx_unset_debug_file
---

# k2hdkcpx_toggle_comlog
Toggles the communication log output

## Description

```
function k2hdkcpx_toggle_comlog(): bool {}
```

Toggles the communication log output.

## Parameters
This function has no parameters.


## Return Values
Returns `true` on success, `false` otherwise.


## Examples

```
php -r 'var_dump(k2hdkcpx_toggle_comlog());' 
```

The above example will output:

```
bool(true)
```


## See Also
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_file.html) - Writes logs to stderr
- [k2hdkcpx_disable_comlog](k2hdkcpx_disable_comlog.html) - Disables the communication log output
- [k2hdkcpx_enable_comlog](k2hdkcpx_enable_comlog.html) - Enables the communication log output
- [k2hdkcpx_is_enable_comlog](k2hdkcpx_is_enable_comlog.html) - Check the enable/disable of the communication log output
- [k2hdkcpx_toggle_comlog](k2hdkcpx_toggle_comlog.html) - Toggles the communication log output
