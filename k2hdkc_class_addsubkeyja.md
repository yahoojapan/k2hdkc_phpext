---
layout: contents
language: ja
title: K2hdkc::addSubkey
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkc_class_addsubkey.html
lang_opp_word: To English
prev_url: k2hdkc_class_getvalueja.html
prev_string: K2hdkc::getValue
top_url: k2hdkc_classja.html
top_string: K2hdkc Class
next_url: k2hdkc_class_casdecrementja.html
next_string: K2hdkc::casDecrement
---

# K2hdkc::addSubkey
subkeyを追加する

## 説明

```
    public function addSubkey(
        string $key,
        string $subkey,
        string $subval,
        bool $check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}
```

## パラメータ
- key  
subkeyと紐づけたいキー指定してください。
- subkey  
subkeyとして紐づけたいキーを指定してください。
- subval  
subkeyの値を指定してください。
- check_attr  
キーの暗号化パスワードと有効期限を確認する場合は `true` を指定してください。
- password  
値を暗号化するパスワードを指定してください。
- expiration_duration  
有効期限（秒）指定してください。

## 戻り値
成功時は、 `true` 失敗時は、 `false`を返します。 

## 例
- 例 1 - subkeyをキーに追加する

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
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeysja.html) - 全てのsubkeyを取得する
