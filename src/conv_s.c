/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:15:09 by bboucher          #+#    #+#             */
/*   Updated: 2019/03/01 13:48:39 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_res_s(t_struct data, char *arg)
{
	char	*small_res;
	int		len;

	len = data.preci >= 0 ? (size_t)data.preci : ft_strlen(arg);
	if (!(small_res = ft_strnew(len)))
		exit(EXIT_FAILURE);
	ft_strncpy(small_res, arg, len);
	return (small_res);
}

static char	*res_s(t_struct data, char *small_res)
{
	char	*res;
	int		len;
	int		i_cpy;

	len = data.width > (int)ft_strlen(small_res) ?
			data.width : (int)ft_strlen(small_res);
	if (!(res = ft_strnew(len)))
		exit(EXIT_FAILURE);
	res = ft_memset(res, ' ', len);
	if (!ft_strchr(data.flags, '-') && ft_strchr(data.flags, '0'))
		res = ft_memset(res, '0', len);
	if (ft_strchr(data.flags, '-'))
		i_cpy = 0;
	else
		i_cpy = len - ft_strlen(small_res);
	ft_memcpy(res + i_cpy, small_res, ft_strlen(small_res));
	ft_strdel(&small_res);
	return (res);
}

int			conv_s(t_struct *data, int fd, va_list list)
{
	int		res_len;
	char	*arg;
	char	*small_res;
	char	*res;

	if (!(arg = va_arg(list, char *)))
	{
		if (!(arg = ft_strdup("(null)")))
			exit(EXIT_FAILURE);
	}
	res_len = 0;
	if (arg)
	{
		if ((small_res = small_res_s(*data, arg))
			&& (res = res_s(*data, small_res)))
		{
			ft_putstr_fd(res, fd);
			res_len = ft_strlen(res);
			ft_strdel(&res);
		}
	}
	if (arg && !ft_strcmp(arg, "(null)"))
		ft_strdel(&arg);
	return (res_len);
}
