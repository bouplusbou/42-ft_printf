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
int     isolate_conv(char *str);
int		is_type(char c);