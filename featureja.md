---
layout: contents
language: ja
title: Feature
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: feature.html
lang_opp_word: To English
prev_url: homeja.html
prev_string: Overview
top_url: indexja.html
top_string: TOP
next_url: usageja.html
next_string: Usage
---

# 特徴
K2HDKC PHP Extensionは、Yahoo! JAPANがオープンソースとして公開する[K2HDKC](https://k2hdkc.antpick.ax/indexja.html)を[PHP](https://www.php.net/)から利用するための PHP Extensionライブラリです。

## ネストされたキー構造
**K2HDKC**は、ネストされたキーデータ構造をサポートしています。つまり、**K2HDKC**は、キーと値のペアとネストされたキーと値のペアを格納できます。この機能は、[K2HASH](https://k2hash.antpick.ax/indexja.html)の[Sub key](https://k2hash.antpick.ax/featureja.html)機能から派生したものです。

![Fig.2](images/feature_fig2.png)

## キュー
**K2HDKC**は、[K2HASH](https://k2hash.antpick.ax/indexja.html)の機能でもあるFIFO（先入れ先出し）およびLIFO（後入れ先出し）キューのデータ構造をサポートしています。これは、**K2HDKC**がキューデータ構造に値とキーと値のペアを格納できることを意味します。

## CAS（Compare And Swap）
**K2HDKC**は、[K2HASH](https://k2hash.antpick.ax/indexja.html)と他のmutex機能を使用してCAS（Compare And Swap）操作をサポートします。**K2HDKC**は、キーの現在の値を読み取って期待値と一致するかどうかを確認した後、キーの値を更新します。CAS操作の典型的な使用例は、カウンタをインクリメントまたはデクリメントすること、ミューテックスデータ項目を更新することなどです。

## データ暗号化
**K2HDKC**は、[K2HASH](https://k2hash.antpick.ax/indexja.html)の機能でもあるデータ暗号化をサポートしています。これが**K2HDKC**が機密データを安全に保管して管理できる理由です。

## データの有効期限
**K2HDKC**はデータの有効期限をサポートします。**K2HDKC**は、枯渇した存続時間を持つデータを削除します。この関数の典型的な使用例は、ある種のキャッシュシステムです。**K2HDKC**のデータ有効期限機能は[K2HASH](https://k2hash.antpick.ax/indexja.html)から提供されます。
