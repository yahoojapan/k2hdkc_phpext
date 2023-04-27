---
layout: contents
language: en-us
title: K2hdkc::keyQueuePut
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_keyqueueputja.html
lang_opp_word: To Japanese
prev_url: k2hdkc_class_keyqueueget.html
prev_string: K2hdkc::keyQueueGet
top_url: k2hdkc_class.html
top_string: K2hdkc Class
next_url: k2hdkc_class_remove.html
next_string: K2hdkc::remove
---

# K2hdkc::keyQueuePut
Puts a key/value pair on the queue

## Description

```
    public function keyQueuePut(
        string $prefix,
        string $key,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```

Puts a key/value pair on the queue.

## Parameters
- prefix  
Specify the prefix of queue name
- key  
Specify the key to add to the queue
- val  
Specify the value to add to the queue
- is_fifo  
Specify `true` if the order of the queue is FIFO(First-In-First-Out), otherwise `false`.
- is_check_attr  
Specify `true` to check the passphrase and expiration of the parent key.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.

## Return Values
Returns `true` on success or `false` on failure. 

## Examples
- Example 1 - Gets a key/value from the queue

```
$ php -r '
> $k2hdkc = new K2hdkc("./tests/slave.ini");
> var_dump($k2hdkc->keyQueuePut("test", "key", "value")); 
> var_dump($k2hdkc->keyQueueGet("test")); 
> '
```

The above example will output:

```
bool(true)
array(1) {
  ["key"]=>
  string(5) "value"
}
```

## See Also
- [K2hdkc::keyQueueGet](k2hdkc_class_keyqueueget.html) - Gets a key/value from the queue


