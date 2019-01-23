int    write()
{


}

int     treat_format(const char *format, va_list args)
{
    int len;
    int i;

    len = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
            len += isolate_conv(format + 1, );
        else
        {
            len = i;
               
        }
        i++;
    }
    return (len);
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
    ft_printf("Hello Coco %d\n", 42);
    return (0);
}