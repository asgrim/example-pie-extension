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

#### Prepare Windows build environment:

- Read this guide to put below into context: https://wiki.php.net/internals/windows/stepbystepbuild_sdk_2
- Read this guide to help get the environment set up: https://gist.github.com/cmb69/47b8c7fb392f5d79b245c74ac496632c
- PHP Binary tools - use https://github.com/php/php-sdk-binary-tools (**not** the Microsoft one as it is not maintained)
- Once the VS tools + php-sdk-binary-tools is installed, everything is done in this shell:
    - Start > `Developer Command Prompt for VS 2019`
    - Then `cd C:\php-sdk`
    - Then `phpsdk-vs16-x64.bat` - you should now have a prompt `$ `
- Install PHP from https://windows.php.net/download/
    - Download, e.g. ZTS build, https://windows.php.net/downloads/releases/php-8.3.6-Win32-vs16-x64.zip
    - Extract into `C:\php` for example
- Prepare to compile the ext
    - Download "Development package" from https://windows.php.net/download/ - make sure TS/NTS depending on above compilation
        - e.g. https://windows.php.net/downloads/releases/php-devel-pack-8.3.6-Win32-vs16-x64.zip
    - Extract to `C:\php-sdk\php-8.3.6-devel-vs16-x64`
    - Add `C:\php-sdk\php-8.3.6-devel-vs16-x64` to your PATH (Start > `env` > Environment variables > "Path" > New)
    - restart the shell

#### Compile the extension

```
phpize
configure --enable-example-pie-extension --enable-debug --with-php-build="C:\php-sdk\phpdev\vs16\x64\deps" --with-prefix="C:\php\"
nmake
nmake run ARGS="-m"
```
