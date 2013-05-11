--TEST--
error_clear_last() usage example
--SKIPIF--
<?php if (!extension_loaded('error_clear_last')) echo "skip"; ?>
--FILE--
<?php
@substr(); // Warning: substr() expects at least 2 parameters, 0 given in %s on line %d
var_dump(is_array(error_get_last()));
error_clear_last();
var_dump(is_array(error_get_last()));
?>
--EXPECTF--
bool(true)
bool(false)
