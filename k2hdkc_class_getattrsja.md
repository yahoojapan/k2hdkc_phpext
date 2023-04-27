---
layout: contents
language: ja
title: K2hdkc::getAttrs
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_getattrs.html
lang_opp_word: To English
prev_url: k2hdkc_class_closeja.html
prev_string: K2hdkc::close
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_getsubkeysja.html
next_string: K2hdkc::getSubkeys
---

# K2hdkc::getAttrs
キーの属性情報を取得する

## 説明

```
    public function getAttrs(
        string $key): array|null {}
```



## パラメータ
- key  
キーを指定してください。

## 戻り値
成功時は、属性情報の配列。失敗時は `null` を返します。

## 例
- 例 1 - キーの属性情報を取得する

```
php -r '
$handle = new K2hdkc("./tests/slave.ini");
$handle->setValue("key1", "val1");
var_dump($handle->getAttrs("key1"));
'
```

上の例の出力は以下となります。

```
array(1) {
  [0]=>
  string(5) "mtime"
}
```

## 参考
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
