---
layout: contents
language: ja
title: k2hdkcpx_set_debug_level_silent
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_set_debug_level_silent.html
lang_opp_word: To English
prev_url: k2hdkcpx_set_debug_level_messageja.html
prev_string: k2hdkcpx_set_debug_level_message
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_set_debug_level_warningja.html
next_string: k2hdkcpx_set_debug_level_warning
---

# k2hdkcpx_set_debug_level_silent
デバッグメッセージの出力レベルをSILENTにする


## 説明

```
function k2hdkcpx_set_debug_level_silent(): void {}
```


## パラメータ
なし。

## 戻り値
なし。

## 例

```
php -r 'var_dump(k2hdkcpx_set_debug_level_silent());'
```

上の例は、下のように出力されます。

```
NULL
```


## 参考
- [k2hdkcpx_bump_debug_level](k2hdkcpx_bump_debug_levelja.html) - ログレベルを変更する
- [k2hdkcpx_load_debug_env](k2hdkcpx_load_debug_envja.html) - 環境変数DKCDBGMODE、DKCDBGFILEを読み込み設定する
- [k2hdkcpx_set_debug_file](k2hdkcpx_set_debug_fileja.html) - デバッグメッセージの出力先をstderrから指定したファイルに切り替える
- [k2hdkcpx_set_debug_level_dump](k2hdkcpx_set_debug_level_dumpja.html) - デバッグメッセージの出力レベルをDUMPにする
- [k2hdkcpx_set_debug_level_error](k2hdkcpx_set_debug_level_errorja.html) - デバッグメッセージの出力レベルをERRORにする
- [k2hdkcpx_set_debug_level_message](k2hdkcpx_set_debug_level_messageja.html) - デバッグメッセージの出力レベルをMESSAGE（INFO)にする
- [k2hdkcpx_set_debug_level_silent](k2hdkcpx_set_debug_level_silentja.html) - デバッグメッセージの出力レベルをSILENTにする
- [k2hdkcpx_set_debug_level_warning](k2hdkcpx_set_debug_level_warningja.html) - デバッグメッセージの出力レベルをWARNINGにする
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_fileja.html) - デバッグメッセージの出力先をstderrに戻す
