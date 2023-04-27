---
layout: contents
language: ja
title: Runtime Configuratioins
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: runtime_configurations.html
lang_opp_word: To English
prev_url: constantsja.html
prev_string: 定数
top_url: developerja.html
top_string: Developer
next_url: k2hdkc_classja.html
next_string: K2hdkc Class
---

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
 
