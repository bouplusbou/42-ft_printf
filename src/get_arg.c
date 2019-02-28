/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:08:21 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/28 10:43:14 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_arg_boux(t_struct data, va_list list)
{
	uintmax_t arg;

	arg = 0;
	if (data.type == 'U')
		arg = va_arg(list, unsigned long);
	else if (!data.size)
		arg = va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "j"))
		arg = va_arg(list, uintmax_t);
	else if (ft_strstr(data.size, "ll"))
		arg = va_arg(list, unsigned long long int);
	else if (ft_strstr(data.size, "l"))
		arg = va_arg(list, unsigned long int);
	else if (ft_strstr(data.size, "z"))
		arg = (size_t)va_arg(list, unsigned long long int);
	else if (ft_strstr(data.size, "h") && !ft_strstr(data.size, "hh"))
		arg = (unsigned short int)va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "hh"))
		arg = (unsigned char)va_arg(list, unsigned int);
	return (arg);
}

long double	get_arg_float(t_struct data, va_list list)
{
	long double arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, double);
	else if (ft_strstr(data.size, "L"))
		arg = va_arg(list, long double);
	return (arg);
}

intmax_t	get_arg_decimal(t_struct data, va_list list)
{
	intmax_t	arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, int);
	else if (ft_strstr(data.size, "j"))
		arg = va_arg(list, intmax_t);
	else if (ft_strstr(data.size, "ll"))
		arg = va_arg(list, long long int);
	else if (ft_strstr(data.size, "l"))
		arg = va_arg(list, long int);
	else if (ft_strstr(data.size, "z"))
		arg = (ssize_t)va_arg(list, long long int);
	else if (ft_strstr(data.size, "h") && !ft_strstr(data.size, "hh"))
		arg = (short int)va_arg(list, int);
	else if (ft_strstr(data.size, "hh"))
		arg = (signed char)va_arg(list, int);
	return (arg);
}
