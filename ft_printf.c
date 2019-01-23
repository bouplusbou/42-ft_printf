#include "ft_printf.h"

int     treat_format(const char *format, va_list args)
{
    int len; // compter le nombre de char printed
    int i;
    int tmp;

    len = 0;
    i = 0;
    tmp = 0;

    /* parcours format, si pas %, write, si % envoie à isolate_conv */
    while (format[i])
    {
        if (format[i] == '%' && format[i - 1] != '%')
        {
            /* si la conv est valide (>= 0), retourner le nombre de char printed 
            dans tmp et pas directement dans len, si jamais retour negatif*/
            if (0 < (tmp = isolate_conv((char*)format + i))) 
            {
                len += tmp;
                tmp = 0;
                while (!is_type(format[i - 1])) // avancer i après la conv
                    i++;
            }
        }
        write(1, &format[i], 1);
        len++;;
        i++;
    }
    return (len); // retourner le nombre de char printed
}

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
    printf("return de ft_printf: %d\n", ft_printf("Conv here -> %%d %s <- just here\n", 42)); //tester avec %d en fin de str
    return (0);
}