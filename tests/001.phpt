--TEST--
Check if extension works
--SKIPIF--
<?php
if (!extension_loaded('example-pie-extension')) {
  echo 'skip';
}
?>
--FILE--
<?php
example_pie_extension_test();
?>
--EXPECT--
Hello!
