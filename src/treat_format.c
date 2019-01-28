/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:38 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/27 16:34:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_format(const char *format, va_list args)
{
	int	len;
	size_t	i;
	int	tmp;

	len = 0;
	i = 0;
	tmp = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			tmp = 0;
			if (0 < (tmp = treat_conv(((char*)format + i), &i, &len, args)))
				len += tmp;
		}
		else
			printf_write(format[i++], &len);
	}
	return (len);
}
