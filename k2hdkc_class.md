---
layout: contents
language: en-us
title: K2hdkc Class
short_desc: k2hdkc PHP Extension - PHP Extension library for k2hdkc
lang_opp_file: k2hdkc_classja.html
lang_opp_word: To Japanese
prev_url: constants.html
prev_string: Constants
top_url: developer.html
top_string: Developer
next_url: k2hdkcpx.html
next_string: k2hdkcpx Functions
---

# K2hdkc class
K2hdkc class provides methods to handle [k2hdkc](https://k2hdkc.antpick.ax/index.html) cluster.

## Class summary

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

## Methods
- [K2hdkc::__construct](k2hdkc_class_construct.html) - Creates a K2hdkc instance
- [K2hdkc::__destruct](k2hdkc_class_destruct.html) - Destructs a K2hdkc instance
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Sets a pair of the key/value
- [K2hdkc::getValue](k2hdkc_class_getvalue.html) - Gets a value of the key
- [K2hdkc::addSubkey](k2hdkc_class_addsubkey.html) - Adds a subkey to the key
- [K2hdkc::casGet](k2hdkc_class_casget.html) - Gets a value using CAS operation
- [K2hdkc::casDecrement](k2hdkc_class_casdecrement.html) - Decrements a value using CAS operation
- [K2hdkc::casIncrement](k2hdkc_class_casincrement.html) - Increments a value using CAS operation
- [K2hdkc::casInit](k2hdkc_class_casinit.html) - Initializes a value using CAS operation
- [K2hdkc::casSet](k2hdkc_class_casset.html) - Sets a value using CAS operation
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeys.html) - Removes all subkeys of the key
- [K2hdkc::close](k2hdkc_class_close.html) - Closes a connection with the K2hdkc cluster
- [K2hdkc::getAttrs](k2hdkc_class_getattrs.html) - Gets attribute information of the key
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeys.html) - Gets all subkeys of the key
- [K2hdkc::queueGet](k2hdkc_class_queueget.html) - Gets a value from the queue
- [K2hdkc::queuePut](k2hdkc_class_queueput.html) - Puts a value to the queue
- [K2hdkc::keyQueueGet](k2hdkc_class_keyqueueget.html) - Gets a pair of the key/value from the queue
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueput.html) - Puts a pair of the key/value from the queue
- [K2hdkc::remove](k2hdkc_class_remove.html) - Removes a pair of the key/value
- [K2hdkc::removeSubkeys](k2hdkc_class_removesubkeys.html) - Removes subkeys
- [K2hdkc::rename](k2hdkc_class_rename.html) - Renames a key
- [K2hdkc::setSubkeys](k2hdkc_class_setsubkeys.html) - Sets subkeys of the key


