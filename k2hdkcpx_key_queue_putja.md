---
layout: contents
language: ja
title: k2hdkcpx_key_queue_put
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_key_queue_put.html
lang_opp_word: To English
prev_url: k2hdkcpx_key_queue_getja.html
prev_string: k2hdkcpx_key_queue_get
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_openja.html
next_string: k2hdkcpx_open
---

# k2hdkcpx_key_queue_put
キー/値形式のデータをキューに保存する

## 説明

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


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- prefix  
キューの名前を指定してください。
- key  
キーを指定してください。
- val  
値を指定してください。
- is_fifo  
先入先出キューとする場合は、 `true` を指定してください。
- is_check_attr  
パスワードと有効期限を指定する場合は、 `true` を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 


## 参考
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueputja.html) - キー/値形式のデータをキューに保存する
