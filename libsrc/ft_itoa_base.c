/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:14:48 by bclaudio          #+#    #+#             */
/*   Updated: 2019/01/31 13:32:14 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		find_value(int index, const char *basestr)
{
	return (basestr[index]);
}

static size_t	find_result_size(int nbr, int base)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	nb = nbr < 0 ? -nbr : nbr;
	while (nb / base)
	{
		size++;
		nb /= base;
	}
	return (size + 1);
}

char			*ft_itoa_base(int nbr, const char *basestr)
{
	char			*result;
	int				resultlen;
	unsigned int	base;
	unsigned int	nb;

	base = ft_strlen(basestr);
	resultlen = find_result_size(nbr, base);
	resultlen += nbr < 0 && base == 10 ? 1 : 0;
	if (!(result = ft_strnew(resultlen)))
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		if (base == 10)
			result[0] = '-';
	}
	nb = nbr;
	resultlen--;
	while (nb >= base)
	{
		result[resultlen--] = find_value(nb % base, basestr);
		nb /= base;
	}
	result[resultlen] = find_value(nb, basestr);
	return (result);
}
