/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:02:49 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 11:43:31 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_perc(t_struct *data, int fd)
{
	int		res_size;
	char	*res;

	res_size = data->width > 1 ? data->width : 1;
	if (!(res = ft_strnew(res_size)))
		exit(EXIT_FAILURE);
	ft_memset(res, ' ', res_size);
	if (ft_strchr(data->flags, '-'))
		res[0] = '%';
	else
		res[res_size - 1] = '%';
	ft_putstr_fd(res, fd);
	ft_strdel(&res);
	return (res_size);
}
