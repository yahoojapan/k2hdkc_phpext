---
layout: contents
language: ja
title: k2hdkcpx_queue_get
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_queue_get.html
lang_opp_word: To English
prev_url: k2hdkcpx_get_valueja.html
prev_string: k2hdkcpx_get_value
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_queue_putja.html
next_string: k2hdkcpx_queue_put
---

# k2hdkcpx_queue_get
値をキューから取得する

## 説明

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


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- prefix  
キューの名前を指定してください。
- is_fifo  
先入先出キューとする場合は `true` を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。


## 戻り値
成功時は値、失敗時は `null` を指定してください。

## 参考
- [K2hdkc::queueGet](k2hdkc_class_queuegetja.html) - キューからvalueを取得する 
