---
layout: contents
language: ja
title: 実行時変数
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: configurations.html
lang_opp_word: To English
prev_url: developerja.html
prev_string: Developer
top_url: indexja.html
top_string: TOP
next_url: 
next_string:
---

# 環境変数
K2HDKC PHP Extension ライブラリは、独自の環境変数を使いません。  
しかし、K2HDKC PHP Extension ライブラリが読み込む[K2HDKC](https://k2hdkc.antpick.ax/indexja.html)によって、環境変数が読み込まれます。  
これらの環境変数については、[こちら](https://k2hdkc.antpick.ax/environmentsja.html)を参照してください。  
[K2HDKC](https://k2hdkc.antpick.ax/indexja.html)の[環境変数](https://k2hdkc.antpick.ax/environmentsja.html)は、K2HDKCライブラリの動作確認、デバッグなどで利用できます。


# 実行時設定
php.iniに書かれた設定によって動的にライブラリの動作を変えられます。K2HDKC PHP Extensionでは、以下の設定項目が定義されています。

## k2hdkcpx.debug
ログレベルを、以下の中から一つ指定してください。このディレクティブは、プログラム中のどこでも設定が可能です。

- **error**  
エラーメッセージをログに記録します。
- **warning**  
エラーメッセージ、警告メッセージをログに記録します。
- **info**  
エラーメッセージ、警告メッセージ、通知メッセージをログに記録します。
- **silent(default)**  
ログに記録されるメッセージはありません。デフォルトのログレベルです。
 
