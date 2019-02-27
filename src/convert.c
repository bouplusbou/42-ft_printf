/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/27 15:35:07 by bclaudio         ###   ########.fr       */
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
	if (data->type == 'o'
		|| data->type == 'u'
		|| data->type == 'U'
		|| data->type == 'x'
		|| data->type == 'X'
		|| data->type == 'b')
		len = conv_boux(data, fd, list);
	if (data->type == 'f')
		len = conv_f(data, fd, list);
	if (data->type == 'i' || data->type == 'd')
		len = conv_id(data, fd, list);
	delete_struct(data);	
	return (len);
}
