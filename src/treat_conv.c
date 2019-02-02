/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:46 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/02 14:59:25 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_conv(char *str, size_t *j, int *len, va_list args)
{
	size_t		i;
	int		type;

	i = 1;
	type = 0;
	while (str[i] && is_conv(str[i]) && type == 0)
	{
		if (is_type(str[i]))
			type = 1;
		i++;
	}
	if (type)
	{
		*j += i;
		return (parse_conv(ft_strndup(str, i), args));
	}
	printf_write('%', len);
	*j += 1;
	return (-1);
}
