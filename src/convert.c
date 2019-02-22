/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/22 17:29:09 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	len;

	len = 0;
	if (data->type == '%')
		len = conv_perc(data); // return char conversion fonction call
	if (data->type == 'c' || data->type == 's')
		len = conv_cs(data, list);
	if (data->type == 'p')
		len = conv_p(data, list); // return pointer conversion fonction call
	if (data->type == 'f')
		len = conv_f(data, list); // return float conversion fonction call
	if (data->type == 'i' || data->type == 'd')
		len = conv_id(data, list); // return decimal conversion fonction call
	return (len);
}
