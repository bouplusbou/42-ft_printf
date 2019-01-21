/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:53:40 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/19 17:41:26 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	return (c == '1'
			|| c == '2' || c == '3' || c == '4'
			|| c == '5' || c == '6' || c == '7'
			|| c == '8' || c == '9');
}

int		is_precision(char c)
{
	return (c == '.' || c == '0' || c == '1'
			|| c == '2' || c == '3' || c == '4'
			|| c == '5' || c == '6' || c == '7'
			|| c == '8' || c == '9');
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

char	*malloc_str(char *str)
{
	int		i;
	int		l;
	char	*ret;

	l = 0;
	while (!is_percent(str[l]))
		l++;
	if (!(ret = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (!is_percent(str[i]))
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*malloc_conv(char *conv)
{
	int		i;
	int		l;
	char	*ret;

	l = 0;
	while (!is_type(conv[l]))
		l++;
	if (!(ret = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (!is_type(conv[i - 1]))
	{
		ret[i] = conv[i];
		i++;
	}
	conv[i] = '\0';
	return (conv);
}

void	split_format(char *str)
{
	char	*tab[50] = {NULL};
	char	*tmp;
	int		count;
	int		i;
	int		j;

	printf("%s", str);
}

int	main(int argc, char **argv)
{
	split_format(argv[1]);
	return (argc);
}
