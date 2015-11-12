#ifndef PHP_PHPWKHTMLTOPDF_H
#define PHP_PHPWKHTMLTOPDF_H

#define PHP_PHPWKHTMLTOPDF_VERSION "0.12"
#define PHP_PHPWKHTMLTOPDF_EXTNAME "phpwkhtmltopdf"

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(phpwkhtmltopdf)
ZEND_END_MODULE_GLOBALS(phpwkhtmltopdf)

#ifdef ZTS
#define PHPWKHTMLTOPDF_G(v) TSRMG(phpwkhtmltopdf_globals_id, zend_phpwkhtmltopdf_globals *, v)
#else
#define PHPWKHTMLTOPDF_G(v) (phpwkhtmltopdf_globals.v)
#endif

PHP_FUNCTION(wkhtmltopdf_convert);

extern zend_module_entry phpwkhtmltopdf_module_entry;
#define phpext_phpwkhtmltopdf_ptr &phpwkhtmltopdf_module_entry

#endif
