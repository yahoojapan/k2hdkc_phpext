---
layout: contents
language: en-us
title: K2hdkc::casDecrement
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_casdecrementja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_addsubkey.html
prev_string: K2hdkc::addSubkey
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casget.html
next_string: K2hdkc::casGet
---

# K2hdkc::casDecrement
Decrements a value using CAS operation

## Description

```
    public function casDecrement(
        string $key,
        string $password = null,
        int $expiration_duration = 0): bool {}
```

Decrements a value using CAS operation.


## Parameters
- key  
Specify the key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns `true` on success, otherwise `false`. 


## Examples
- Example 1 - Decrements a value using CAS operation

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->casInit("key", 1);
$handle->casDecrement("key");
var_dump($handle->casGet("key"));
$handle->close();
'
```

The above example will output:

```
int(0)
```


## See Also
- [K2hdkc::casInit](k2hdkc_class_casinit.html) - Initializes a value using CAS operation
- [K2hdkc::casGet](k2hdkc_class_casget.html) - Gets a value using CAS operation
