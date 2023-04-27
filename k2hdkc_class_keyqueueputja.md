---
layout: contents
language: ja
title: K2hdkc::keyQueuePut
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_keyqueueput.html
lang_opp_word: To English
prev_url: k2hdkc_class_keyqueuegetja.html
prev_string: K2hdkc::keyQueueGet
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_removeja.html
next_string: K2hdkc::remove
---

# K2hdkc::keyQueuePut
キー/値形式のデータをキューに保存する

## 説明

```
    public function keyQueuePut(
        string $prefix,
        string $key,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```



## パラメータ
- prefix  
キューの名前を指定してください。
- key  
キーを指定してください。
- val  
値を指定してください。
- is_fifo  
先入先出キューとする場合は、 `true` を指定してください。
- is_check_attr  
パスワードと有効期限を指定する場合は、 `true` を指定してください。
- password  
パスワードを指定してください。
- expiration_duration  
有効期限を指定してください。


## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - キー/値形式のデータをキューに保存する

```
$ php -r '
> $k2hdkc = new K2hdkc("./tests/slave.ini");
> var_dump($k2hdkc->keyQueuePut("test", "key", "value")); 
> var_dump($k2hdkc->keyQueueGet("test")); 
> '
```

上の例の出力は以下となります。

```
bool(true)
array(1) {
  ["key"]=>
  string(5) "value"
}
```

## 参考
- [K2hdkc::keyQueueGet](k2hdkc_class_keyqueuegetja.html) - キー/値形式のデータをキューから取得する


