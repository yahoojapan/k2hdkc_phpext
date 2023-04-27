---
layout: contents
language: en-us
title: K2hdkc::close
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_closeja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_clearsubkeys.html
prev_string: K2hdkc::clearSubkeys
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_getattrs.html
next_string: K2hdkc::getAttrs
---

# K2hdkc::close
Closes a connection with the K2hdkc cluster

## Description

```
    public function close(): bool {}
```

Closes a connection with the K2hdkc cluster.

## Parameters
This function has no parameters.

## Return Values
Returns `true` on success or `false` on failure. 

## Examples
- Example 1 - Closes a connection with the K2hdkc cluster

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
var_dump($handle->close());
'
```

The above example will output:

```
bool(true)
```


## See Also
- [K2hdkc::__construct](k2hdkc_class_construct.html) - Constructs a [K2hdkc](k2hdkc_class.html) instance
