---
layout: contents
language: en-us
title: K2hdkc::queueGet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_addsubkeyja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_getsubkeys.html
prev_string: K2hdkc::getSubkeys
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_queueput.html
next_string: K2hdkc::queuePut
---

# K2hdkc::queueGet
Gets a value from the queue

## Description

```
    public function queueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): string|null {}
```

Gets a value from the queue.

## Parameters
- prefix  
Specify the prefix of queue name
- is_fifo  
Specify `true` if the order of the queue is FIFO(First-In-First-Out), otherwise `false`.
- password  
Specify the passphrase for encrypting the value.

## Return Values
Returns value on success or `null` on failure. 

## Examples
- Example 1 - Gets a value from the queue

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
$k2hdkc->queuePut("test", "value");
var_dump($k2hdkc->queueGet("test"));
'
```

The above example will output:

```
string(5) "value"
```

## See Also
- [K2hdkc::queuePut](k2hdkc_class_queueput.html) - Puts a value on the queue

