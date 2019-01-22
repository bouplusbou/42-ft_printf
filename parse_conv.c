#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
			|| c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f');
}

int		is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-'
			|| c == '+' || c == ' ');
}

int		is_width(char c)
{
	return ('1' <= c && c <= '9');
}

int		is_precision(char c)
{
	return (c == '.' || ('0' <= c && c <= '9'));
}

int		is_size(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		is_percent(char c)
{
	return (c == '%');
}

int		is_conv(char c)
{
	return (is_type(c) || is_percent(c) || is_flag(c) || is_width(c) || is_precision(c));
}

int	ft_isspace(char c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\v'
			|| c == '\n'
			|| c == '\r'
			|| c == '\f');
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	int	neg;
	int	res;

	while (ft_isspace(*s))
		s++;
	neg = (*s == '-');
	if (*s == '-' || *s == '+')
		s++;
	res = 0;
	while (ft_isdigit(*s))
	{
		res *= 10;
		res += (*s - '0');
		s++;
	}
	return (neg ? -res : res);
}



char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    *parse_flags(char *str_flags, int *i)
{
    int l;

    l = 0;
    while (is_flag(str_flags[l]))
        l++;
    *i += l;
    return (ft_strndup(str_flags, l));
}

int     parse_width(char *str_width, int *i)
{
    int l;

    l = 0;
    while (is_width(str_width[l]))
        l++;
    *i += l;
    return (ft_atoi(ft_strndup(str_width, l)));
}

int     parse_precision(char *str_precision, int *i)
{
    int l;

    l = 1;
    while (is_precision(str_precision[l]))
        l++;
    *i += l;
    return (ft_atoi(ft_strndup(str_precision + 1, l)));
}

char    *parse_size(char *str_size, int *i)
{
    int l;

    l = 0;
    while (is_size(str_size[l]))
        l++;
    *i += l;
    return (ft_strndup(str_size, l));
}

t_struct parse_conv(char *conv)
{
    t_struct    t_conv;
    int         i;

    i = 1;
    if (is_flag(conv[i]))
        t_conv.flags = parse_flags(conv + i, &i);
    if (is_width(conv[i]))
        t_conv.width = parse_width(conv + i, &i);
    if (conv[i] == '.')
        t_conv.precision = parse_precision(conv + i, &i);
    if (conv[i])
        t_conv.size = parse_size(conv + i, &i);
    if (is_type(conv[i]))
            t_conv.type = conv[i];
    
    printf("%s\n", t_conv.flags);
    printf("%d\n", t_conv.width);
    printf("%d\n", t_conv.precision);
    printf("%s\n", t_conv.size);
    printf("%c\n", t_conv.type);
    return (t_conv);
}

int main()
{
    parse_conv("%#-+ 132.23lls");
    return (0);
}