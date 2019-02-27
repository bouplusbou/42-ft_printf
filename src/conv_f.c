#include "ft_printf.h"

static long double	get_arg_float(t_struct data, va_list list)
{
	long double arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, double);
	else if (ft_strstr(data.size, "L"))
		arg = va_arg(list, long double);
	return (arg);
}

static char			*inf_nan(long double arg, char *small_res)
{
	ft_strdel(&small_res);
	if (arg != arg)
		return (ft_strdup("nan"));
	return (ft_strdup("inf"));
}

static char			*format_res(t_struct data, long double arg, char *small_res)
{
	char	*res;
	int		res_len;
	int		small_res_len;

	if (arg != arg || arg == +1.0 / 0.0 || arg == -1.0 / 0.0)
		small_res = inf_nan(arg, small_res);
	if (data.sign)
		small_res = ft_strjoinf("0", small_res, 2);
	small_res_len = (int)ft_strlen(small_res);
	res_len = data.width < small_res_len ? small_res_len : data.width;
	if (!(res = ft_strnew(res_len)))
		return (NULL);
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

static char			find_sign(t_struct data, long double arg)
{
	if ((1 / arg < 0) || arg == -1.0 / 0.0 || arg < 0)
		return ('-');
	else
	{
		if (ft_strchr(data.flags, '+'))
			return ('+');
		if (ft_strchr(data.flags, ' '))
			return (' ');
	}
	return (0);
}

static char	*get_float(t_struct data, long double value, char *result)
{
	char	*float_res;
	char	*digit;

	value -= (unsigned long long)value;
	if (!(float_res = ft_strnew(0)))
		return (NULL);
	while (data.preci >= 0)
	{
		value *= 10;
		digit = ft_ulltoa_base((unsigned long long)value, data.base);
		float_res = ft_strjoinf(float_res, digit, 3);
		value -= (unsigned long long)value;
		data.preci--;
	}
	result = ft_strjoinf(result, float_res, 3);
	return (result);
}

static char			*manage_preci(t_struct data, long double value, char *res)
{
	int		last_i;
	int		i;

	last_i = ft_get_char_index('.', res) + data.preci;
	if (res[last_i - 1] == '.' && value != 0)
		res[last_i - 2] += res[last_i] >= '5' ? 1 : 0;
	else if (value != 0)
		res[last_i - 1] += res[last_i] >= '5' ? 1 : 0;
	i = last_i;
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
				last_i++;
			}
		}
		i--;
	}
	if (res[last_i - 1] == '.' && !ft_strchr(data.flags, '#'))
		last_i--;
	res[last_i] = '\0';
	return (res);
}

int					conv_f(t_struct *data, int fd, va_list list)
{
	int			result_len;
	char		*result;
	long double	arg;

	arg = get_arg_float(*data, list);
	data->sign = find_sign(*data, arg);
	arg = arg > 0 ? arg : -arg;
	result = ft_ulltoa_base((unsigned long long)arg, data->base);
	data->preci = data->preci == -1 ? 6 : data->preci;
	if (data->preci >= 0 || ft_strchr(data->flags, '#'))
		result = ft_strjoinf(result, ".", 1);
	if (data->preci >= 0)
	{
		data->preci++;
		result = get_float(*data, arg, result);
		result = manage_preci(*data, arg, result);
	}
	if (!(result = format_res(*data, arg, result)))
		result_len = 0;
	else
	{
		ft_putstr_fd(result, fd);
		result_len = ft_strlen(result);
	}
	ft_strdel(&result);
	return (result_len);
}
