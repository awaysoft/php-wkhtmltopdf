#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <string.h>
#include <stdio.h>

#include "php.h"
#include "phpwkhtmltopdf.h"

ZEND_DECLARE_MODULE_GLOBALS(phpwkhtmltopdf)

static zend_function_entry phpwkhtmltopdf_functions[] =
{
    PHP_FE(wkhtmltopdf_convert, NULL)
    {
        NULL, NULL, NULL
    }
};

static int run_cmd(char *cmd, char *result)
{
    FILE *pp;
    int iRet = 0;
    if((pp = popen(cmd, "r")) == NULL)
    {
        strcpy(result, "popen error!");
        return -1;
    }
    fgets(result, 999, pp);
    iRet = pclose(pp);
    return iRet;
}

PHP_MINIT_FUNCTION(phpwkhtmltopdf)
{
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phpwkhtmltopdf)
{
    return SUCCESS;
}

PHP_RINIT_FUNCTION(phpwkhtmltopdf)
{
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(phpwkhtmltopdf)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(phpwkhtmltopdf)
{
    char result[1000] = {0};
    int res = run_cmd("wkhtmltopdf --version", &result);
    php_info_print_table_start();
    php_info_print_table_row(2, "phpwkhtmltopdf", "enabled");
    php_info_print_table_row(2, "phpwkhtmltopdf version", result);
    php_info_print_table_end();
}

zend_module_entry phpwkhtmltopdf_module_entry =
{
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_PHPWKHTMLTOPDF_EXTNAME,
    phpwkhtmltopdf_functions,
    PHP_MINIT(phpwkhtmltopdf),
    PHP_MSHUTDOWN(phpwkhtmltopdf),
    PHP_RINIT(phpwkhtmltopdf),
    PHP_RSHUTDOWN(phpwkhtmltopdf),
    PHP_MINFO(phpwkhtmltopdf),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_PHPWKHTMLTOPDF_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHPWKHTMLTOPDF
ZEND_GET_MODULE(phpwkhtmltopdf)
#endif

/**
 * bool wkhtmltopdf_convert(source, des)
 */
PHP_FUNCTION(wkhtmltopdf_convert)
{
    // used for iterating over the object params
    zval *data;
    HashTable *params_hash;
    HashPosition pointer;
    int params_count;

    // temporarily holds return value
    int ret;

    // source file and des file
    char *source;
    size_t source_len;

    char *des;
    size_t des_len;

    char command[1000] = {0};

    // parse out parameters passed
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss",
                              &source, &source_len, &des, &des_len) == FAILURE)
    {
        RETURN_NULL();
    }

    sprintf(command, "wkhtmltopdf %s %s", source, des);
    ret = system(command);

    RETVAL_BOOL(ret == 0);
}
