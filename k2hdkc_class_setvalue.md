---
layout: contents
language: en-us
title: K2hdkc::__set
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_setvalueja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_destruct.html
prev_string: K2hdkc::__destruct
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_getvalue.html
next_string: K2hdkc::getValue
---

# K2hdkc::setValue
Sets a key/value pair

## Description
```
    public function setValue(
        string $key,
        string $val,
        bool $clear_subkeys = false,
        array $subkeys = null,
        string $password = null,
        int $expiration_duration = 0): bool {}
```
Sets a key/value pair.

## Parameters
- key  
Specify the key.
- val  
Specify the value.
- clear_subkeys  
Specify `true` when clearing the subkeys.
- subkeys  
Specify the subkeys.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.

## Return Values
Returns `true` on success or `false` on failure.

## Examples
- Example 1 - Sets a value to the key

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
- [K2hdkc::getValue](k2hdkc_class_getvalue.html) - Gets a value of the key

