---
layout: contents
language: ja
title: K2hdkc::queueput
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_addsubkey.html
lang_opp_word: To English
prev_url: k2hdkc_class_queuegetja.html
prev_string: K2hdkc::queueGet
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_keyqueuegetja.html
next_string: K2hdkc::keyQueueGet
---

# K2hdkc::queuePut
キューにvalueを保存する

## 説明

```
    public function queuePut(
        string $prefix,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```



## パラメータ
- prefix  
キューの名前を指定してください。
- val  
キューに値を保存する
- is_fifo  
先入先出キューの場合は、 `true` を指定してください。
- is_check_attr  
パスワードと有効期限をチェックする場合は、 `true` を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - キューにvalueを保存する

```
php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
var_dump($k2hdkc->queuePut("test", "value"));
var_dump($k2hdkc->queueGet("test"));
'
```

上の例の出力は以下となります。

```
bool(true)
string(5) "value"
```

## 参考
- [K2hdkc::queueGet](k2hdkc_class_queuegetja.html) - キューから値を取得する


