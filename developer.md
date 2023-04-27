---
layout: contents
language: en-us
title: Developer
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: developerja.html
lang_opp_word: To Japanese
prev_url: usage.html
prev_string: Usage
top_url: index.html
top_string: TOP
next_url: configurations.html
next_string: Configurations
---

# Developers

## [Predefined Constants](constants.html)
K2HDKC PHP Extension defines [constants](constants.html).

## [K2hdkc](k2hdkc_class.html) Class
[K2hdkc](k2hdkc_class.html) class provides the methods below.

- [K2hdkc::__construct](k2hdkc_class_construct.html) - Creates a K2hdkc instance
- [K2hdkc::__destruct](k2hdkc_class_destruct.html) - Destructs a K2hdkc instance
- [K2hdkc::setValue](k2hdkc_class_setvalue.html) - Sets a pair of a key/value
- [K2hdkc::getValue](k2hdkc_class_getvalue.html) - Gets a value of a key
- [K2hdkc::addSubkey](k2hdkc_class_addsubkey.html) - Adds a subkey to a key
- [K2hdkc::casGet](k2hdkc_class_casget.html) - Gets a value using CAS operation
- [K2hdkc::casDecrement](k2hdkc_class_casdecrement.html) - Decrements a value using CAS operation
- [K2hdkc::casIncrement](k2hdkc_class_casincrement.html) - Increments a value using CAS operation
- [K2hdkc::casInit](k2hdkc_class_casinit.html) - Initializes a value using CAS operation
- [K2hdkc::casSet](k2hdkc_class_casset.html) - Sets a value using CAS operation
- [K2hdkc::clearSubkeys](k2hdkc_class_clearsubkeys.html) - Removes all subkeys of a key
- [K2hdkc::close](k2hdkc_class_close.html) - Closes a connection with a K2hdkc cluster
- [K2hdkc::getAttrs](k2hdkc_class_getattrs.html) - Gets attribute information of a key
- [K2hdkc::getSubkeys](k2hdkc_class_getsubkeys.html) - Gets all subkeys of a key
- [K2hdkc::queueGet](k2hdkc_class_queueget.html) - Gets a value from a queue
- [K2hdkc::queuePut](k2hdkc_class_queueput.html) - Puts a value to a queue
- [K2hdkc::keyQueueGet](k2hdkc_class_keyqueueget.html) - Gets a pair of a key/value from a queue
- [K2hdkc::keyQueuePut](k2hdkc_class_keyqueueput.html) - Puts a pair of a key/value from a queue
- [K2hdkc::remove](k2hdkc_class_remove.html) - Removes a pair of a key/value
- [K2hdkc::removeSubkeys](k2hdkc_class_removesubkeys.html) - Removes subkeys
- [K2hdkc::rename](k2hdkc_class_rename.html) - Renames a key
- [K2hdkc::setSubkeys](k2hdkc_class_setsubkeys.html) - Sets subkeys of a key


## [K2hdkc](k2hdkcpx.html) Funsctions
[K2hdkc](k2hdkcpx.html) functions provides the methods below.

- [k2hdkcpx_add_subkey](k2hdkcpx_add_subkey.html) - Adds a new subkey to a key
- [k2hdkcpx_bump_debug_level](k2hdkcpx_bump_debug_level.html) - Changes the log level
- [k2hdkcpx_cas_decrement](k2hdkcpx_cas_decrement.html) - Decrements a variable in a cluster by using a CAS operation
- [k2hdkcpx_cas_get](k2hdkcpx_cas_get.html) - Gets a variable from a cluster using a CAS operation
- [k2hdkcpx_cas_increment](k2hdkcpx_cas_increment.html) - Increments a variable in a cluster by using a CAS operation
- [k2hdkcpx_cas_init](k2hdkcpx_cas_init.html) - Initializes a variable in a cluster by using a CAS operation
- [k2hdkcpx_cas_set](k2hdkcpx_cas_set.html) - Sets a value in a cluster by using a CAS operation
- [k2hdkcpx_clear_subkeys](k2hdkcpx_clear_subkeys.html) - Removes all subkeys of a key
- [k2hdkcpx_close](k2hdkcpx_close.html) - Closes the chmpx handle
- [k2hdkcpx_disable_comlog](k2hdkcpx_disable_comlog.html) - Disables the communication log output
- [k2hdkcpx_enable_comlog](k2hdkcpx_enable_comlog.html) - Enables the communication log output
- [k2hdkcpx_get_attributes](k2hdkcpx_get_attributes.html) - Retrievs attributes of a key
- [k2hdkcpx_get_subkeys](k2hdkcpx_get_subkeys.html) - Gets all subkeys of a key
- [k2hdkcpx_get_value](k2hdkcpx_get_value.html) - Gets a value of a key
- [k2hdkcpx_is_enable_comlog](k2hdkcpx_is_enable_comlog.html) - Check the enable/disable of the communication log output
- [k2hdkcpx_key_queue_get](k2hdkcpx_key_queue_get.html) - Gets a pair of a key/value from a queue
- [k2hdkcpx_key_queue_put](k2hdkcpx_key_queue_put.html) - Puts a pair of a key/value from a queue
- [k2hdkcpx_load_debug_env](k2hdkcpx_load_debug_env.html) - Sets the message output and output destination according to the value
- [k2hdkcpx_open](k2hdkcpx_open.html) - Creates a connection to chmpx slave
- [k2hdkcpx_queue_get](k2hdkcpx_queue_get.html) - Gets a value from a queue
- [k2hdkcpx_queue_put](k2hdkcpx_queue_put.html) - Puts a value to a queue
- [k2hdkcpx_remove](k2hdkcpx_remove.html) - Removes a pair of a key/value
- [k2hdkcpx_remove_subkeys](k2hdkcpx_remove_subkeys.html) - Removes subkeys
- [k2hdkcpx_rename](k2hdkcpx_rename.html) - Renames a key
- [k2hdkcpx_set_debug_file](k2hdkcpx_set_debug_file.html) - Specify the file to output message
- [k2hdkcpx_set_debug_level_dump](k2hdkcpx_set_debug_level_dump.html) - Sets the message output level to dump
- [k2hdkcpx_set_debug_level_error](k2hdkcpx_set_debug_level_error.html) - Sets the message output level to error
- [k2hdkcpx_set_debug_level_message](k2hdkcpx_set_debug_level_message.html) - Sets the message output level to message
- [k2hdkcpx_set_debug_level_silent](k2hdkcpx_set_debug_level_silent.html) - Sets the message output level to silent
- [k2hdkcpx_set_debug_level_warning](k2hdkcpx_set_debug_level_warning.html) - Sets the message output level to warning
- [k2hdkcpx_set_subkeys](k2hdkcpx_set_subkeys.html) - Sets subkeys of a key
- [k2hdkcpx_set_value](k2hdkcpx_set_value.html) - Sets a pair of a key/value
- [k2hdkcpx_toggle_comlog](k2hdkcpx_toggle_comlog.html) - Toggles the communication log output
- [k2hdkcpx_unset_debug_file](k2hdkcpx_unset_debug_file.html) - Sets output messages to stderr

