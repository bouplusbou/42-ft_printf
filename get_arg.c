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

void    ouXxf_fun(t_struct *t_conv, va_list list)
{
        printf("arg:%p\n", va_arg(list, unsigned int));
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