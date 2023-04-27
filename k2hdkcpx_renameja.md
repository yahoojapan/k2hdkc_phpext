---
layout: contents
language: ja
title: k2hdkcpx_rename
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_rename.html
lang_opp_word: To English
prev_url: k2hdkcpx_remove_subkeysja.html
prev_string: k2hdkcpx_remove_subkeys
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_subkeysja.html
next_string: k2hdkcpx_set_subkeys
---

# k2hdkcpx_rename
キーの名前を変更する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_rename(
    $handle_res,
    string $key,
    string $new_key,
    string $parent_key = null,
    bool $is_check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- new_key  
キーの新しい名前を指定してください。
- parent_key  
親のキーを指定してください。
- is_check_attr  
パスワードと有効期限を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考
- [K2hdkc::rename](k2hdkc_class_renameja.html) - キーの名前を変更する
