---
layout: contents
language: en-us
title: K2hdkc::getAttrs
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_getattrsja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_close.html
prev_string: K2hdkc::close
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_getsubkeys.html
next_string: K2hdkc::getSubkeys
---

# K2hdkc::getAttrs
Gets attribute information of the key

## Description

```
    public function getAttrs(
        string $key): array|null {}
```

Gets attribute information of the key.

## Parameters
- key  
Specify the key to get attribute information

## Return Values
Returns arrays on success or `null` on failure. 

## Examples
- Example 1 - Gets attribute information of the key

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->setValue("key1", "val1");
var_dump($handle->getAttrs("key1"));
'
```

The above example will output:

```
array(1) {
  [0]=>
  string(5) "mtime"
}
```

## See Also
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Sets a pair of the key/value
