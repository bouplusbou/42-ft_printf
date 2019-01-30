/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:20:10 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/12 11:31:08 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	fts_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		fts_putchar('-');
		n = -n;
	}
	nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		fts_putchar(nbr % 10 + '0');
	}
	else
		fts_putchar(nbr + '0');
}
