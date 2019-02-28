/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:38:32 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 16:34:29 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_res_idmal(t_struct data, intmax_t arg)
{
	char	*small_res;
	int		small_res_len;
	char	*arg_str;
	int		arg_str_len;

	if (!(arg_str = ft_uimxtoa_base(arg < 0 ? -arg : arg, data.base)))
		exit(EXIT_FAILURE);
	arg_str_len = ft_strlen(arg_str);
	small_res_len = arg_str_len + (data.sign ? 1 : 0);
	if (data.preci > (int)arg_str_len)
		small_res_len += data.preci - arg_str_len;
	if (!(small_res = ft_strnew(small_res_len)))
		exit(EXIT_FAILURE);
	ft_memset(small_res, '0', small_res_len);
	ft_memcpy(small_res + (small_res_len - arg_str_len), arg_str, arg_str_len);
	ft_strdel(&arg_str);
	return (small_res);
}

static char	*res_id(t_struct data, int res_len, char *small_res)
{
	char	*res;
	int		small_res_len;

	if (!(res = ft_strnew(res_len)))
		exit(EXIT_FAILURE);
	ft_memset(res, ' ', res_len);
	if (ft_strchr(data.flags, '0') && data.preci < 0
		&& !ft_strchr(data.flags, '-'))
		ft_memset(res, '0', res_len);
	small_res_len = ft_strlen(small_res);
	if (ft_strchr(data.flags, '-'))
		ft_memcpy(res, small_res, small_res_len);
	else
		ft_memcpy(res + (res_len - small_res_len), small_res, small_res_len);
	if (data.sign)
		res[ft_get_char_index('0', res)] = data.sign;
	return (res);
}

int			conv_id(t_struct *data, int fd, va_list list)
{
	int				res_len;
	char			*res;
	char			*small_res;
	intmax_t		arg;

	// printf("\n|data->preci:%d|\n", data->preci);
	arg = get_arg_decimal(*data, list);
	data->sign = find_sign_id(*data, arg >= 0 ? 1 : 0);
	small_res = small_res_idmal(*data, arg);
	res_len = 0;
	if (!ft_strcmp(small_res, "0") && data->preci == 0)
		small_res[0] = '\0';
	res_len = ft_strlen(small_res);
	if (data->width > (int)ft_strlen(small_res))
		res_len = data->width;
	if (!(res = res_id(*data, res_len, small_res)))
		res_len = 0;
	ft_putstr_fd(res, fd);
	ft_strdel(&res);
	ft_strdel(&small_res);
	return (res_len);
}
