---
layout: contents
language: en-us
title: k2hdkcpx_queue_put
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_queue_putja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_get_value.html
prev_string: k2hdkcpx_get_value
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_remove.html
next_string: k2hdkcpx_remove
---

# k2hdkcpx_queue_put
Puts a value to a queue

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_queue_put(
    $handle_res,
    string $prefix,
    string $val,
    bool $is_fifo = true,
    bool $is_check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

Puts a value to the queue.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
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
- [K2hdkc::queuePut](k2hdkc_class_queueput.html) - Puts a value to the queue
