/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudios <bclaudios@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 01:50:09 by bclaudios         #+#    #+#             */
/*   Updated: 2019/02/01 01:51:13 by bclaudios        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		find_value(int index, const char *basestr)
{
	return (basestr[index]);
}

static size_t	find_result_size(unsigned long long nbr, int base)
{
	size_t			size;

	size = 0;
	while (nbr / base)
	{
		size++;
		nbr /= base;
	}
	return (size + 1);
}

char			*ft_ulltoa_base(unsigned long long nbr, const char *basestr)
{
	char			*result;
	int				resultlen;
	int				base;

	base = ft_strlen(basestr);
	resultlen = find_result_size(nbr, base);
	if (!(result = ft_strnew(resultlen)))
		return (NULL);
	resultlen--;
	while (nbr >= (unsigned long long)base)
	{
		result[resultlen--] = find_value(nbr % base, basestr);
		nbr /= base;
	}
	result[resultlen] = find_value(nbr, basestr);
	return (result);
}
