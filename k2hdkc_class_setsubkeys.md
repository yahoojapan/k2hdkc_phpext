---
layout: contents
language: en-us
title: K2hdkc::setSubkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_removesubkeysja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_remove.html
prev_string: K2hdkc::remove
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: 
next_string: 
---

# K2hdkc::setSubkeys
Sets a subkeys

## Description

```
    public function setSubkeys(
        string $key,
        array $subkeys,
        bool $nested = false): bool {}
```

Sets a subkeys.

## Parameters
- key  
Specify the key.
- subkey  
Specify the subkeys that is associated with the key.
- nested  
Specify `true` if remove subkeys recursively.

## Return Values
Returns `true` on success or `false` on failure. 

## Examples
- Example 1 - Sets a subkeys

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
$k2hdkc->addSubkey("test", "sub1", "subv1");
$k2hdkc->addSubkey("test", "sub2", "subv2");
var_dump($k2hdkc->getSubkeys("test")); 
var_dump($k2hdkc->setSubkeys("test", array("sub1")));
var_dump($k2hdkc->getSubkeys("test")); 
$k2hdkc->close(); 
'
```

The above example will output:

```
array(2) {
  [0]=>
  string(4) "sub1"
  [1]=>
  string(4) "sub2"
}
bool(true)
array(1) {
  [0]=>
  string(4) "sub2"
}
```


## See Also
- [K2hdkc::addSubkey](k2hdkc_class_addsubkey.html) - Adds a subkey to the key
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeys.html) - Gets all subkeys of the key

