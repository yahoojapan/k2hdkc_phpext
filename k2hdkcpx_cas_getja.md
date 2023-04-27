---
layout: contents
language: ja
title: k2hdkcpx_cas_get
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_get.html
lang_opp_word: To English
prev_url: k2hdkcpx_cas_decrementja.html
prev_string: k2hdkcpx_cas_decrement
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_incrementja.html
next_string: k2hdkcpx_cas_increment
---

# k2hdkcpx_cas_get
CASを使って、値を取得する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_get(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): int {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キー指定してください。
- password  
値を暗号化するパスワードを指定してください。
- expiration_duration  
有効期限（秒）指定してください。


## 戻り値
成功時は、値。

## 参考
- [K2hdkc::casGet](k2hdkc_class_casgetja.html) - CASを使って値を取得する
