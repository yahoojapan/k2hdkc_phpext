---
layout: contents
language: en-us
title: K2hdkc::rename
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_renameja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_keyqueueput.html
prev_string: K2hdkc::keyQueuePut
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_setsubkeys.html
next_string: K2hdkc::setSubkeys
---

# K2hdkc::rename
Renames a pair of the key/value

## Description

```
    public function rename(
        string $key,
        string $new_key,
        string $parent_key = null,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```

Renames a pair of the key/value.

## Parameters
- key  
Specify the key.
- new_key  
Specify the new key.
- parent_key  
Specify the parent key.
- is_check_attr  
Specify `true` to check the passphrase and expiration of the parent key.
- password  
Specify the password that is associated with the key.
- expiration_duration  
Specify the expiration duration in seconds.

## Return Values
Returns `true` on success or `false` on failure. 

## Examples
- Example 1 - Renames a key

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
var_dump($k2hdkc->setValue("key1", "val1")); 
var_dump($k2hdkc->getValue("key1"));   
var_dump($k2hdkc->rename("key1", "key2"));
var_dump($k2hdkc->getValue("key2"));
'
```

The above example will output:

```
bool(true)
string(4) "val1"
bool(true)
string(4) "val1"
```


## See Also
- [K2hdkc::getValue](k2hdkc_class_getvalue.html) - Gets a value of the key
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Sets a pair of the key/value
