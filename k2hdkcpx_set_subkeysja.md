---
layout: contents
language: ja
title: k2hdkcpx_set_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_subkeys.html
lang_opp_word: To English
prev_url: k2hdkcpx_renameja.html
prev_string: k2hdkcpx_rename
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_valueja.html
next_string: k2hdkcpx_set_value
---

# k2hdkcpx_set_subkeys
任意のsubkeyを指定する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_set_subkeys(
    $handle_res,
    string $key,
    array $subkeys): bool {}
```


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- subkeys  
subkeyを指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考
- [K2hdkc::setSubkeys](k2hdkc_class_setsubkeysja.html) - 任意のsubkeyをセットする
