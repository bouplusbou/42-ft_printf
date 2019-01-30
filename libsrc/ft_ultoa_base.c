/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:51 by bclaudio          #+#    #+#             */
/*   Updated: 2019/01/28 18:55:53 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		find_value(int index, const char *basestr)
{
	return (basestr[index]);
}

static size_t	find_result_size(unsigned long nbr, int base)
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

char			*ft_ultoa_base(unsigned long nbr, const char *basestr)
{
	char			*result;
	int				resultlen;
	int				base;

	base = ft_strlen(basestr);
	resultlen = find_result_size(nbr, base);
	if (!(result = ft_strnew(resultlen)))
		return (NULL);
	resultlen--;
	while (nbr > 0)
	{
		result[resultlen--] = find_value(nbr % base, basestr);
		nbr /= base;
	}
	return (result);
}
