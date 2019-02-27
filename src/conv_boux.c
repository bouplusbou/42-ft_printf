/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_boux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:40:31 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 17:31:57 by bclaudio         ###   ########.fr       */
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
		return (NULL);
	arg_str_len = ft_strlen(arg_str);
	small_res_len = arg_str_len;
	if (data.sign)
	{
		small_res_len++;
		if (data.type == 'x' || data.type == 'X')
			small_res_len++;
	}
	if (data.preci > (data.type == 'x' ? (int)arg_str_len : small_res_len))
		small_res_len += data.preci - (data.type == 'x' ?
			(int)arg_str_len : small_res_len);
	if (!(small_res = ft_strnew(small_res_len)))
		return (NULL);
	ft_memset(small_res, '0', small_res_len);
	ft_memcpy(small_res + (small_res_len - arg_str_len), arg_str, arg_str_len);
	ft_strdel(&arg_str);
	return (small_res);
}

static char	*create_res_boux(t_struct data, int res_len, char *small_res)
{
	char	*res;
	int		small_res_len;
	int		sign_i;

	if (!res_len || !(res = ft_strnew(res_len)))
		return (NULL);
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
	char		*result;
	char		*small_res;
	uintmax_t	arg;

	arg = get_arg_boux(*data, list);
	data->sign = find_sign_boux(*data, arg);
	res_len = 0;
	if ((small_res = small_res_boux(*data, arg)))
		exit(0);
	if (!ft_strcmp(small_res, "0") && data->preci == 0)
	{
		small_res[0] = '\0';
		if (ft_strchr(data->flags, '#') && data->type == 'o')
			small_res[0] = '0';
	}
	res_len = ft_strlen(small_res);
	if (data->width > (int)ft_strlen(small_res))
		res_len = data->width;
	if (!(result = create_res_boux(*data, res_len, small_res)))
		exit(0);
	ft_putstr_fd(result, fd);
	ft_strdel(&result);
	ft_strdel(&small_res);
	return (res_len);
}
