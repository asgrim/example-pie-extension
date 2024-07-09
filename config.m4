dnl config.m4 for extension example_pie_extension

PHP_ARG_ENABLE([example-pie-extension],
  [whether to enable example-pie-extension support],
  [AS_HELP_STRING([--enable-example-pie-extension],
    [Enable example-pie-extension support])],
  [no])

PHP_ARG_WITH([hello-name],
  [hello name],
  [name to use for hello],
  [no],
  [no])

if test "$PHP_EXAMPLE_PIE_EXTENSION" != "no"; then

  MAINTAINER_CFLAGS="-std=gnu99"
  STD_CFLAGS="-g -O0 -Wall"

  PHP_EXAMPLE_PIE_EXTENSION_CFLAGS="-DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 $STD_CFLAGS $MAINTAINER_CFLAGS"

  AC_DEFINE(HAVE_EXAMPLE_PIE_EXTENSION, 1, [ Have extension support ])

  if test "$PHP_HELLO_NAME" == "no"; then
    AC_DEFINE(HELLO_NAME, [ "world" ], [ Hello name ])
  else
    AC_DEFINE_UNQUOTED(HELLO_NAME, [ "$PHP_HELLO_NAME" ], [ Hello name ])
  fi

  PHP_NEW_EXTENSION(
    example_pie_extension,
    zend_example_pie_extension.c,
    $ext_shared,,$PHP_EXAMPLE_PIE_EXTENSION_CFLAGS)
fi

AC_CONFIG_COMMANDS_POST([
  rm -f build/php
  ln -s "$PHP_EXECUTABLE" build/php
])
