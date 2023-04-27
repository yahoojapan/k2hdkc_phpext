---
layout: contents
language: en-us
title: K2hdkc::clearSubkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_clearsubkeyja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_casset.html
prev_string: K2hdkc::casSet
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_close.html
next_string: K2hdkc::close
---

# K2hdkc::clearSubkey
Removes all subkeys of the key

## Description

```
    public function clearSubkeys(
        string $key): bool {}
```

Removes all subkeys of the key.

## Parameters
- key  
Specify the key to remove all subkeys

## Return Values
Returns `true` on success or `false` on failure. 

## Examples
- Example 1 - Adds a subkey to the key

```
$ php -r '
$handle = new K2hdkc("./tests/slave.ini");
var_dump($handle->setValue("key1", "val1"));
$handle->addSubkey("key1", "key2", "val2");
var_dump($handle->getSubkeys("key1"));
var_dump($handle->clearSubkeys("key1"));
var_dump($handle->getSubkeys("key1"));
'
```

The above example will output:

```
bool(true)
array(1) {
  [0]=>
  string(4) "key2"
}
bool(true)
array(0) {
}
```


## See Also
- [K2hdkc::addSubkey](k2hdkc_class_addsubkey.html) - Adds a subkey to the key
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeys.html) - Removes all subkeys of the key
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeys.html) - Gets all subkeys of the key
