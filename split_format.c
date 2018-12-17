/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:53:40 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/17 18:49:03 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	split_format(char *str)
{
	int		tab[50];
	char	*tmp;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (str[i + 1])
	{
		printf("str[%i]: %c\n", i, str[i]);
		if (str[i] == '%' && str[i + 1] != '%')
		{
			tab[j++] = i;
			count++;
		}
		i++;
	}
	printf("count: %i\n", count);
	j = 0;
	while (j < count - 1)
	{
		printf("tab[%i]: %i\n", j, tab[j]);
		j--;
	}

}

int	main(int argc, char **argv)
{
	split_format(argv[1]);
	return (argc);
}
