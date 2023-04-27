---
layout: contents
language: ja
title: k2hdkcpx_cas_init
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_init.html
lang_opp_word: To English
prev_url: k2hdkcpx_cas_incrementja.html
prev_string: k2hdkcpx_cas_increment
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_setja.html
next_string: k2hdkcpx_cas_set
---

# k2hdkcpx_cas_init
CASをつかって値を初期化する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_increment(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): bool {}
```


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- val  
値をして値してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。

## 参考
- [K2hdkc::casInit](k2hdkc_class_casinitja.html) - CASを使って値を初期化する
