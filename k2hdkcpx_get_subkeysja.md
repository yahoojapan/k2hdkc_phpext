---
layout: contents
language: ja
title: k2hdkcpx_get_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_get_subkeys.html
lang_opp_word: To English
prev_url: k2hdkcpx_closeja.html
prev_string: k2hdkcpx_get_attributes
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_get_valueja.html
next_string: k2hdkcpx_get_value
---

# k2hdkcpx_get_subkeys
全てのsubkeyを取得する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_subkeys(
    $handle_res,
    string $key): array|null {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。


## 戻り値
成功時は、subkeyの配列。失敗時は `null` を返します。

## 参考
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeysja.html) - 全てのsubkeyを取得する
