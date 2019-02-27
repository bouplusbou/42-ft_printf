/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_boux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:40:31 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 16:06:05 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_arg_boux(t_struct data, va_list list)
{
	uintmax_t arg;

	arg = 0;
	if (data.type == 'U')
		arg = va_arg(list, unsigned long);
	else if (!data.size)
		arg = va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "j"))
		arg = va_arg(list, uintmax_t);
	else if (ft_strstr(data.size, "ll"))
		arg = va_arg(list, unsigned long long int);
	else if (ft_strstr(data.size, "l"))
		arg = va_arg(list, unsigned long int);
	else if (ft_strstr(data.size, "z"))
		arg = (size_t)va_arg(list, unsigned long long int);
	else if (ft_strstr(data.size, "h") && !ft_strstr(data.size, "hh"))
		arg = (unsigned short int)va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "hh"))
		arg = (unsigned char)va_arg(list, unsigned int);
	return (arg);
}

static char						find_sign(t_struct data, uintmax_t value)
{
	if (ft_strchr(data.flags, '#') && value != 0)
	{
		if (data.type == 'x')
			return ('x');
		if (data.type == 'X')
			return ('X');
		if (data.type == 'o')
			return ('0');
	}
	return (0);
}

static char						*small_res_boux(t_struct data, uintmax_t arg)
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

static char						*create_res_boux(t_struct data, int res_len, char *small_res)
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

int								conv_boux(t_struct *data, int fd, va_list list)
{
	int			res_len;
	char		*result;
	char		*small_res;
	uintmax_t	arg;

	arg = get_arg_boux(*data, list);
	data->sign = find_sign(*data, arg);
	res_len = 0;
	if ((small_res = small_res_boux(*data, arg)))
	{
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
			res_len = 0;
		ft_putstr_fd(result, fd);
		ft_strdel(&result);
		ft_strdel(&small_res);
	}
	return (res_len);
}
