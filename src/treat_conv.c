/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:46 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/27 16:34:27 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_conv(char *str, int *j, int *len, va_list args)
{
	int		i;
	int		type;

	i = 1;
	type = 0;
	while (str[i] && is_conv(str[i]) && type == 0)
	{
		if (str[i] == '%')
		{
			printf_write(str[i], len);
			*j += i + 1;
			return (-1);
		}
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
