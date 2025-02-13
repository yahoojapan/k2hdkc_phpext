k2hdkc php extension
====================
[![PHP AntPickax CI](https://github.com/yahoojapan/k2hdkc_phpext/workflows/PHP%20AntPickax%20CI/badge.svg)](https://github.com/yahoojapan/k2hdkc_phpext/actions)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/yahoojapan/k2hdkc_phpext/master/LICENSE)
[![GitHub forks](https://img.shields.io/github/forks/yahoojapan/k2hdkc_phpext.svg)](https://github.com/yahoojapan/k2hdkc_phpext/network)
[![GitHub stars](https://img.shields.io/github/stars/yahoojapan/k2hdkc_phpext.svg)](https://github.com/yahoojapan/k2hdkc_phpext/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/yahoojapan/k2hdkc_phpext.svg)](https://github.com/yahoojapan/k2hdkc_phpext/issues)
[![RPM packages](https://img.shields.io/badge/rpm-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)
[![debian packages](https://img.shields.io/badge/deb-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)
[![ALPINE packages](https://img.shields.io/badge/apk-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)

- K2HDKC PHP Extension library  
K2HDKC is NoSQL Key Value Store(KVS) library by Yahoo! JAPAN.

### Overview
K2HDKC is a free and open-source distributed KVS(Key Value Store) clustering system created in Yahoo! JAPAN.
This PHP Extension library is for using K2HDKC from PHP.  

By [K2HDKC PHP Extension](https://php.k2hdkc.antpick.ax/) library, you can easily incorporate the functions and features of K2HDKC into PHP based programs.  
For the features and functions of K2HDKC, see the [k2hdkc documentation](https://k2hdkc.antpick.ax/).  

![k2HASH PHP Extension](https://php.k2hdkc.antpick.ax/images/top_k2hdkc_phpext.png)

### Usage
K2HDKC PHP Extension library is provided as RPM and Debian package.  
Before installing this package, you need the K2HDKC package(RPM or Debian).  
First of all, please install the k2hdkc developer package as described [here](https://k2hdkc.antpick.ax/usage.html).  
Next, install the K2HDKC PHP Extension library using the package manager command.  

- Debian based Linux users can install it by following the steps below:  
```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.4 libapache2-mod-php8.4
$ sudo update-alternatives --set php-config /usr/bin/php-config8.4
$ sudo update-alternatives --set php /usr/bin/php8.4
$ sudo apt-get install -y k2hdkc php-pecl-k2hdkc
```
- Fedora derived RPM based Linux(Fedora, CentOS, CentOS Stream, RHEL, etc.) users can install it by following the steps below:
```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-9.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.4
$ sudo dnf install -y php-pecl-k2hdkc
```
- ALPINE based Linux users can install it by following the steps below:
```
# apk update

# curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.alpine.sh | sh

# apk add php84 php84-dev php84-tokenizer
$ apk add php84-pecl-k2hdkc
```

### Documents
- [Document top page](https://php.k2hdkc.antpick.ax/)
- [Github wiki page](https://github.com/yahoojapan/k2hdkc_phpext/wiki)
- [About K2HDKC](https://k2hdkc.antpick.ax/)
- [About AntPickax](https://antpick.ax/)

### Packages
- [RPM packages(packagecloud.io)](https://packagecloud.io/app/antpickax/stable/search?q=php&filter=rpm&filter=rpm&dist=&arch=)
- [Debian packages(packagecloud.io)](https://packagecloud.io/app/antpickax/stable/search?q=php&filter=deb&dist=&arch=)
- [ALPINE packages(packagecloud.io)](https://packagecloud.io/app/antpickax/stable/search?q=php&filter=alpine&dist=&arch=)

### License
This software is released under the MIT License, see the license file.

### AntPickax
K2HDKC PHP Extension is one of [AntPickax](https://antpick.ax/) products.

Copyright(C) 2023 Yahoo Japan Corporation.
