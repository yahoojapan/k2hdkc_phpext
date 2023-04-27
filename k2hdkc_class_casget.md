---
layout: contents
language: en-us
title: K2hdkc::casGet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_cassetja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_casdecrement.html
prev_string: K2hdkc::casDecrement
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casincrement.html
next_string: K2hdkc::casIncrement
---

# K2hdkc::casGet
Gets a value using CAS operation

## Description

```
    public function casGet(
        string $key,
        string $password = null): int|false {}
```

Gets a value using CAS operation.


## Parameters
- key  
Specify the key.
- password  
Specify the passphrase for encrypting the value.


## Return Values
Returns the value on success, otherwise 0(false).


## Examples
- Example 1 - Gets a value using CAS operation

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->casInit("key", 0);
$handle->casSet("key", 0, 1);
var_dump($handle->casGet("key"));
$handle->close();
'
```

The above example will output:

```
int(1)
```


## See Also
- [K2hdkc::casGet](k2hdkc_class_casget.html) - Gets a value using CAS operation
