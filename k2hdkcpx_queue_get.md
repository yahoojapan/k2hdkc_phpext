---
layout: contents
language: en-us
title: k2hdkcpx_queue_get
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_queue_getja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_get_value.html
prev_string: k2hdkcpx_get_value
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_queue_put.html
next_string: k2hdkcpx_queue_put
---

# k2hdkcpx_queue_get
Gets a value from the queue

## Description

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_queue_get(
    $handle_res,
    string $prefix,
    bool $is_fifo = true,
    string $password = null): string|null {}
```

Gets a value from the queue.

## Parameters
- handle_res  
Specify the chmpx handle that [`k2hdkcpx_open`](k2hdkcpx_open.html) returns.
- prefix  
Specify the prefix of queue name
- is_fifo  
Specify `true` if the order of the queue is FIFO(First-In-First-Out), otherwise `false`.
- password  
Specify the passphrase for encrypting the value.
- expiration_duration  
Specify the expiration duration in seconds.


## Return Values
Returns value on success or `null` on failure. 

## See Also
- [K2hdkc::queueGet](k2hdkc_class_queueget.html) - Gets a value from the queue
