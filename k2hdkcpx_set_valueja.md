---
layout: contents
language: ja
title: k2hdkcpx_set_value
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_value.html
lang_opp_word: To English
prev_url: k2hdkcpx_set_subkeysja.html
prev_string: k2hdkcpx_set_subkeys
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_bump_debug_levelja.html
next_string: k2hdkcpx_bump_debug_level
---

# k2hdkcpx_set_value
キー/値形式のデータを保存する

## 説明

```
/**
 * @param resource $handle_res
 */
function k2hdkcpx_set_value(
	$handle_res,
	string $key,
	string $val,
	bool $clearSubkeys = false,
	array $subkeys = null,
	string $password = null,
	int $expirationDuration = 0): bool {}
```


## パラメータ
- handle_res  
[`k2hdkcpx_open`](k2hdkcpx_openja.html) の戻り値を指定してください。
- key  
キーを指定してください。
- val  
値を指定してください。
- clear_subkeys  
subkeyを削除する場合は、 `true` を指定してください。
- subkeys  
subkeyを指定していください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 参考
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
