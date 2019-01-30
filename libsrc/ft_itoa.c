/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:50:48 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:46:31 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(int n)
{
	int				len;
	unsigned int	i;

	len = 0;
	if (n < 0)
		i = -n;
	else
		i = n;
	while (i >= 10)
	{
		len++;
		i /= 10;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	i = ft_getlen(n);
	if (n < 0)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	nb = n;
	i--;
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = nb + '0';
	return (str);
}
