<?php

/** @generate-class-entries */

/*
*
* K2HDKC PHP Extension library
* 
* Copyright 2023 Yahoo Japan Corporation.
* 
* K2HDKC is k2hash based distributed KVS cluster.
* K2HDKC uses K2HASH, CHMPX, FULLOCK libraries. K2HDKC supports
* distributed KVS cluster server program and client libraries.
* 
* For the full copyright and license information, please view
* the license file that was distributed with this source code.
*
* AUTHOR:   Hirotaka Wakabayashi
* CREATE:   Fri, Mar 31 2023
* REVISION:
*
*/

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

    // bool k2hdkc_pm_set_str_subkey_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, const char* pskeyval, bool checkattr, const char* encpass, const time_t* expire)
    public function addSubkey(
        string $key,
        string $subkey,
        string $subval,
        bool $check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_cas64_str_get_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, uint64_t* pval)
    public function casGet(
        string $key,
        string $password = null): int|false {}

    // bool k2hdkc_pm_cas_str_decrement_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
    public function casDecrement(
        string $key,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_cas_str_increment_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
    public function casIncrement(
        string $key,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_cas8_str_init_wa(k2hdkc_chmpx_h handle, const char* pkey, uint8_t val, const char* encpass, const time_t* expire)
    public function casInit(
        string $key,
        int $val,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_cas8_str_set_wa(k2hdkc_chmpx_h handle, const char* pkey, uint8_t oldval, uint8_t newval, const char* encpass, const time_t* expire)
    public function casSet(
        string $key,
        int $old_val,
        int $new_val,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_clear_str_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
    public function clearSubkeys(
        string $key): bool {}

    // bool k2hdkc_close_chmpx_ex(k2hdkc_chmpx_h handle, bool is_clean_bup)
    public function close(): bool {}

    // PK2HDKCATTRPCK k2hdkc_pm_get_str_direct_attrs(k2hdkc_chmpx_h handle, const char* pkey, int* pattrspckcnt)
    public function getAttrs(
        string $key): array|null {}

    // PK2HDKCKEYPCK k2hdkc_pm_get_direct_subkeys(k2hdkc_chmpx_h handle, const unsigned char* pkey, size_t keylength, int* pskeypckcnt)
    public function getSubkeys(
        string $key): array|null {}

    // bool k2hdkc_pm_q_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppval)
    public function queueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): string|null {}

    // bool k2hdkc_pm_q_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
    public function queuePut(
        string $prefix,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_keyq_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppkey, const char** ppval)
    public function keyQueueGet(
        string $prefix,
        bool $is_fifo = true,
        string $password = null): array|false {}

    // bool k2hdkc_pm_keyq_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pkey, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
    public function keyQueuePut(
        string $prefix,
        string $key,
        string $val,
        bool $is_fifo = true,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_remove_str(k2hdkc_chmpx_h handle, const char* pkey)
    public function remove(
        string $key,
        string $password = null): bool {}

    // bool k2hdkc_pm_remove_str_subkey(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, size_t subkeylength, bool is_nest)
    public function removeSubkeys(
        string $key,
        array $subkeys,
        bool $nested = false): bool {}

    // bool k2hdkc_pm_rename_with_parent_str_wa(k2hdkc_chmpx_h handle, const char* poldkey, const char* pnewkey, const char* pparentkey, bool checkattr, const char* encpass, const time_t* expire)
    public function rename(
        string $key,
        string $new_key,
        string $parent_key = null,
        bool $is_check_attr = true,
        string $password = null,
        int $expiration_duration = 0): bool {}

    // bool k2hdkc_pm_set_subkeys(k2hdkc_chmpx_h handle, const unsigned char* pkey, size_t keylength, const PK2HDKCKEYPCK pskeypck, int skeypckcnt)
    public function setSubkeys(
        string $key,
        array $subkeys): bool {}
}

/**
 * @return resource|false
 */
function k2hdkcpx_open(
    string $config_file,
    int $port = 8031,
    string $cuk = null,
    bool $rejoin = true,
    bool $rejoin_forever = true,
    bool $clear_backup = true) {}

// set
// bool k2hdkc_pm_set_str_all_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* pval, const char** pskeyarray, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_set_value(
    $handle_res,
    string $key,
    string $val,
    bool $clearSubkeys = false,
    array $subkeys = null,
    string $password = null,
    int $expirationDuration = 0): bool {}

// get
// bool k2hdkc_pm_get_str_value_wp(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, char** ppval);
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_value(
    $handle_res,
    string $key,
    string $password = null): string|null {}

// add_subkey
// bool k2hdkc_pm_set_str_subkey_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, const char* pskeyval, bool checkattr, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_add_subkey(
    $handle_res,
    string $key,
    string $subkey,
    string $subval,
    bool $check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}

// cas_get
// bool k2hdkc_pm_cas64_str_get_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, uint64_t* pval)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_get(
    $handle_res,
    string $key,
    string $password = null): int|false {}

// cas_decrement
// bool k2hdkc_pm_cas_str_decrement_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_decrement(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): bool {}

// cas_increment
// bool k2hdkc_pm_cas_str_increment_wa(k2hdkc_chmpx_h handle, const char* pkey, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_increment(
    $handle_res,
    string $key,
    string $password = null,
    int $expiration_duration = 0): bool {}

