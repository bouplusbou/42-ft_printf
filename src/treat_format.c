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
            if (0 < (tmp = treat_conv(((char*)format + i), args)))
            {
                len += tmp;
                tmp = 0;
                while (!is_type(format[i - 1])) // avancer i après la conv
                    i++;
            }
        }
        write(1, &format[i], 1);
        len++;
        i++;
    }
    return (len); // retourner le nombre de char printed
}