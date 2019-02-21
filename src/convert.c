/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/21 17:17:45 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	size_printed;

	size_printed = 0;
	if (data->type == '%')
		size_printed = conv_perc(data); // return char conversion fonction call
	if (data->type == 'c' || data->type == 's')
		size_printed = conv_cs(data, list);
	if (data->type == 'p')
		size_printed = conv_p(data, list); // return pointer conversion fonction call
	if (data->type == 'x'
		|| data->type == 'X'
		|| data->type == 'o'
		|| data->type == 'u')
		size_printed = conv_ouxX(data, list); // return hexa conversion fonction call
	if (data->type == 'i' || data->type == 'd')
		size_printed = conv_id(data, list); // return decimal conversion fonction call
	if (data->type == 'f')
		size_printed = conv_f(data, list); // return float conversion fonction call
	return (size_printed);
}
