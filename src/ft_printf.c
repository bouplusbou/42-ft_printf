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

int main()
{
    ft_printf("Conv here -> %s <- just here\n", 42);
    // printf("return de ft_printf: %d\n", ft_printf("Conv here -> %%d %s <- just here\n", 42)); //tester avec %d en fin de str
    return (0);
}