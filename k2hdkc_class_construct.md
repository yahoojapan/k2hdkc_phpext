---
layout: contents
language: en-us
title: K2hdkc::__construct
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_destruct.html
next_string: K2hdkc::__destruct
---

# K2hdkc::__construct
Creates a K2hdkc instance

## Description

```
    public function __construct(
        string $config_file,
        int $port = 8031,
        string $cuk = null,
        bool $rejoin = true,
        bool $rejoin_forever = true,
        bool $clear_backup = true) {}
```

Creates a [K2hdkc](k2hdkc_class.html) instance.

## Parameters
- config_file  
Specify a chmpx slave configuration file.
- port  
Specify the port that chmpx slave process listens.
- cuk  
Specify the `cuk` string that is a unique string for each node in the cluster.
- rejoin  
Specify `true` when reconnecting with chmpx slave process.
- rejoin_forever  
Specify `true` when reconnecting with chmpx slave process infinitely.
- clear_backup  
Specify `true` when removing the temporary files

## Examples
- Example 1 - Creates a [K2hdkc](k2hdkc_class.html) instance

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
- [K2hdkc::__destruct](k2hdkc_class_destruct.html) - Destructs a [K2hdkc](k2hdkc_class.html) instance
