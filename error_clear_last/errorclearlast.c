#include "errorclearlast.h"
#include "php.h"

PHP_FUNCTION(error_clear_last);

const zend_function_entry errorclearlast_functions[] = {
    ZEND_FE(error_clear_last, NULL)

    ZEND_FE_END
};

PHP_RINIT_FUNCTION(errorclearlast);

zend_module_entry errorclearlast_module_entry = {
    STANDARD_MODULE_HEADER,
    ERRORCLEARLAST_EXT_NAME,
    errorclearlast_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    ERRORCLEARLAST_EXT_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(errorclearlast)

/* {{{ proto void error_clear_last()
 */
PHP_FUNCTION(error_clear_last)
{
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "") == FAILURE) {
        return;
    }

    PG(last_error_type) = 0;
    PG(last_error_lineno) = 0;
    if (PG(last_error_message)) {
        free(PG(last_error_message));
        PG(last_error_message) = NULL;
    }
    if (PG(last_error_file)) {
        free(PG(last_error_file));
        PG(last_error_file) = NULL;
    }
}
/* }}} */
