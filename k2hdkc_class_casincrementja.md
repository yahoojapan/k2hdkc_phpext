---
layout: contents
language: ja
title: K2hdkc::casIncrement
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_casincrement.html
lang_opp_word: To English
prev_url: k2hdkc_class_casdecrementja.html
prev_string: K2hdkc::casDecrement
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casinitja.html
next_string: K2hdkc::casInit
---

# K2hdkc::casIncrement
CASを使ってvalueをひとつ増やす

## 説明

```
    public function casIncrement(
        string $key,
        string $password = null,
        int $expiration_duration = 0): bool {}
```


## パラメータ
- key  
キーを指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限（秒）を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 


## 例
- 例 1 - CASを使ってvalueをひとつ増やす 

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->casInit("key", 0);
$handle->casIncrement("key");
var_dump($handle->casGet("key"));
$handle->close();
'
```

上の例の出力は以下となります。

```
int(1)
```


## 参考
- [K2hdkc::casInit](k2hdkc_class_casinitja.html) -  CASを使ってvalueを初期化する
- [K2hdkc::casGet](k2hdkc_class_casgetja.html) - CASを使ってvalueを取得する
