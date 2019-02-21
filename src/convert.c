/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudios <bclaudios@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/20 23:55:03 by bclaudios        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	size_printed;

	if (data->type == '%')
		size_printed = conv_perc(data); // return char conversion fonction call
	if (data->type == 'c')
		return (0); // return char conversion fonction call
	if (data->type == 'p')
		return (0); // return pointer conversion fonction call
	if (data->type == 'x' || data->type == 'X')
		size_printed = conv_oux(data, list); // return hexa conversion fonction call
	if (data->type == 's')
		return (0); // return string conversion fonction call
	if (data->type == 'i' || data->type == 'd')
		size_printed = conv_decimal(data, list); // return decimal conversion fonction call
	if (data->type == 'o')
		size_printed = conv_oux(data, list); // return hexa conversion fonction call
	if (data->type == 'u')
		size_printed = conv_oux(data, list); // return hexa conversion fonction call
	if (data->type == 'f')
		size_printed = conv_float(data, list); // return float conversion fonction call
	return (size_printed);
}
