---
layout: contents
language: ja
title: K2hdkc::casDecrement
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_casdecrement.html
lang_opp_word: To English
prev_url: k2hdkc_class_addsubkeyja.html
prev_string: K2hdkc::addSubkey
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casgetja.html
next_string: K2hdkc::casGet
---

# K2hdkc::casDecrement
CASを使ってvalueをひとつ減らす

## 説明

```
    public function casDecrement(
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
- 例 1 - CASを使って値をひとつ減らす

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->casInit("key", 1);
$handle->casDecrement("key");
var_dump($handle->casGet("key"));
$handle->close();
'
```

上の例の出力は以下となります。

```
int(0)
```


## 参考
- [K2hdkc::casInit](k2hdkc_class_casinitja.html) -  CASを使ってvalueを初期化する
- [K2hdkc::casGet](k2hdkc_class_casgetja.html) - CASを使ってvalueを取得する
