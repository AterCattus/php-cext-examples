PHP_ARG_ENABLE(errorclearlast, Enable error_clear_last() function)

if test "$PHP_ERRORCLEARLAST" = "yes"; then
    AC_DEFINE(HAVE_ERRORCLEARLAST, 1, [You have error_clear_last extension])

    errorclearlast_sources="errorclearlast.c"

    PHP_NEW_EXTENSION(errorclearlast, $errorclearlast_sources, $ext_shared)
fi
