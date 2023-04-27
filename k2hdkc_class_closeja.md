---
layout: contents
language: ja
title: K2hdkc::close
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_close.html
lang_opp_word: To English
prev_url: k2hdkc_class_clearsubkeysja.html
prev_string: K2hdkc::clearSubkeys
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_getattrsja.html
next_string: K2hdkc::getAttrs
---

# K2hdkc::close
K2hdkcクラスタとの接続を閉じる

## 説明

```
    public function close(): bool {}
```



## パラメータ
なし。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - K2hdkcクラスタとの接続を閉じる

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
var_dump($handle->close());
'
```

上の例の出力は以下となります。

```
bool(true)
```


## 参考
- [K2hdkc::__construct](k2hdkc_class_constructja.html) - [K2hdkc](k2hdkc_classja.html) インスタンスを作る
