---
layout: contents
language: ja
title: k2hdkcpx_get_value
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_get_value.html
lang_opp_word: To English
prev_url: k2hdkcpx_get_subkeysja.html
prev_string: k2hdkcpx_get_subkeys
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_key_queue_getja.html
next_string: k2hdkcpx_key_queue_get
---

# k2hdkcpx_get_value
値を取得する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_value(
	$handle_res,
	string $key,
	string $password = null): string|null {}
```

## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- password  
パスワードを指定してください。


## 戻り値
成功時は値、失敗時は `null` を返します。


## 参考
- [K2hdkc::getValue](k2hdkc_class_getvalueja.html) - valueを取得する
