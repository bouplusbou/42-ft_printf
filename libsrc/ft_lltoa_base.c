/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudios <bclaudios@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:13:56 by bclaudios         #+#    #+#             */
/*   Updated: 2019/02/01 01:26:38 by bclaudios        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		find_value(int index, const char *basestr)
{
	return (basestr[index]);
}

static size_t	find_result_size(long long int nbr, int base)
{
	size_t					size;
	unsigned long long int	nb;

	size = 0;
	nb = nbr < 0 ? -nbr : nbr;
	while (nb / base)
	{
		size++;
		nb /= base;
	}
	return (size + 1);
}

char			*ft_lltoa_base(long long int nbr, const char *basestr)
{
	char					*result;
	int						resultlen;
	int						base;
	unsigned long long int	nb;

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
	while (nb >= (unsigned long long)base)
	{
		result[resultlen--] = find_value(nb % base, basestr);
		nb /= base;
	}
	result[resultlen] = find_value(nb, basestr);
	return (result);
}
