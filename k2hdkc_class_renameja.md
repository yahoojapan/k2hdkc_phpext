---
layout: contents
language: ja
title: K2hdkc::rename
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_rename.html
lang_opp_word: To English
prev_url: k2hdkc_class_keyqueueputja.html
prev_string: K2hdkc::keyQueuePut
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_setsubkeysja.html
next_string: K2hdkc::setSubkeys
---

# K2hdkc::rename
キーの名前を変更する

## 説明

```
    public function rename(
        string $key,
        string $new_key,
        string $parent_key = null,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```



## パラメータ
- key  
キーを指定してください。
- new_key  
キーの新しい名前を指定してください。
- parent_key  
親のキーを指定してください。
- is_check_attr  
パスワードと有効期限を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - キーの名前を変更する

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
var_dump($k2hdkc->setValue("key1", "val1")); 
var_dump($k2hdkc->getValue("key1"));   
var_dump($k2hdkc->rename("key1", "key2"));
var_dump($k2hdkc->getValue("key2"));
'
```

上の例の出力は以下となります。

```
bool(true)
string(4) "val1"
bool(true)
string(4) "val1"
```


## 参考
- [K2hdkc::getValue](k2hdkc_class_getvalueja.html) - valueを取得する
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
