/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/26 10:17:37 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	len;

	len = 0;
	if (data->type == '%')
		len = conv_perc(data);
	if (data->type == 'c')
		len = conv_c(data, list);
	if (data->type == 's')
		len = conv_s(data, list);
	if (data->type == 'p')
		len = conv_p(data, list);
	if (data->type == 'o'
		|| data->type == 'u'
		|| data->type == 'U'
		|| data->type == 'x'
		|| data->type == 'X')
		len = conv_oux(data, list);
	if (data->type == 'f')
		len = conv_f(data, list);
	if (data->type == 'i' || data->type == 'd')
		len = conv_id(data, list);
	return (len);
}
