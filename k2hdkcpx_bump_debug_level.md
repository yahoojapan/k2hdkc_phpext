---
layout: contents
language: en-us
title: k2hdkcpx_bump_debug_level
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_bump_debug_levelja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_set_value.html
prev_string: k2hdkcpx_set_value
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_disable_comlog.html
next_string: k2hdkcpx_disable_comlog
---

# k2hdkcpx_bump_debug_level
Changes the log level

## Description

```
function k2hdkcpx_bump_debug_level(): void {}
```

Changes the log level by each call. The order is 'error' , 'warning' , 'message' (info), 'dump' (debug), 'silent' (no logging). The log level turns 'error' when calling the function in the 'silent' level. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples

```
php -r 'var_dump(k2hdkcpx_bump_debug_level());'
```

The above example will output:

```
NULL
```


## See Also
- [k2hdkcpx_set_debug_file](k2hdkcpx_set_debug_file.html) - Writes log to the file
- [k2hdkcpx_set_debug_level_error](k2hdkcpx_set_debug_level_error.html) - Sets log level to error
- [k2hdkcpx_set_debug_level_message](k2hdkcpx_set_debug_level_message.html) - Sets log level to info
- [k2hdkcpx_set_debug_level_silent](k2hdkcpx_set_debug_level_silent.html) - Stops logging
- [k2hdkcpx_set_debug_level_warning](k2hdkcpx_set_debug_level_warning.html) - Sets log level to warning
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_file.html) - Writes logs to stderr
