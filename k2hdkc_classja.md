---
layout: contents
language: ja
title: K2hdkc Class
short_desc: k2hdkc PHP Extension - PHP Extension library for k2hdkc
lang_opp_file: k2hdkc_class.html
lang_opp_word: To English
prev_url: constantsja.html
prev_string: 定数
top_url: developerja.html
top_string: Developer
next_url: k2hdkcpxja.html
next_string: k2hdkcpx 関数型インターフェース群
---

# K2hdkc クラス
K2hdkcクラスは、[k2hdkc](https://k2hdkc.antpick.ax/indexja.html)を操作するメソッドを提供します。  

## Class 概要

```
class K2hdkc {
    private string $_config_file;
    private int $_port;
    private string $_cuk;
    private bool $_rejoin;
    private bool $_rejoin_forever;
    private bool $_clear_backup;

    /** @var resource|null */
    private $_handle;

    public function __construct(
        string $config_file,
        int $port = 8031,
        string $cuk = null,
        bool $rejoin = true,
        bool $rejoin_forever = true,
        bool $clear_backup = true) {}

    public function __destruct() {}

    public function setValue(
        string $key,
        string $val,
        bool $clear_subkeys = false,
        array $subkeys = null,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function getValue(
        string $key,
        string $password = null): string|null {}

    public function addSubkey(
        string $key,
        string $subkey,
        string $subval,
        bool $check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function casGet(
        string $key,
        string $password = null): int|false {}

    public function casDecrement(
        string $key,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function casIncrement(
        string $key,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function casInit(
        string $key,
        int $val,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function casSet(
        string $key,
        int $old_val,
        int $new_val,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function clearSubkeys(
        string $key): bool {}

    public function close(): bool {}

    public function getAttrs(
        string $key): array|null {}

    public function getSubkeys(
        string $key): array|null {}

    public function queueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): string|null {}

    public function queuePut(
        string $prefix,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function keyQueueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): array|false {}

    public function keyQueuePut(
        string $prefix,
        string $key,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function remove(
        string $key,
        string $password = null): bool {}

    public function removeSubkeys(
        string $key,
        array $subkeys,
        bool $nested = false): bool {}

    public function rename(
        string $key,
        string $new_key,
        string $parent_key = null,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    public function setSubkeys(
        string $key,
        array $subkeys): bool {}

}
```

## メソッド一覧
- [K2hdkc::__construct](k2hdkc_class_constructja.html) - K2hdkcインスタンスを作成する
- [K2hdkc::__destruct](k2hdkc_class_destructja.html) - K2hdkcインスタンスを解放する
- [K2hdkc::setValue](k2hdkc_class_setvalueja.html) - キー/値形式のデータを保存する
- [K2hdkc::getValue](k2hdkc_class_getvalueja.html) - valueを取得する
- [K2hdkc::addSubkey](k2hdkc_class_addsubkeyja.html) - subkeyを追加する
- [K2hdkc::casGet](k2hdkc_class_casgetja.html) - CASを使ってvalueを取得する
- [K2hdkc::casDecrement](k2hdkc_class_casdecrementja.html) - CASを使ってvalueをひとつ減らす
- [K2hdkc::casIncrement](k2hdkc_class_casincrementja.html) - CASを使ってvalueをひとつ増やす
- [K2hdkc::casInit](k2hdkc_class_casinitja.html) - CASを使ってvalueを初期化する
- [K2hdkc::casSet](k2hdkc_class_cassetja.html) - CASを使ってvalueを保存する
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeysja.html) - 全てのsubkeyを消去する
- [K2hdkc::close](k2hdkc_class_closeja.html) - K2hdkcクラスタとの接続を閉じる
- [K2hdkc::getAttrs](k2hdkc_class_getattrsja.html) - keyの属性情報を取得する
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeysja.html) - 全てのsubkeyを取得する
- [K2hdkc::queueGet](k2hdkc_class_queuegetja.html) - キューからvalueを取得する
- [K2hdkc::queuePut](k2hdkc_class_queueputja.html) - キューにvalueを保存する
- [K2hdkc::keyQueueGet](k2hdkc_class_keyqueuegetja.html) - キー/値形式のデータをキューから取得する
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueputja.html) - キー/値形式のデータをキューに保存する
- [K2hdkc::remove](k2hdkc_class_removeja.html) - キー/値形式のデータを削除する
- [K2hdkc::removeSubkeys](k2hdkc_class_removesubkeysja.html) - 任意のsubkeyを削除する
- [K2hdkc::rename](k2hdkc_class_renameja.html) - key名を変更する
- [K2hdkc::setSubkeys](k2hdkc_class_setsubkeysja.html) - 任意のsubkeyをセットする


