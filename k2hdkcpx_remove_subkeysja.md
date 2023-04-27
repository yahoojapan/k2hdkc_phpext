---
layout: contents
language: ja
title: k2hdkcpx_remove_subkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_remove_subkeys.html
lang_opp_word: To English
prev_url: k2hdkcpx_removeja.html
prev_string: k2hdkcpx_remove
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_renameja.html
next_string: k2hdkcpx_rename
---

# k2hdkcpx_remove_subkeys
任意のsubkeyを削除する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_remove_subkeys(
    $handle_res,
    string $key,
    array $subkeys,
    bool $nested = false): bool {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- subkey  
subkeysを指定してください。
- nested  
subkeyを再帰的に削除する場合は、 `true` を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考
- [K2hdkc::removeSubkeys](k2hdkc_class_removesubkeysja.html) - 任意のsubkeyを削除する
