/* Example extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_example_pie_extension.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

ZEND_DECLARE_MODULE_GLOBALS(example_pie_extension)

/* {{{ void example_pie_extension_test()
 */
PHP_FUNCTION(example_pie_extension_test)
{
    ZEND_PARSE_PARAMETERS_NONE();

    php_printf("Hello2!\r\n");
}
/* }}} */

static PHP_GINIT_FUNCTION(example_pie_extension)
{
#if defined(COMPILE_DL_BCMATH) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    example_pie_extension_globals->scale= 1;
}

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(example_pie_extension)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "example pie extension support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_example_pie_extension_test, 0)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ example_pie_extension_functions[]
 */
static const zend_function_entry example_pie_extension_functions[] = {
        PHP_FE(example_pie_extension_test,		arginfo_example_pie_extension_test)
        PHP_FE_END
};
/* }}} */

/* {{{ example_pie_extension_module_entry
 */
zend_module_entry example_pie_extension_module_entry = {
        STANDARD_MODULE_HEADER,
        "example-pie-extension",					/* Extension name */
        example_pie_extension_functions,			/* zend_function_entry */
        NULL,				/* PHP_MINIT - Module initialization */
        NULL,							/* PHP_MSHUTDOWN - Module shutdown */
        NULL,							/* PHP_RINIT - Request initialization */
        NULL,							/* PHP_RSHUTDOWN - Request shutdown */
        PHP_MINFO(example_pie_extension),			/* PHP_MINFO - Module info */
        PHP_EXAMPLE_PIE_EXTENSION_VERSION,		/* Version */
        PHP_MODULE_GLOBALS(example_pie_extension),	/* Module globals */
        PHP_GINIT(example_pie_extension),			/* PHP_GINIT - Globals initialization */
        NULL,					/* PHP_GSHUTDOWN - Globals shutdown */
        NULL,
        STANDARD_MODULE_PROPERTIES_EX
};
/* }}} */

#ifdef COMPILE_DL_EXAMPLE_PIE_EXTENSION
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(example_pie_extension)
#endif
