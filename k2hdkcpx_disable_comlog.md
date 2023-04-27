---
layout: contents
language: en-us
title: k2hdkcpx_disable_comlog
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_disable_comlogja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_bump_debug_level.html
prev_string: k2hdkcpx_bump_debug_level
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_enable_comlog.html
next_string: k2hdkcpx_enable_comlog
---

# k2hdkcpx_disable_comlog
Disables the communication log output

## Description

```
function k2hdkcpx_disable_comlog(): bool {}
```

Disables the communication log output.

## Parameters
This function has no parameters.

## Return Values
Returns `true` when it is disabled, `false` otherwise.

## Examples

```
php -r 'var_dump(k2hdkcpx_disable_comlog());'
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
