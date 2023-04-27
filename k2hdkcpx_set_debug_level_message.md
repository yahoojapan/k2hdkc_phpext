---
layout: contents
language: en-us
title: k2hdkcpx_set_debug_level_message
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_debug_level_messageja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_set_debug_level_error.html
prev_string: k2hdkcpx_set_debug_level_error
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_debug_level_silent.html
next_string: k2hdkcpx_set_debug_level_silent
---

# k2hdkcpx_set_debug_level_message
Sets a message output level to message

## Description

```
function k2hdkcpx_set_debug_level_message(): void {}
```

Sets a message output level to message.

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples

```
php -r 'var_dump(k2hdkcpx_set_debug_level_message());'
```

The above example will output:

```
NULL
```


## See Also
- [k2hdkcpx_bump_debug_level](k2hdkcpx_bump_debug_level.html) - Changes the log level
- [k2hdkcpx_load_debug_env](k2hdkcpx_load_debug_env.html) - Sets a message output and output destination according to the value
- [k2hdkcpx_set_debug_file](k2hdkcpx_set_debug_file.html) - Specify the file to output message
- [k2hdkcpx_set_debug_level_dump](k2hdkcpx_set_debug_level_dump.html) - Sets log level to dump
- [k2hdkcpx_set_debug_level_error](k2hdkcpx_set_debug_level_error.html) - Sets log level to error
- [k2hdkcpx_set_debug_level_message](k2hdkcpx_set_debug_level_message.html) - Sets log level to info
- [k2hdkcpx_set_debug_level_silent](k2hdkcpx_set_debug_level_silent.html) - Stops logging
- [k2hdkcpx_set_debug_level_warning](k2hdkcpx_set_debug_level_warning.html) - Sets log level to warning
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_file.html) - Writes logs to stderr
