#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/* A supprimer */
#include <stdio.h>

typedef struct  s_struct
{
    char    *flags;
    int     width;
    int     precision;
    char    *size;
    char    type;
}               t_struct;

int     treat_format(const char *format, va_list args);
int     treat_conv(char *str, va_list args);
int		is_type(char c);
char	*ft_strndup(const char *s1, int len);
int     parse_conv(char *conv, va_list args);
int		is_flag(char c);
int		is_width(char c);
int		is_precision(char c);
int		is_size(char c);
int		is_type(char c);
int		is_conv(char c);
int     ft_atoi(const char *s);
int     convert(t_struct t_conv, va_list args);