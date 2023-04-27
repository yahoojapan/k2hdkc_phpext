---
layout: contents
language: ja
title: K2hdkc::__set
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_setvalue.html
lang_opp_word: To English
prev_url: k2hdkc_class_destructja.html
prev_string: K2hdkc::__destruct
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_getvalueja.html
next_string: K2hdkc::getValue
---

# K2hdkc::setValue
キー/値形式のデータを保存する

## 説明
```
    public function setValue(
        string $key,
        string $val,
        bool $clear_subkeys = false,
        array $subkeys = null,
        string $password = null,
        int $expiration_duration = 0): bool {}
```


## パラメータ
- key  
キーを指定してください。
- val  
値を指定してください。
- clear_subkeys  
subkeyを削除する場合は、 `true` を指定してください。
- subkeys  
subkeyを指定していください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。

## 戻り値
成功時は、 `true`、失敗時は、 `false`を返します。

## 例
- 例 1 - キー/値形式のデータを保存する

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
- [K2hdkc::getValue](k2hdkc_class_getvalueja.html) - valueを取得する

