---
layout: contents
language: en-us
title: K2hdkc::keyQueueGet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_keyqueuegetja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_queueput.html
prev_string: K2hdkc::queuePut
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_keyqueueput.html
next_string: K2hdkc::keyQueuePut
---

# K2hdkc::keyQueueGet
Gets a pair of the key/value from the queue

## Description

```
    public function keyQueueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): array|false {}
```

Gets a pair of the key/value from the queue.

## Parameters
- prefix  
Specify the prefix of queue name
- is_fifo  
Specify `true` if the order of the queue is FIFO(First-In-First-Out), otherwise `false`.
- password  
Specify the passphrase for encrypting the value.

## Return Values
Returns an array on success or `null` on failure. 

## Examples
- Example 1 - Gets a key/value from the queue

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
$k2hdkc->keyQueuePut("test", "key", "value");
var_dump($k2hdkc->keyQueueGet("test"));
'
```

The above example will output:

```
array(1) {
  ["key"]=>
  string(5) "value"
}
```

## See Also
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueput.html) - Puts a key/value on the queue


