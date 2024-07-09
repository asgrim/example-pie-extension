--TEST--
Check if extension works
--SKIPIF--
<?php
if (!extension_loaded('example_pie_extension')) {
  echo 'skip';
}
?>
--FILE--
<?php
example_pie_extension_test();
?>
--EXPECTF--
Hello, %s!
