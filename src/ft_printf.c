#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int ret;
    va_list args;

    va_start(args, format);
    ret = treat_format(format, args);
    va_end(args);
    return (ret); // return the number of char printed (without the `\0') OR a negative value if an error occurs
}