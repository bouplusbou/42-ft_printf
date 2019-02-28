/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:15:15 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 10:59:03 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*res_c(t_struct data, char arg, int res_len)
{
	char	*res;

	if (!(res = ft_strnew(res_len)))
		exit(EXIT_FAILURE);
	res = ft_memset(res, ' ', res_len);
	if (ft_strchr(data.flags, '0'))
		res = ft_memset(res, '0', res_len);
	if (ft_strchr(data.flags, '-'))
		res[0] = arg;
	else
		res[res_len - 1] = arg;
	return (res);
}

void		print_res_c(char *res, int fd, int res_len)
{
	int	i;

	i = 0;
	while (i < res_len)
		write(fd, &res[i++], 1);
}

int			conv_c(t_struct *data, int fd, va_list list)
{
	int		res_len;
	char	arg;
	char	*res;

	arg = (char)va_arg(list, int);
	res_len = data->width > 1 ? data->width : 1;
	res = res_c(*data, arg, res_len);
	print_res_c(res, fd, res_len);
	ft_strdel(&res);
	return (res_len);
}
