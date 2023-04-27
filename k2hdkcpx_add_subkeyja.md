---
layout: contents
language: ja
title: k2hdkcpx_add_subkey
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_add_subkey.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_cas_decrementja.html
next_string: k2hdkcpx_cas_decrement
---

# k2hdkcpx_add_subkey
subkeyを追加する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_add_subkey(
    $handle_res,
    string $key,
    string $subkey,
    string $subval,
    bool $check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
subkeyと紐づけたいキー指定してください。
- subkey  
subkeyとして紐づけたいキーを指定してください。
- subval  
subkeyの値を指定してください。
- check_attr  
キーの暗号化パスワードと有効期限を確認する場合は `true` を指定してください。
- password  
値を暗号化するパスワードを指定してください。
- expiration_duration  
有効期限（秒）指定してください。


## 戻り値
成功時は `true` 。それ以外は `false` を返します。

## 参考
- [K2hdkc::addSubkey](k2hdkc_class_addsubkeyja.html) - subkeyを追加する
