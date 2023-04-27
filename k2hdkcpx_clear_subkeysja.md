---
layout: contents
language: ja
title: k2hdkcpx_clear_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_clear_subkeys.html
lang_opp_word: To English
prev_url: k2hdkcpx_cas_setja.html
prev_string: k2hdkcpx_cas_set
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_closeja.html
next_string: k2hdkcpx_close
---

# K2hdkc::clearSubkey
subkeyを消去する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_clear_subkeys(
    $handle_res,
    string $key): bool {}
```


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeysja.html) - 全てのsubkeyを消去する
