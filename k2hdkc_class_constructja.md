---
layout: contents
language: ja
title: K2hdkc::__construct
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_destructja.html
next_string: K2hdkc::__destruct
---

# K2hdkc::__construct
K2hdkcインスタンスを作成する

## 説明

```
    public function __construct(
        string $config_file,
        int $port = 8031,
        string $cuk = null,
        bool $rejoin = true,
        bool $rejoin_forever = true,
        bool $clear_backup = true) {}
```

[K2hdkc](k2hdkc_classja.html)クラスのインスタンスを作成します。

## パラメータ
- config_file  
chmpxスレーブプロセスの設定ファイルを指定してください。
- port  
chmpxスレーブプロセスのポート番号を指定してください。
- cuk  
`cuk` 文字列を指定したください。`cuk` は、ノードごとにユニークな文字列です。
- rejoin  
chmpxスレーブプロセスに再接続する場合は、 `true` を指定してください。
- rejoin_forever  
chmpxスレーブプロセスに再接続し続ける場合は、 `true` を指定してください。
- clear_backup  
一時ファイルを削除する場合は、 `true` を指定してください。

## 例
- 例 1 - [K2hdkc](k2hdkc_classja.html) クラスのインスタンスを作成する

```
php -r '
k2hdkc = new K2hdkc("tests/slave.ini");
var_dump($k2hdkc->setValue("key1", "val1"));
var_dump($k2hdkc->getValue("key1"));
unset($k2hdkc);
'
```

上の例の出力は以下となります。

```
bool(true)
string(4) "val1"
```


## 参考
- [K2hdkc::__destruct](k2hdkc_class_destructja.html) - [K2hdkc](k2hdkc_classja.html) インスタンスを解放する
