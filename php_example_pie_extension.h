/* Example extension for PHP */

#ifndef PHP_EXAMPLE_PIE_EXTENSION_H
# define PHP_EXAMPLE_PIE_EXTENSION_H

extern zend_module_entry example_pie_extension_module_entry;
# define phpext_example_pie_extension_ptr &example_pie_extension_module_entry

# define PHP_EXAMPLE_PIE_EXTENSION_VERSION "2.0.4"

# if defined(ZTS) && defined(COMPILE_DL_EXAMPLE_PIE_EXTENSION)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

ZEND_BEGIN_MODULE_GLOBALS(example_pie_extension)
        zend_long scale;
                ZEND_END_MODULE_GLOBALS(example_pie_extension)

ZEND_EXTERN_MODULE_GLOBALS(example_pie_extension)

#define EXAMPLE_PIE_EXTENSION_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(example_pie_extension, v)

#endif	/* PHP_EXAMPLE_PIE_EXTENSION_H */
