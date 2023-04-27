---
layout: contents
language: ja
title: K2hdkc::clearSubkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_clearsubkey.html
lang_opp_word: To English
prev_url: k2hdkc_class_cassetja.html
prev_string: K2hdkc::casSet
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_closeja.html
next_string: K2hdkc::close
---

# K2hdkc::clearSubkey
subkeyを消去する

## 説明

```
    public function clearSubkeys(
        string $key): bool {}
```


## パラメータ
- key  
キーを指定してください。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - subkeyを消去する

```
$ php -r '
$handle = new K2hdkc("./tests/slave.ini");
var_dump($handle->setValue("key1", "val1"));
$handle->addSubkey("key1", "key2", "val2");
var_dump($handle->getSubkeys("key1"));
var_dump($handle->clearSubkeys("key1"));
var_dump($handle->getSubkeys("key1"));
'
```

上の例の出力は以下となります。

```
bool(true)
array(1) {
  [0]=>
  string(4) "key2"
}
bool(true)
array(0) {
}
```


## 参考
- [K2hdkc::addSubkey](k2hdkc_class_addsubkeyja.html) - subkeyを追加する
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeysja.html) - 全てのsubkeyを消去する
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeysja.html) - subkeyを取得する
