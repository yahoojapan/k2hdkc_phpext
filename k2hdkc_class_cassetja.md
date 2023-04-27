---
layout: contents
language: ja
title: K2hdkc::casSet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_casset.html
lang_opp_word: To English
prev_url: k2hdkc_class_casinitja.html
prev_string: K2hdkc::casInit
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_clearsubkeysja.html
next_string: K2hdkc::clearSubkeys
---

# K2hdkc::casSet
CASを使ってvalueを保存する

## 説明

```
    public function casSet(
        string $key,
        int $old_val,
        int $new_val,
        string $password = null,
        int $expiration_duration = 0): bool {}
```


## パラメータ
- key  
キーを指定してください。
- old_val  
現在の値を指定してください。
- new_val  
新しい値を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限（秒）を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 


## 例
- 例 1 - CASを使ってvalueを保存す

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
- [K2hdkc::casGet](k2hdkc_class_casgetja.html) - CASを使ってvalueを取得する 
