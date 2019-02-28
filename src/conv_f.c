/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:07:07 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/28 11:42:37 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*format_res(t_struct data, long double arg, char *small_res)
{
	char	*res;
	int		res_len;
	int		small_res_len;

	if (arg != arg)
		small_res = ft_strreplace(small_res, "nan");
	else if (arg == +1.0 / 0.0 || arg == -1.0 / 0.0)
		small_res = ft_strreplace(small_res, "inf");
	if (data.sign)
		small_res = ft_strjoinf("0", small_res, 2);
	small_res_len = (int)ft_strlen(small_res);
	res_len = data.width < small_res_len ? small_res_len : data.width;
	if (!(res = ft_strnew(res_len)))
		exit(EXIT_FAILURE);
	ft_memset(res, ' ', res_len);
	if (ft_strchr(data.flags, '0') && !ft_strchr(data.flags, '-'))
		ft_memset(res, '0', res_len);
	if (ft_strchr(data.flags, '-'))
		ft_memcpy(res, small_res, small_res_len);
	else
		ft_memcpy(res + (res_len - small_res_len), small_res, small_res_len);
	if (data.sign)
		res[ft_get_char_index('0', res)] = data.sign;
	ft_strdel(&small_res);
	return (res);
}

static char	*get_float(t_struct data, long double value, char *res)
{
	char	*float_res;
	char	*digit;

	value -= (unsigned long long)value;
	if (!(float_res = ft_strnew(0)))
		exit(EXIT_FAILURE);
	while (data.preci >= 0)
	{
		value *= 10;
		digit = ft_ulltoa_base((unsigned long long)value, data.base);
		float_res = ft_strjoinf(float_res, digit, 3);
		value -= (unsigned long long)value;
		data.preci--;
	}
	res = ft_strjoinf(res, float_res, 3);
	return (res);
}

char		*jesaispas(char *res, int *last_i)
{
	int	i;

	i = *last_i;
	while (i >= 0)
	{
		if (res[i] == ':')
		{
			res[i] = '0';
			if (res[i - 1] == '.')
				res[i - 2]++;
			else if (i != 0)
				res[i - 1]++;
			else
			{
				res = ft_strjoinf("1", res, 2);
				*last_i += 1;
			}
		}
		i--;
	}
	return (res);
}

static char	*manage_preci(t_struct data, long double value, char *res)
{
	int		last_i;
	int		i;

	last_i = ft_get_char_index('.', res) + data.preci;
	if (res[last_i - 1] == '.' && value != 0)
		res[last_i - 2] += res[last_i] >= '5' ? 1 : 0;
	else if (value != 0)
		res[last_i - 1] += res[last_i] >= '5' ? 1 : 0;
	res = jesaispas(res, &last_i);
	i = last_i;
	if (res[last_i - 1] == '.' && !ft_strchr(data.flags, '#'))
		last_i--;
	res[last_i] = '\0';
	return (res);
}

int			conv_f(t_struct *data, int fd, va_list list)
{
	int			res_len;
	char		*res;
	long double	arg;

	arg = get_arg_float(*data, list);
	data->sign = find_sign_f(*data, arg);
	arg = arg > 0 ? arg : -arg;
	res = ft_ulltoa_base((unsigned long long)arg, data->base);
	data->preci = data->preci == -1 ? 6 : data->preci;
	if (data->preci >= 0 || ft_strchr(data->flags, '#'))
		res = ft_strjoinf(res, ".", 1);
	if (data->preci >= 0)
	{
		data->preci++;
		res = get_float(*data, arg, res);
		res = manage_preci(*data, arg, res);
	}
	res = format_res(*data, arg, res);
	ft_putstr_fd(res, fd);
	res_len = ft_strlen(res);
	ft_strdel(&res);
	return (res_len);
}
