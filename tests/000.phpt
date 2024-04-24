--TEST--
Check extension is installed
--FILE--
<?php
var_dump(extension_loaded('example_pie_extension'));
?>
--EXPECT--
bool(true)
