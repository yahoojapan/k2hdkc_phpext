---
layout: contents
language: en-us
title: Environments
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: configurationsja.html
lang_opp_word: To Japanese
prev_url: developer.html
prev_string: Developer
top_url: index.html
top_string: TOP
next_url: 
next_string:
---

# Environments
K2HDKC PHP Extension library does not define its own environment variable.
However, the environment variable defined by [K2HDKC](https://k2hdkc.antpick.ax/) is loaded into K2HDKC PHP Extension library through it.
For information on these environment variables, please see [here](https://k2hdkc.antpick.ax/environments.html).


# Runtime Configuration
The behaviour of the library is affected by settings in php.ini. The configuration directives below are defined by K2HDKC PHP Extension.

## k2hdkcpx.debug
Specify the log levels of the library among the following values. This parameter can be set anywhere.

- **error**  
the level of the importance of the message is the "error" level
- **info**  
the level of the importance of the message is the "info" level
- **warning**  
the level of the importance of the message is the "warning" level
- **silent(default)**  
the level of the importance of the message is the "silent" level which is the default level
 
