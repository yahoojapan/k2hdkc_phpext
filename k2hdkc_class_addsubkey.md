---
layout: contents
language: en-us
title: K2hdkc::addSubkey
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_addsubkeyja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_getvalue.html
prev_string: K2hdkc::getValue
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casdecrement.html
next_string: K2hdkc::casDecrement
---

# K2hdkc::addSubkey
Associates the key with the other key

## Description

```
    public function addSubkey(
        string $key,
        string $subkey,
        string $subval,
        bool $check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```

Associates the key with the other key. The key that is added to the other key is called 'subkey'. The key that adds the other key to is called 'parent key'. A parent key can associates many subkeys.

## Parameters
- key  
Specify the key.
- subkey  
Specify the subkey that is associated with the key.
- subval  
Specify the subval that is associated with the subkey.
- check_attr  
Specify `true` to check the passphrase and expiration of the parent key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.

## Return Values
Returns `true` on success or `false` on failure. 

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
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeys.html) - Gets a array of keys associated with the key
