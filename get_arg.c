#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"


void    cdi_fun(t_struct *t_conv, va_list list)
{
        printf("arg:%d\n", va_arg(list, int));
        (void)t_conv;
}

void    s_fun(t_struct *t_conv, va_list list)
{
        printf("arg:%s\n", va_arg(list, char*));
        (void)t_conv;
}

void    p_fun(t_struct *t_conv, va_list list)
{
        printf("arg:%p\n", va_arg(list, void*));
        (void)t_conv;
}

void    p_fun(t_struct *t_conv, va_list list)
{
        printf("arg:%p\n", va_arg(list, void*));
        (void)t_conv;
}

int     type_id(char c)
{
    if (c == 'c' || c == 'd' || c = 'i')
        return (0);
    if (c == 's')
        return (1);
    if (c == 'p')
        return (2);
    return (-1);
}

void    get_arg(t_struct *t_conv, va_list args)
{
    void (*fun_arr[3])(t_struct*, va_list) = {cdi_fun, s_fun, p_fun};
    
    (*fun_arr[type_id(t_conv->type)])(t_conv, args); // quand meme oblige d'utiliser une foret de if....
}
 

int     ft_printf(const char *format, ...)
{
    t_struct    t_conv;
    
    t_conv.type = 'p';
    va_list args;
    va_start(args, format);
    get_arg(&t_conv, args);    
    va_end(args);
    return (0); // return the number of char printed (without the `\0') OR a negative value if an error occurs
}

int main()
{
    ft_printf("Hello Bro", 156, 123);
    return (0);
}