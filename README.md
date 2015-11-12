A simple extension to convert html to pdf, need wkhtmltopdf

Special thanks to antialize for creating [wkhtmltopdf](http://wkhtmltopdf.org)


### Installation

    $ phpize
    $ ./configure
    $ make install

edit your `php.ini` and add:

    extension=phpwkhtmltopdf.so

### Tested on:

 * CentOS 7, PHP 7.0 RC6 (64-bit)

### Pre-requisites on all platforms:

 * you need `wkhtmltopdf` somewhere in your bin path (`/usr/local/bin`)

