---
layout: contents
language: ja
title: k2hdkcpx_toggle_comlog
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_toggle_comlog.html
lang_opp_word: To English
prev_url: k2hdkcpx_set_debug_level_warningja.html
prev_string: k2hdkcpx_set_debug_level_warning
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_unset_debug_fileja.html
next_string: k2hdkcpx_unset_debug_file
---

# k2hdkcpx_toggle_comlog
通信コマンドの送受信ログ出力を有効/無効で切り替える  

## 説明

```
function k2hdkcpx_toggle_comlog(): bool {}
```


## パラメータ
なし。


## 戻り値
成功時は、 `true` ,失敗時は、 `false` を返します。


## 例

```
php -r 'var_dump(k2hdkcpx_toggle_comlog());' 
```

上の例は、下のように出力されます。

```
bool(true)
```


## 参考
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_fileja.html) - デバッグメッセージの出力先をstderrに戻す
- [k2hdkcpx_disable_comlog](k2hdkcpx_disable_comlogja.html) - 通信コマンドの送受信ログ出力を無効にする
- [k2hdkcpx_enable_comlog](k2hdkcpx_enable_comlogja.html) - 通信コマンドの送受信ログ出力を有効にする
- [k2hdkcpx_is_enable_comlog](k2hdkcpx_is_enable_comlogja.html) - 通信コマンドの送受信ログが出力中かどうかを判定する
- [k2hdkcpx_toggle_comlog](k2hdkcpx_toggle_comlogja.html) - 通信コマンドの送受信ログ出力を有効/無効で切り替える
