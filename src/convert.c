/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/21 16:39:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	size_printed;

	(void)list;
	size_printed = 0;
	if (data->type == '%')
		return (0); // return char conversion fonction call
	if (data->type == 'c')
		return (0); // return char conversion fonction call
	if (data->type == 'p')
		size_printed = conv_p(data, list); // return pointer conversion fonction call
	if (data->type == 'x'
		|| data->type == 'X'
		|| data->type == 'o'
		|| data->type == 'u')
		size_printed = conv_oux(data, list); // return hexa conversion fonction call
	if (data->type == 's')
		return (0); // return string conversion fonction call
	if (data->type == 'i' || data->type == 'd')
		size_printed = conv_id(data, list); // return decimal conversion fonction call
	if (data->type == 'f')
		return (0); // return float conversion fonction call
	return (size_printed);
}
