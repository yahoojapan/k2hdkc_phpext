---
layout: contents
language: ja
title: K2hdkc::remove
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_remove.html
lang_opp_word: To English
prev_url: k2hdkc_class_keyqueueputja.html
prev_string: K2hdkc::keyQueuePut
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_removesubkeysja.html
next_string: K2hdkc::removesubkeys
---

# K2hdkc::remove
キー/値形式のデータを削除する

## 説明

```
    public function remove(
        string $key,
        string $password = null): bool {}
```



## パラメータ
- key  
キーを指定してください。
- password  
パスワードを指定してください。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - Removes a key

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
var_dump($k2hdkc->setValue("key1", "val1"));
var_dump($k2hdkc->getValue("key1"));
var_dump($k2hdkc->remove("key1"));
var_dump($k2hdkc->getValue("key1"));
'
```

上の例の出力は以下となります。

```
bool(true)
string(4) "val1"
bool(true)
string(0) ""
```


## 参考
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
- [K2hdkc::getValue](k2hdkc_class_getvalueja.html) - キー/値形式のデータを取得する
