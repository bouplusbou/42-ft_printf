/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_boux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:40:31 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 14:27:25 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_res_boux(t_struct data, uintmax_t arg)
{
	char	*small_res;
	int		small_res_len;
	char	*arg_str;
	int		arg_str_len;

	if (!(arg_str = ft_uimxtoa_base(arg, data.base)))
		exit(EXIT_FAILURE);
	arg_str_len = ft_strlen(arg_str);
	small_res_len = arg_str_len;
	if (data.sign)
	{
		small_res_len++;
		if (ft_strchr("xX", data.type))
			small_res_len++;
	}
	if (data.preci > (ft_strchr("xX", data.type) ?
		(int)arg_str_len : small_res_len))
		small_res_len += data.preci - (ft_strchr("xX", data.type) ?
			(int)arg_str_len : small_res_len);
	if (!(small_res = ft_strnew(small_res_len)))
		exit(EXIT_FAILURE);
	ft_memset(small_res, '0', small_res_len);
	ft_memcpy(small_res + (small_res_len - arg_str_len), arg_str, arg_str_len);
	ft_strdel(&arg_str);
	return (small_res);
}

static char	*res_boux(t_struct data, int res_len, char *small_res)
{
	char	*res;
	int		small_res_len;
	int		sign_i;

	if (!(res = ft_strnew(res_len)))
		exit(EXIT_FAILURE);
	ft_memset(res, ' ', res_len);
	if (ft_strchr(data.flags, '0')
		&& data.preci < 0 && !ft_strchr(data.flags, '-'))
		ft_memset(res, '0', res_len);
	small_res_len = ft_strlen(small_res);
	if (ft_strchr(data.flags, '-'))
		ft_memcpy(res, small_res, small_res_len);
	else
		ft_memcpy(res + (res_len - small_res_len), small_res, small_res_len);
	if (data.sign)
	{
		sign_i = ft_get_char_index('0', res);
		if (data.type == 'x' || data.type == 'X')
			sign_i++;
		res[sign_i] = data.sign;
	}
	return (res);
}

int			conv_boux(t_struct *data, int fd, va_list list)
{
	int			res_len;
	char		*res;
	char		*small_res;
	uintmax_t	arg;

	arg = get_arg_boux(*data, list);
	data->sign = find_sign_boux(*data, arg);
	res_len = 0;
	small_res = small_res_boux(*data, arg);
	if (!ft_strcmp(small_res, "0") && data->preci == 0)
	{
		small_res[0] = '\0';
		if (ft_strchr(data->flags, '#') && data->type == 'o')
			small_res[0] = '0';
	}
	res_len = ft_strlen(small_res);
	if (data->width > (int)ft_strlen(small_res))
		res_len = data->width;
	res = res_boux(*data, res_len, small_res);
	ft_putstr_fd(res, fd);
	ft_strdel(&res);
	ft_strdel(&small_res);
	return (res_len);
}
