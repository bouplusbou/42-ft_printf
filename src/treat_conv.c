#include "ft_printf.h"

int	treat_conv(char *str, va_list args) // lui envoyer le bout de str à partir du %
{
	int		i;
	int		type; // flag si on trouve bien un type 

	i = 1;
	type = 0;
	while (str[i] && is_conv(str[i]))
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
		return (parse_conv(ft_strndup(str, i), args));
	return (-1); // conv invalide si pas de type
}