---
layout: contents
language: en-us
title: k2hdkcpx_set_debug_file
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_debug_fileja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_load_debug_env.html
prev_string: k2hdkcpx_load_debug_env
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_debug_level_dump.html
next_string: k2hdkcpx_set_debug_level_dump
---

# k2hdkcpx_set_debug_file
Specify the file to output message

## Description

```
function k2hdkcpx_set_debug_file(string $filepath): bool {}
```

Specify the file to output message.

## Parameters
This function has no parameters.

## Return Values
Returns `true` on success, `false` otherwise.


## Examples

```
php -r 'var_dump(k2hdkcpx_set_debug_file("/dev/null"));'
```

The above example will output:

```
bool(true)
```


## See Also
- [k2hdkcpx_bump_debug_level](k2hdkcpx_bump_debug_level.html) - Changes the log level
- [k2hdkcpx_load_debug_env](k2hdkcpx_load_debug_env.html) - Sets a message output and output destination according to the value
- [k2hdkcpx_set_debug_file](k2hdkcpx_set_debug_file.html) - Specify the file to output message
- [k2hdkcpx_set_debug_level_dump](k2hdkcpx_set_debug_level_dump.html) - Sets a message output level to dump
- [k2hdkcpx_set_debug_level_error](k2hdkcpx_set_debug_level_error.html) - Sets a message output level to error
- [k2hdkcpx_set_debug_level_message](k2hdkcpx_set_debug_level_message.html) - Sets a message output level to message
- [k2hdkcpx_set_debug_level_silent](k2hdkcpx_set_debug_level_silent.html) - Sets a message output level to silent
- [k2hdkcpx_set_debug_level_warning](k2hdkcpx_set_debug_level_warning.html) - Sets a message output level to warning
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_file.html) - Sets output messages to stderr
