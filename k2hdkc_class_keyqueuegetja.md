---
layout: contents
language: ja
title: K2hdkc::keyQueueGet
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_keyqueueget.html
lang_opp_word: To English
prev_url: k2hdkc_class_queueputja.html
prev_string: K2hdkc::queuePut
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_keyqueueputja.html
next_string: K2hdkc::keyQueuePut
---

# K2hdkc::keyQueueGetG
キー/値形式のデータをキューから取得する

## 説明

```
    public function keyQueueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): array|false {}
```



## パラメータ
- prefix  
キューの名前を指定してください。
- is_fifo  
先入先出しキューの場合は `true` を指定してください。
- password  
パスワードを指定してください。

## 戻り値
成功時はキー/値形式の配列、失敗時は `null` を返します。


## 例
- 例 1 - キー/値形式のデータをキューから取得する

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
$k2hdkc->keyQueuePut("test", "key", "value");
var_dump($k2hdkc->keyQueueGet("test"));
'
```

上の例の出力は以下となります。

```
array(1) {
  ["key"]=>
  string(5) "value"
}
```

## 参考
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueputja.html) - キー/値形式のデータをキューに保存する


