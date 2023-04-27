---
layout: contents
language: en-us
title: k2hdkcpx_key_queue_put
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_key_queue_putja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_key_queue_get.html
prev_string: k2hdkcpx_key_queue_get
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_open.html
next_string: k2hdkcpx_open
---

# k2hdkcpx_key_queue_put
Puts a key/value pair on the queue

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_key_queue_put(
    $handle_res,
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
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
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


## See Also
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueput.html) - Puts a pair of the key/value on the queue
