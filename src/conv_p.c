/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:57:57 by bboucher          #+#    #+#             */
/*   Updated: 2019/03/01 13:47:58 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_res_addr(t_struct data, unsigned long arg)
{
	char	*concat;
	char	*addr;

	if (!(addr = ft_ulltoa_base(arg, data.base)))
		exit(EXIT_FAILURE);
	if (!(concat = ft_strdup("0x")))
		exit(EXIT_FAILURE);
	concat = ft_strjoinf(concat, addr, 3);
	return (concat);
}

static char	*res_p(t_struct data, char *concat)
{
	char	*res;
	int		res_len;
	int		concat_len;

	concat_len = ft_strlen(concat);
	res_len = data.width > concat_len ? data.width : concat_len;
	if (!(res = ft_strnew(res_len)))
		exit(EXIT_FAILURE);
	ft_memset(res, ' ', res_len);
	if (data.width > concat_len && !ft_strchr(data.flags, '-'))
		ft_memcpy(res + (res_len - concat_len), concat, concat_len);
	else
		ft_memcpy(res, concat, concat_len);
	return (res);
}

int			conv_p(t_struct *data, int fd, va_list list)
{
	int		res_len;
	char	*res;
	char	*small_res;

	small_res = small_res_addr(*data, (unsigned long)va_arg(list, void*));
	res = res_p(*data, small_res);
	res_len = ft_strlen(res);
	ft_putstr_fd(res, fd);
	ft_strdel(&res);
	ft_strdel(&small_res);
	return (res_len);
}
