---
layout: contents
language: ja
title: K2hdkc::casGet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_casset.html
lang_opp_word: To English
prev_url: k2hdkc_class_casdecrementja.html
prev_string: K2hdkc::casDecrement
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casincrementja.html
next_string: K2hdkc::casIncrement
---

# K2hdkc::casGet
CASを使ってvalueを取得する

## 説明

```
    public function casGet(
        string $key,
        string $password = null): int|false {}
```


## パラメータ
- key  
キー指定してください。
- password  
値を暗号化するパスワードを指定してください。


## 戻り値
成功時は、値。


## 例
- 例 1 - CASを使ってvalueを取得する

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->casInit("key", 0);
$handle->casSet("key", 0, 1);
var_dump($handle->casGet("key"));
$handle->close();
'
```

上の例の出力は以下となります。

```
int(1)
```


## 参考
- [K2hdkc::casSet](k2hdkc_class_cassetja.html) - CASを使って値を保存する
