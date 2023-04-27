---
layout: contents
language: ja
title: K2hdkc::removeSubkeys
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_removesubkeys.html
lang_opp_word: To English
prev_url: k2hdkc_class_removeja.html
prev_string: K2hdkc::remove
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_renameja.html
next_string: K2hdkc::rename
---

# K2hdkc::removeSubkeys
任意のsubkeyを削除する

## 説明

```
    public function removeSubkeys(
        string $key,
        array $subkeys,
        bool $nested = false): bool {}
```



## パラメータ
- key  
キーを指定してください。
- subkey  
subkeysを指定してください。
- nested  
subkeyを再帰的に削除する場合は、 `true` を指定してください。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - 任意のsubkeyを削除する

```
$ php -r '
$k2hdkc = new K2hdkc("./tests/slave.ini");
$k2hdkc->addSubkey("test", "sub1", "subv1");
$k2hdkc->addSubkey("test", "sub2", "subv2");
var_dump($k2hdkc->getSubkeys("test")); 
var_dump($k2hdkc->removeSubkeys("test", array("sub1")));
var_dump($k2hdkc->getSubkeys("test")); 
$k2hdkc->close(); 
'
```

上の例の出力は以下となります。

```
array(2) {
  [0]=>
  string(4) "sub1"
  [1]=>
  string(4) "sub2"
}
bool(true)
array(1) {
  [0]=>
  string(4) "sub2"
}
```


## 参考
- [K2hdkc::addSubkey](k2hdkc_class_addsubkeyja.html) - subkeyを追加する 
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeysja.html) - 全てのsubkeyを取得する
