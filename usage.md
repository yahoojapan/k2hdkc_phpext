---
layout: contents
language: en-us
title: Usage
short_desc: K2HDKC PHP Extension - PHP Extension library for K2HDKC
lang_opp_file: usageja.html
lang_opp_word: To Japanese
prev_url: feature.html
prev_string: Feature
top_url: index.html
top_string: TOP
next_url: developer.html
next_string: Developer
---

# Usage
This page describes how to build the K2HDKC PHP driver and install it and use it.

## 1. Install
Debian based Linux users can install it by following the steps below:

```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.4 libapache2-mod-php8.4
$ sudo update-alternatives --set php-config /usr/bin/php-config8.4
$ sudo update-alternatives --set php /usr/bin/php8.4
$ sudo apt-get install -y k2hdkc php-pecl-k2hdkc
```

RPM-based Linux distributions users, follow the steps below:

```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-8.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.4
$ sudo dnf install -y php-pecl-k2hdkc
```

ALPINE-based Linux distributions users, follow the steps below:
```
# apk update

# curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.alpine.sh | sh

# apk add php83 php83-dev php83-tokenizer
$ apk add php83-pecl-k2hdkc
```

## 2. Test

Firstly clone the GitHub repository.
```
$ git clone https://github.com/yahoojapan/k2hdkc_phpext.git
```

Run a CHMPX server daemon process.
```
$ chmpx -conf ./k2hdkc_phpext/tests/server.ini &
```

Run a CHMPX slave daemon process.
```
$ chmpx -conf ./k2hdkc_phpext/tests/slave.ini &
```

Run a K2HDKC damon process.
```
$ k2hdkc -conf ./k2hdkc_phpext/tests/slave.ini &
```

Run a PHP client application and save a pair of key/value.
```
$ php -r '
> $handle = new K2hdkc("./k2hdkc_phpext/tests/slave.ini");
> $handle->setValue("key1", "val1");
> echo $handle->getValue("key1");
'
```

The above example will output something similar to:
```
val1
```

