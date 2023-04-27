---
layout: contents
language: ja
title: k2hdkcpx_open
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_open.html
lang_opp_word: To English
prev_url: k2hdkcpx_key_queue_putja.html
prev_string: k2hdkcpx_key_queue_put
top_url: k2hdkcpxja.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_queue_getja.html
next_string: k2hdkcpx_queue_get
---

# k2hdkcpx_open
chmpxスレーブノードへ接続する

## 説明

```

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
```


## パラメータ
- config_file  
chmpxスレーブの設定ファイルのパスを指定してください。
- port  
chmpxスレーブプロセスがlistenしているポート番号を指定してください。
- cuk  
chmpxスレーブプロセスの `cuk` 文字列を指定してください。
- rejoin  
chmpxスレーブプロセスに再接続する場合は、 `true` を指定してください。
- rejoin_forever  
chmpxスレーブプロセスに継続的に再接続する場合は、 `true` を指定してください。
- clear_backup  
chmpxスレーブプロセスとの接続を切る時に、一時ファイルを削除する場合は、 `true` を指定してください。


## 戻り値
成功時はchmpxスレーブプロセスとの接続ハンドル、失敗時は `false` を返します。

## 参考
- [K2hdkc::__construct](k2hdkc_class_constructja.html) - K2hdkcインスタンスを作成する
