#include "ft_printf.h"

int		get_color(char *str, size_t len)
{
	int is_color;

	is_color = 0;
	if (!len)
		return (0);
	else if ((is_color = !ft_strncmp("red", str, len)))
		ft_putstr("\033[31m");
	else if ((is_color = !ft_strncmp("green", str, len)))
		ft_putstr("\033[32m");
	else if ((is_color = !ft_strncmp("yellow", str, len)))
		ft_putstr("\033[33m");
	else if ((is_color = !ft_strncmp("blue", str, len)))
		ft_putstr("\033[34m");
	else if ((is_color = !ft_strncmp("magenta", str, len)))
		ft_putstr("\033[35m");
	else if ((is_color = !ft_strncmp("white", str, len)))
		ft_putstr("\033[m");
	else if ((is_color = !ft_strncmp("bold", str, len)))
		ft_putstr("\e[1m");
	else if ((is_color = !ft_strncmp("underline", str, len)))
		ft_putstr("\e[4m");
	else if ((is_color = !ft_strncmp("eof", str, len)))
		ft_putstr("\e[0m");
	return (is_color);
}

void	treat_color(char *str, size_t *j, int *len)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (str[i] && end == 0)
	{
		if (str[i] == '}')
			end = 1;
		i++;
	}
	if (end)
	{
		if (get_color(str + 1, i - 2))
		{
			*j += i;
			return ;
		}
	}
	printf_write('{', len);
	*j += 1;
}
