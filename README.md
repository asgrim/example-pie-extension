# Example PIE extension

This an example PHP module that can be installed using PIE.

## Build it

### Linux

The usual process applies...

```
PHPIZE=/usr/bin/phpize7.1
PHP_CONFIG=/usr/bin/php-config7.1
make clean
$PHPIZE --clean
$PHPIZE --force
./configure --enable-example-pie-extension --with-php-config=$PHP_CONFIG
make
make test
```

### Windows

TBC