// cas_init
// bool k2hdkc_pm_cas8_str_init_wa(k2hdkc_chmpx_h handle, const char* pkey, uint8_t val, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_init(
    $handle_res,
    string $key,
    int $val,
    string $password = null,
    int $expiration_duration = 0): bool {}

// cas_set
// bool k2hdkc_pm_cas8_str_set_wa(k2hdkc_chmpx_h handle, const char* pkey, uint8_t oldval, uint8_t newval, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_cas_set(
    $handle_res,
    string $key,
    int $old_val,
    int $new_val,
    string $password = null,
    int $expiration_duration = 0): bool {}

// clear_subkeys
// bool k2hdkc_pm_clear_str_subkeys(k2hdkc_chmpx_h handle, const char* pkey)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_clear_subkeys(
    $handle_res,
    string $key): bool {}

// bool k2hdkc_close_chmpx_ex(k2hdkc_chmpx_h handle, bool is_clean_bup)
// public function close(): bool {}
/**
 * @param resource $handle_res
 */
function k2hdkcpx_close(
    $handle_res,
    bool $is_clean_bup = true): bool {}

// get_attributes
// PK2HDKCATTRPCK k2hdkc_pm_get_str_direct_attrs(k2hdkc_chmpx_h handle, const char* pkey, int* pattrspckcnt)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_attributes(
    $handle_res,
    string $key): array|null {}

// get_subkeys
// PK2HDKCKEYPCK k2hdkc_pm_get_direct_subkeys(k2hdkc_chmpx_h handle, const unsigned char* pkey, size_t keylength, int* pskeypckcnt)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_get_subkeys(
    $handle_res,
    string $key): array|null {}

// queue_get
// bool k2hdkc_pm_q_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppval)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_queue_get(
    $handle_res,
    string $prefix,
    bool $is_fifo = true,
    string $password = null): string|null {}

// queue_put
// bool k2hdkc_pm_q_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_queue_put(
    $handle_res,
    string $prefix,
    string $val,
    bool $is_fifo = true,
    bool $is_check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}

// keyqueue_get
// bool k2hdkc_pm_keyq_str_pop_wp(k2hdkc_chmpx_h handle, const char* pprefix, bool is_fifo, const char* encpass, const char** ppkey, const char** ppval)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_key_queue_get(
    $handle_res,
    string $prefix,
    bool $is_fifo = true,
    string $password = null): array|null{}

// keyqueue_put
// bool k2hdkc_pm_keyq_str_push_wa(k2hdkc_chmpx_h handle, const char* pprefix, const char* pkey, const char* pval, bool is_fifo, bool checkattr, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_key_queue_put(
    $handle_res,
    string $prefix,
    string $key,
    string $val,
    bool $is_fifo = true,
    bool $is_check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}

// remove
// bool k2hdkc_pm_remove_str(k2hdkc_chmpx_h handle, const char* pkey)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_remove(
    $handle_res,
    string $key,
    string $password = null): bool {}

// remove_subkeys
// bool k2hdkc_pm_remove_str_subkey(k2hdkc_chmpx_h handle, const char* pkey, const char* psubkey, size_t subkeylength, bool is_nest)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_remove_subkeys(
    $handle_res,
    string $key,
    array $subkeys,
    bool $nested = false): bool {}

// rename
// bool k2hdkc_pm_rename_with_parent_str_wa(k2hdkc_chmpx_h handle, const char* poldkey, const char* pnewkey, const char* pparentkey, bool checkattr, const char* encpass, const time_t* expire)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_rename(
    $handle_res,
    string $key,
    string $new_key,
    string $parent_key = null,
    bool $is_check_attr = true,
    string $password = null,
    int $expiration_duration = 0): bool {}

// set_subkeys
// bool k2hdkc_pm_set_subkeys(k2hdkc_chmpx_h handle, const unsigned char* pkey, size_t keylength, const PK2HDKCKEYPCK pskeypck, int skeypckcnt)
/**
 * @param resource $handle_res
 */
function k2hdkcpx_set_subkeys(
    $handle_res,
    string $key,
    array $subkeys): bool {}

// void k2hdkc_bump_debug_level(void)
function k2hdkcpx_bump_debug_level(): void {}

// void k2hdkc_set_debug_level_silent(void)
function k2hdkcpx_set_debug_level_silent(): void {}

// void k2hdkc_set_debug_level_error(void)
function k2hdkcpx_set_debug_level_error(): void {}

// void k2hdkc_set_debug_level_warning(void)
function k2hdkcpx_set_debug_level_warning(): void {}

// void k2hdkc_set_debug_level_message(void)
function k2hdkcpx_set_debug_level_message(): void {}

// void k2hdkc_set_debug_level_dump(void)
function k2hdkcpx_set_debug_level_dump(): void {}

// bool k2hdkc_set_debug_file(const char* filepath)
function k2hdkcpx_set_debug_file(string $filepath): bool {}

// bool k2hdkc_unset_debug_file(void)
function k2hdkcpx_unset_debug_file(): void {}

// bool k2hdkc_load_debug_env(void)
function k2hdkcpx_load_debug_env(): bool {}

// bool k2hdkc_is_enable_comlog(void)
function k2hdkcpx_is_enable_comlog(): bool {}

// void k2hdkc_enable_comlog(void)
function k2hdkcpx_enable_comlog(): bool {}

// void k2hdkc_disable_comlog(void)
function k2hdkcpx_disable_comlog(): bool {}

// void k2hdkc_toggle_comlog(void)
function k2hdkcpx_toggle_comlog(): bool {}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
