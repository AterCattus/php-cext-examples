php-cext-examples
=================

Examples of C extensions for PHP:

* error_clear_last() function for clearing error_get_last().

### Build (linux):
~~~
# phpize && ./configure && make && make test
$ make install
# make clean; phpize --clean
~~~
And enable the extension in php.ini via "extension=/path/to/extension.so"
