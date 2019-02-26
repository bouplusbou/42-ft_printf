/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:38 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/26 14:16:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_format(const char *format, va_list list)
{
	int		len;
	size_t	i;
	int		tmp;

	len = 0;
	i = 0;
	tmp = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			tmp = 0;
			if (0 < (tmp = treat_conv(((char*)format + i), &i, &len, list)))
				len += tmp;
		}
		if (format[i] == '{')
			treat_color(((char*)format + i), &i);
		else
			printf_write(format[i++], &len);
	}
	return (len);
}
