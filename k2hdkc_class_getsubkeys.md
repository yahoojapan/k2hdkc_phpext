---
layout: contents
language: en-us
title: K2hdkc::getSubkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_getsubkeysja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_getattrs.html
prev_string: K2hdkc::getAttrs
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_queueget.html
next_string: K2hdkc::queueGet
---

# K2hdkc::getSubkeys
Gets all subkeys of the key

## Description

```
    public function getSubkeys(
        string $key): array|null {}
```

Gets all subkeys of the key.

## Parameters
- key  
Specify the key.

## Return Values
Returns array on success or `null` on failure. 

## Examples
- Example 1 - Adds a subkey to the key

```
php -r '
$k2hdkc = new K2hdkc("tests/slave.ini");
$k2hdkc->addSubkey("test", "sub");
var_dump($k2hdkc->getSubkeys("test"));
$k2hdkc->close();
'
```

The above example will output:

```
array(1) {
  [0]=>
  string(3) "sub"
}
```


## See Also
- [K2hdkc::addSubkey](k2hdkc_class_addsubkey.html) - Adds a subkey to the key
