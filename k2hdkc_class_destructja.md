---
layout: contents
language: ja
title: K2hdkc::__destruct
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_construct.html
lang_opp_word: To English
prev_url: k2hdkc_class_constructja.html
prev_string: K2hdkc::__construct
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_setvalueja.html
next_string: K2hdkc::setValue
---

# K2hdkc::__destruct
[K2hdkc](k2hdkc_classja.html) クラスのインスタンスを解放する

## 説明

```
    public function __destruct() {}
```

[K2hdkc](k2hdkc_classja.html) クラスのインスタンスを解放します。

## パラメータ
This function has no parameters.

## 例
- 例 1 - [K2hdkc](k2hdkc_classja.html) クラスのインスタンスを解放する

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
- [K2hdkc::__construct](k2hdkc_class_constructja.html) - [K2hdkc](k2hdkc_classja.html) クラスのインスタンスを作る
