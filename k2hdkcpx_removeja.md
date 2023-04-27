---
layout: contents
language: ja
title: k2hdkcpx_remove
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_remove.html
lang_opp_word: To English
prev_url: k2hdkcpx_queue_putja.html
prev_string: k2hdkcpx_queue_put
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_remove_subkeysja.html
next_string: k2hdkcpx_remove_subkeys
---

# k2hdkcpx_remove
キー/値形式のデータを削除する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_remove(
    $handle_res,
    string $key,
    string $password = null): bool {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- password  
パスワードを指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考

- [K2hdkc::remove](k2hdkc_class_removeja.html) - キー/値形式のデータを削除する
