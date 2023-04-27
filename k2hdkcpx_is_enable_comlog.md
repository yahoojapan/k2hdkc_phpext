---
layout: contents
language: en-us
title: k2hdkcpx_is_enable_comlog
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_is_enable_comlogja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_enable_comlog.html
prev_string: k2hdkcpx_enable_comlog
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_load_debug_env.html
next_string: k2hdkcpx_load_debug_env
---

# k2hdkcpx_is_enable_comlog
Check the enable/disable of the communication log output

## Description

```
function k2hdkcpx_is_enable_comlog(): bool {}
```

Check the enable/disable of the communication log output.

## Parameters
This function has no parameters.

## Return Values
Returns `true` when it is enabled, `false` otherwise.

## Examples

```
php -r 'var_dump(k2hdkcpx_is_enable_comlog());'
```

The above example will output:

```
bool(false)
```


## See Also
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_file.html) - Writes logs to stderr
- [k2hdkcpx_disable_comlog](k2hdkcpx_disable_comlog.html) - Disables the communication log output
- [k2hdkcpx_enable_comlog](k2hdkcpx_enable_comlog.html) - Enables the communication log output
- [k2hdkcpx_is_enable_comlog](k2hdkcpx_is_enable_comlog.html) - Check the enable/disable of the communication log output
- [k2hdkcpx_toggle_comlog](k2hdkcpx_toggle_comlog.html) - Toggles the communication log output
