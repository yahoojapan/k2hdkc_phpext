---
layout: contents
language: en-us
title: K2hdkc::__destruct
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_constructja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_construct.html
prev_string: K2hdkc::__construct
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_setvalue.html
next_string: K2hdkc::setValue
---

# K2hdkc::__destruct
Destroys a [K2hdkc](k2hdkc_class.html) instance

## Description

```
    public function __destruct() {}
```

Destroys a [K2hdkc](k2hdkc_class.html) instance.

## Parameters
This function has no parameters.

## Examples
- Example 1 - Destroys a [K2hdkc](k2hdkc_class.html) instance

```
php -r '
k2hdkc = new K2hdkc("tests/slave.ini");
var_dump($k2hdkc->setValue("key1", "val1"));
var_dump($k2hdkc->getValue("key1"));
unset($k2hdkc);
'
```

The above example will output:

```
bool(true)
string(4) "val1"
```

## See Also
- [K2hdkc::__construct](k2hdkc_class_construct.html) - Constructs a [K2hdkc](k2hdkc_class.html) instance
