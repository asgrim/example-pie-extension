--TEST--
Check extension is installed
--FILE--
<?php
var_dump(extension_loaded('example-pie-extension'));
?>
--EXPECT--
bool(true)
