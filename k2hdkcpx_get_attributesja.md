---
layout: contents
language: ja
title: k2hdkcpx_get_attributes
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_get_attributes.html
lang_opp_word: To English
prev_url: k2hdkcpx_closeja.html
prev_string: k2hdkcpx_close
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_get_subkeysja.html
next_string: k2hdkcpx_get_subkeys
---

# k2hdkcpx_get_attributes
キーの属性情報を取得する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_attributes(
    $handle_res,
    string $key): array|null {}
```


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。

## 戻り値
成功時は、属性情報の配列。失敗時は `null` を返します。

## 参考
- [K2hdkc::getAttrs](k2hdkc_class_getattrsja.html) - keyの属性情報を取得する
