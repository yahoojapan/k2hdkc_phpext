---
layout: contents
language: ja
title: k2hdkcpx_close
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_close.html
lang_opp_word: To English
prev_url: k2hdkcpx_clear_subkeysja.html
prev_string: k2hdkcpx_clear_subkeys
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_get_attributesja.html
next_string: k2hdkcpx_get_attributes
---

# k2hdkcpx_close
K2hdkcクラスタとの接続を閉じる

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_close(
    $handle_res,
    bool $is_clean_bup = true): bool {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- is_clean_bup  
一時ファイルを削除するときは、 `true` を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考
- [K2hdkc::close](k2hdkc_class_closeja.html) - K2hdkcクラスタとの接続を閉じる
