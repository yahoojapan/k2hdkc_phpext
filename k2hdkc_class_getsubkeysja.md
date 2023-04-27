---
layout: contents
language: ja
title: K2hdkc::getSubkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_getsubkeys.html
lang_opp_word: To English
prev_url: k2hdkc_class_getattrsja.html
prev_string: K2hdkc::getAttrs
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_queuegetja.html
next_string: K2hdkc::queueGet
---

# K2hdkc::getSubkeys
全てのsubkeyを取得する

## 説明

```
    public function getSubkeys(
        string $key): array|null {}
```



## パラメータ
- key  
キーを指定してください。

## 戻り値
成功時は、subkeyの配列。失敗時は `null` を返します。


## 例
- 例 1 - 全てのsubkeyを取得する

```
php -r '
$k2hdkc = new K2hdkc("tests/slave.ini");
$k2hdkc->addSubkey("test", "sub");
var_dump($k2hdkc->getSubkeys("test"));
$k2hdkc->close();
'
```

上の例の出力は以下となります。

```
array(1) {
  [0]=>
  string(3) "sub"
}
```


## 参考
- [K2hdkc::addSubkey](k2hdkc_class_addsubkeyja.html) - subkeyを追加する
