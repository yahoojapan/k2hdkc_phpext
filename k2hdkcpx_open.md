---
layout: contents
language: en-us
title: k2hdkcpx_open
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: k2hdkcpx_openja.html
lang_opp_word: To Japanese
prev_url: k2hdkcpx_key_queue_put.html
prev_string: k2hdkcpx_key_queue_put
top_url: k2hdkcpx.html
top_string: k2hdkcpx Functions
next_url: k2hdkcpx_queue_get.html
next_string: k2hdkcpx_queue_get
---

# k2hdkcpx_open
Creates a connection to chmpx slave

## Description

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

Creates a connection to chmpx slave.


## Parameters
- config_file  
Specify a chmpx slave configuration file.
- port  
Specify the port that chmpx slave process listens.
- cuk  
Specify the `cuk` string that is a unique string for each node in the cluster.
- rejoin  
Specify `true` when reconnecting with chmpx slave process.
- rejoin_forever  
Specify `true` when reconnecting with chmpx slave process infinitely.
- clear_backup  
Specify `true` when removing the temporary files


## Return Values
Returns the chmpx handle on success or `false` on failure. 

## See Also
- [K2hdkc::__construct](k2hdkc_class_construct.html) - Creates a K2hdkc instance
