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
    convert();
    return (0);
}