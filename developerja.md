---
layout: contents
language: ja
title: Developer
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: developer.html
lang_opp_word: To English
prev_url: usageja.html
prev_string: Usage
top_url: indexja.html
top_string: TOP
next_url: configurationsja.html
next_string: 実行時変数
---

# 開発者向け

## [定義済み定数](constantsja.html)
K2HDKC PHP Extensionは、[定数](constantsja.html)を定義しています。

## [K2hdkc](k2hdkc_classja.html) Class
[K2hdkc](k2hdkc_classja.html)クラスは、次のメソッドを提供します。

- [K2hdkc::__construct](k2hdkc_class_constructja.html) - K2hdkcインスタンスを作成する
- [K2hdkc::__destruct](k2hdkc_class_destructja.html) - K2hdkcインスタンスを解放する
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
- [K2hdkc::getValue](k2hdkc_class_getvalueja.html) - valueを取得する
- [K2hdkc::addSubkey](k2hdkc_class_addsubkeyja.html) - subkeyを追加する
- [K2hdkc::casGet](k2hdkc_class_casgetja.html) - CASを使ってvalueを取得する
- [K2hdkc::casDecrement](k2hdkc_class_casdecrementja.html) - CASを使ってvalueをひとつ減らす
- [K2hdkc::casIncrement](k2hdkc_class_casincrementja.html) - CASを使ってvalueをひとつ増やす
- [K2hdkc::casInit](k2hdkc_class_casinitja.html) - CASを使ってvalueを初期化する
- [K2hdkc::casSet](k2hdkc_class_cassetja.html) - CASを使ってvalueを保存する
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeysja.html) - 全てのsubkeyを消去する
- [K2hdkc::close](k2hdkc_class_closeja.html) - K2hdkcクラスタとの接続を閉じる
- [K2hdkc::getAttrs](k2hdkc_class_getattrsja.html) - keyの属性情報を取得する
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeysja.html) - 全てのsubkeyを取得する
- [K2hdkc::queueGet](k2hdkc_class_queuegetja.html) - キューからvalueを取得する
- [K2hdkc::queuePut](k2hdkc_class_queueputja.html) - キューにvalueを保存する
- [K2hdkc::keyQueueGet](k2hdkc_class_keyqueuegetja.html) - キー/値形式のデータをキューから取得する
- [K2hdkc::remove](k2hdkc_class_removeja.html) - キー/値形式のデータを削除する
- [K2hdkc::removeSubkeys](k2hdkc_class_removesubkeysja.html) - 任意のsubkeyを削除する
- [K2hdkc::rename](k2hdkc_class_renameja.html) - key名を変更する
- [K2hdkc::setSubkeys](k2hdkc_class_setsubkeysja.html) - 任意のsubkeyをセットする


## [K2hdkc](k2hdkcpxja.html) Funsctions
[K2hdkc](k2hdkcpxja.html) 関数群の関数は、次のとおりです。

- [k2hdkcpx_add_subkey](k2hdkcpx_add_subkeyja.html) - subkeyを追加する
- [k2hdkcpx_bump_debug_level](k2hdkcpx_bump_debug_levelja.html) - ログレベルを変更する
- [k2hdkcpx_cas_decrement](k2hdkcpx_cas_decrementja.html) - CASを使ってvalueをひとつ減らす
- [k2hdkcpx_cas_get](k2hdkcpx_cas_getja.html) - CASを使ってvalueを取得する
- [k2hdkcpx_cas_increment](k2hdkcpx_cas_incrementja.html) - CASを使ってvalueをひとつ増やす
- [k2hdkcpx_cas_init](k2hdkcpx_cas_initja.html) - CASを使ってvalueを初期化する
- [k2hdkcpx_cas_set](k2hdkcpx_cas_setja.html) - CASを使ってvalueを保存する
- [k2hdkcpx_clear_subkeys](k2hdkcpx_clear_subkeysja.html) - 全てのsubkeyを消去する
- [k2hdkcpx_close](k2hdkcpx_closeja.html) - K2hdkcクラスタとの接続を閉じる
- [k2hdkcpx_disable_comlog](k2hdkcpx_disable_comlogja.html) - 通信コマンドの送受信ログ出力を無効にする
- [k2hdkcpx_enable_comlog](k2hdkcpx_enable_comlogja.html) - 通信コマンドの送受信ログ出力を有効にする
- [k2hdkcpx_get_attributes](k2hdkcpx_get_attributesja.html) - keyの属性情報を取得する
- [k2hdkcpx_get_subkeys](k2hdkcpx_get_subkeysja.html) - 全てのsubkeyを取得する
- [k2hdkcpx_get_value](k2hdkcpx_get_valueja.html) - valueを取得する
- [k2hdkcpx_is_enable_comlog](k2hdkcpx_is_enable_comlogja.html) - 通信コマンドの送受信ログが出力中かどうかを判定する
- [k2hdkcpx_key_queue_get](k2hdkcpx_key_queue_getja.html) - キー/値形式のデータをキューから取得する
- [k2hdkcpx_key_queue_put](k2hdkcpx_key_queue_putja.html) - キー/値形式のデータをキューに保存する
- [k2hdkcpx_load_debug_env](k2hdkcpx_load_debug_envja.html) - 環境変数DKCDBGMODE、DKCDBGFILEを読み込み設定する
- [k2hdkcpx_open](k2hdkcpx_openja.html) - chmpxスレーブノードへ接続する
- [k2hdkcpx_queue_get](k2hdkcpx_queue_getja.html) - キューからvalueを取得する
- [k2hdkcpx_queue_put](k2hdkcpx_queue_putja.html) - キューにvalueを保存する
- [k2hdkcpx_remove](k2hdkcpx_removeja.html) - キー/値形式のデータを削除する
- [k2hdkcpx_remove_subkeys](k2hdkcpx_remove_subkeysja.html) - 任意のsubkeyを削除する
- [k2hdkcpx_rename](k2hdkcpx_renameja.html) - key名を変更する
- [k2hdkcpx_set_debug_file](k2hdkcpx_set_debug_fileja.html) - デバッグメッセージの出力先をstderrから指定したファイルに切り替える
- [k2hdkcpx_set_debug_level_dump](k2hdkcpx_set_debug_level_dumpja.html) - デバッグメッセージの出力レベルをDUMPにする
- [k2hdkcpx_set_debug_level_error](k2hdkcpx_set_debug_level_errorja.html) - デバッグメッセージの出力レベルをERRORにする
- [k2hdkcpx_set_debug_level_message](k2hdkcpx_set_debug_level_messageja.html) - デバッグメッセージの出力レベルをMESSAGE（INFO)にする
- [k2hdkcpx_set_debug_level_silent](k2hdkcpx_set_debug_level_silentja.html) - デバッグメッセージの出力レベルをSILENTにする
- [k2hdkcpx_set_debug_level_warning](k2hdkcpx_set_debug_level_warningja.html) - デバッグメッセージの出力レベルをWARNINGにする
- [k2hdkcpx_set_subkeys](k2hdkcpx_set_subkeysja.html) - 任意のsubkeyをセットする
- [k2hdkcpx_set_value](k2hdkcpx_set_valueja.html) - キー/値形式のデータを保存する
- [k2hdkcpx_toggle_comlog](k2hdkcpx_toggle_comlogja.html) - 通信コマンドの送受信ログ出力を有効/無効で切り替える
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_fileja.html) - デバッグメッセージの出力先をstderrに戻す

