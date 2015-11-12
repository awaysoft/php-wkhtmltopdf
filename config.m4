PHP_ARG_WITH(phpwkhtmltopdf, [for libwkhtmltopdf support],
[  --with-phpwkhtmltopdf=[DIR]     Include libwkhtmltopdf support])

if test "$PHP_PHPWKHTMLTOPDF" != "no"; then
    for i in $PHP_PHPWKHTMLTOPDF /usr /usr/local /opt; do
        if test -f $i/bin/wkhtmltopdf; then
            WKHTMLTOX_BIN_DIR=$i/bin
            AC_MSG_RESULT([found in $i]) 
        fi
    done
    
    if test -z "$WKHTMLTOX_BIN_DIR"; then
        AC_MSG_RESULT([not found])
        AC_MSG_ERROR([Please install wkhtmltopdf])
    fi
    
    PHP_NEW_EXTENSION(phpwkhtmltopdf, phpwkhtmltopdf.c, $ext_shared)
fi
