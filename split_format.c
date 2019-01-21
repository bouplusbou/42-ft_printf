/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:53:40 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/21 15:03:21 by bboucher         ###   ########.fr       */
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
	ret[i] = '\0';
	printf("malloc_conv: %s\n", ret);
	return (ret);
}

char	*malloc_str(char *str)
{
	int		i;
	int		l;
	char	*ret;

	printf("malloc_str//str:%s\n", str);
	l = 0;
	while (str[l] != '%')
		l++;
//	printf("malloc_str//l:%d\n", l);
	if (!(ret = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '%')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	printf("malloc_str//ret:%s\n", ret);
	return (ret);
}

int		conv_size(char *conv)
{
	int	i;

	printf("conv:%s\n", conv);
	i = 0;
	while (!is_type(conv[i]))
		i++;
	printf("conv_size:%d\n", i);
	return (i + 1);
}


void	split_format(char *str)
{
	char	*tab[50];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
		{	
			tab[k] = malloc_str(str + j);
			j = i + conv_size(str + i);
			printf("j:%d\n", j);
			k++;
			tab[k] = malloc_conv(str + i);
			k++;
			i += conv_size(str + i) - 1;
			printf("i:%d\n", i);
		}
		i++;
	}
	if (str[j])
		tab[k] = malloc_str(str + j);
	k = 0;
//	while (k != 3)
//	{
//		printf("tab[%d]:%s\n", k, tab[k]);
//		k++;
//	}
}

int	main()
{
	split_format("%-3.2s %s Loulou\n");
	return (0);
}
