---
layout: contents
language: ja
title: K2hdkc::getValue
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_setvalue.html
lang_opp_word: To English
prev_url: k2hdkc_class_setvalueja.html
prev_string: K2hdkc::setValue
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_addsubkeyja.html
next_string: K2hdkc::addSubkey
---

# K2hdkc::getValue
valueを取得する

## 説明
```
    public function getValue(
        string $key,
        string $password = null): string|null {}
```


## パラメータ
- key  
キーを指定してください。
- password  
パスワードを指定してください。

## 戻り値
成功時は値、失敗時は `null` を返します。

## 例
- 例 1 - キーを指定し、キーに紐づいている値を取得します。

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
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
