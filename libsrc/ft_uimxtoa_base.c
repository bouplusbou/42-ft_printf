/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:51:00 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/28 14:28:27 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		find_value(int index, const char *basestr)
{
	return (basestr[index]);
}

static size_t	find_result_size(uintmax_t nbr, int base)
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

char			*ft_uimxtoa_base(uintmax_t nbr, const char *basestr)
{
	char			*result;
	int				resultlen;
	int				base;

	base = ft_strlen(basestr);
	resultlen = find_result_size(nbr, base);
	if (!(result = ft_strnew(resultlen)))
		return (NULL);
	resultlen--;
	while (nbr >= (uintmax_t)base)
	{
		result[resultlen--] = find_value(nbr % base, basestr);
		nbr /= base;
	}
	result[resultlen] = find_value(nbr, basestr);
	return (result);
}
