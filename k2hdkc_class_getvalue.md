---
layout: contents
language: en-us
title: K2hdkc::getValue
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_setvalueja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_setvalue.html
prev_string: K2hdkc::setValue
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_addsubkey.html
next_string: K2hdkc::addSubkey
---

# K2hdkc::getValue
Gets a value associated with the key

## Description
```
    public function getValue(
        string $key,
        string $password = null): string|null {}
```
Gets a value associated with the key.

## Parameters
- key  
Specify the key.
- password  
Specify the passphrase for encrypting the value.

## Return Values
Returns the value of the key, otherwise null.

## Examples
- Example 1 - Gets a value associated with the key

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
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Set the value associated with the key
