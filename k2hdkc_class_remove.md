---
layout: contents
language: en-us
title: K2hdkc::remove
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_removeja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_keyqueueput.html
prev_string: K2hdkc::keyQueuePut
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_removesubkeys.html
next_string: K2hdkc::removesubkeys
---

# K2hdkc::remove
Removes a pair of the key/value

## Description

```
    public function remove(
        string $key,
        string $password = null): bool {}
```

Removes a pair of the key/value.

## Parameters
- key  
Specify the key.
- password  
Specify the password that is associated with the key.

## Return Values
Returns `true` on success or `false` on failure. 

## Examples
- Example 1 - Removes a key

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
var_dump($k2hdkc->setValue("key1", "val1"));
var_dump($k2hdkc->getValue("key1"));
var_dump($k2hdkc->remove("key1"));
var_dump($k2hdkc->getValue("key1"));
'
```

The above example will output:

```
bool(true)
string(4) "val1"
bool(true)
string(0) ""
```


## See Also
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Sets a pair of the key/value
- [K2hdkc::getValue](k2hdkc_class_getvalue.html) - Gets a value of the key
