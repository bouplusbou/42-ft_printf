#include <stdio.h>
#include <stdlib.h>

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

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
			|| c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f');
}

int		is_conv(char c)
{
	return (is_flag(c) || is_width(c) || is_precision(c) || is_size(c) || is_type(c));
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


char	*isolate_conv(char *str) // lui envoyer le bout de str à partir du %
{
	int		i;
	int		type; // flag si on trouve bien un type 

	i = 1;
	type = 0;
	while (is_conv(str[i]))
	{
		if (is_type(str[i]))
		{
			i++;
			type = 1;
			break ;
		}
		i++;
	}
	if (type)
		return (ft_strndup(str, i));
	return (NULL); // conv invalide si pas de type
}

int main()
{
    printf("isolate_conv:%s\n", isolate_conv("%#-+ 132.23lls petit bout"));
    printf("isolate_conv:%s\n", isolate_conv("%s petit bout"));
    printf("isolate_conv:%s\n", isolate_conv("%#-+ 132.23ll etit bout"));
    return (0);
}