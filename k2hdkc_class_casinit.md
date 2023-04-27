---
layout: contents
language: en-us
title: K2hdkc::casInit
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_casinitja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_casincrement.html
prev_string: K2hdkc::casIncrement
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casset.html
next_string: K2hdkc::casset
---

# K2hdkc::casInit
Initializes a value using CAS operation

## Description

```
    public function casInit(
        string $key,
        int $val,
        string $password = null,
        int $expiration_duration = 0): bool {}
```

Initializes a value using CAS operation.


## Parameters
- key  
Specify the key.
- val  
Specify the new value of the key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success, otherwise `false`. 


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
- [K2hdkc::casSet](k2hdkc_class_casset.html) - Sets a value using CAS operation
- [K2hdkc::casGet](k2hdkc_class_casget.html) - Gets a value using CAS operation
