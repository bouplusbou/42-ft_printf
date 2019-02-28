/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/28 11:08:14 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, int fd, va_list list)
{
	int	len;

	len = 0;
	if (data->type == '%')
		len = conv_perc(data, fd);
	if (data->type == 'c')
		len = conv_c(data, fd, list);
	if (data->type == 's')
		len = conv_s(data, fd, list);
	if (data->type == 'p')
		len = conv_p(data, fd, list);
	if (ft_strchr("ouUxXb", data->type))
		len = conv_boux(data, fd, list);
	if (data->type == 'f')
		len = conv_f(data, fd, list);
	if (ft_strchr("id", data->type))
		len = conv_id(data, fd, list);
	delete_struct(data);
	return (len);
}
