---
layout: contents
language: ja
title: K2hdkc::queueGet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_addsubkey.html
lang_opp_word: To English
prev_url: k2hdkc_class_getsubkeysja.html
prev_string: K2hdkc::getSubkeys
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_queueputja.html
next_string: K2hdkc::queuePut
---

# K2hdkc::queueGet
値をキューから取得する

## 説明

```
    public function queueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): string|null {}
```



## パラメータ
- prefix  
キューの名前を指定してください。
- is_fifo  
先入先出キューとする場合は `true` を指定してください。
- password  
パスワードを指定してください。

## 戻り値
成功時は値、失敗時は `null` を指定してください。


## 例
- 例 1 - 値をキューから取得する

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
$k2hdkc->queuePut("test", "value");
var_dump($k2hdkc->queueGet("test"));
'
```

上の例の出力は以下となります。

```
string(5) "value"
```

## 参考
- [K2hdkc::queuePut](k2hdkc_class_queueputja.html) - 値をキューに保存する

