/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/21 15:15:07 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	size_printed;

	size_printed = 0;
	if (data->type == '%')
		return (0); // return char conversion fonction call
	if (data->type == 'c')
		return (0); // return char conversion fonction call
	if (data->type == 'p')
		return (0); // return pointer conversion fonction call
	if (data->type == 'x' || data->type == 'X')
		return (0); // return hexa conversion fonction call
	if (data->type == 's')
		return (0); // return string conversion fonction call
	if (data->type == 'i' || data->type == 'd')
		return (0); // return decimal conversion fonction call
	if (data->type == 'o')
		return (0); // return hexa conversion fonction call
	if (data->type == 'u')
		return (0); // return hexa conversion fonction call
	if (data->type == 'f')
		size_printed = conv_float(data, list); // return float conversion fonction call
	return (size_printed);
}
