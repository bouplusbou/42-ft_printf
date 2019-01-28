/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:28 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/28 18:49:14 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** return the number of char printed (without the `\0')
** OR a negative value if an error occurs
*/

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = treat_format(format, args);
	va_end(args);
	return (ret);
}
