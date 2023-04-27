---
layout: contents
language: ja
title: k2hdkcpx_cas_set
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_cas_set.html
lang_opp_word: To English
prev_url: k2hdkcpx_cas_initja.html
prev_string: k2hdkcpx_cas_init
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_clear_subkeysja.html
next_string: k2hdkcpx_clear_subkeys
---

# k2hdkcpx_cas_set
CASを使ってvalueを保存する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_set(
    $handle_res,
    string $key,
    int $old_val,
    int $new_val,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- old_val  
現在の値を指定してください。
- new_val  
新しい値を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限（秒）を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 


## 参考
- [K2hdkc::casSet](k2hdkc_class_cassetja.html) - CASを使ってvalueを保存する
