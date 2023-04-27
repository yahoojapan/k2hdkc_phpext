---
layout: contents
language: en-us
title: Feature
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: featureja.html
lang_opp_word: To Japanese
prev_url: home.html
prev_string: Overview
top_url: index.html
top_string: TOP
next_url: usage.html
next_string: Usage
---

# Feature
K2HDKC PHP Extension provides [K2HDKC](https://k2hdkc.antpick.ax/) API for [PHP](https://www.php.net/). You can build your own distributed and regilient [PHP](https://www.php.net/) application on your [K2HDKC](https://k2hdkc.antpick.ax/) cluster.

## Nested key structure
**K2HDKC** supports nested key data structure which means **K2HDKC** can store a key-value pair and a nested key-value pair. This functionality is derived from the [Sub key](https://k2hash.antpick.ax/feature.html) function of [K2HASH](https://k2hash.antpick.ax/).

![Fig.2](images/feature_fig2.png)

## Queue
**K2HDKC** supports a FIFO(first-in-first-out) and LIFO(last-in-first-out) queue data structure which is also a [K2HASH](https://k2hash.antpick.ax/)'s function.
This means that **K2HDKC** can store a value and a key-value pair in a queue data structure.

## CAS(Compare And Swap)
**K2HDKC** supports CAS(compare-and-swap) operations by using [K2HASH](https://k2hash.antpick.ax/) and other mutex functionality. **K2HDKC** updates a value of a key after reading the current value of the key to check if it matches the expected one. Typical use cases of CAS operations are increment or decrement a counter, updating a mutex data item and so on.

## Data Encryption
**K2HDKC** supports data encryption which is also a [K2HASH](https://k2hash.antpick.ax/)'s function.
This is the reason why **K2HDKC** can securely store and manage sensitive data.

## Data Expiration
**K2HDKC** supports data expiration. **K2HDKC** deletes data with exhausted  time-to-live. A typical use case of this function is some kind of a cache system. The **K2HDKC**'s data expiration functionality comes from [K2HASH](https://k2hash.antpick.ax/).

