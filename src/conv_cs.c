#include "ft_printf.h"

char	*get_arg_cs(t_struct data, va_list list)
{
	char	*arg;

	if (data.type == 'c')
	{
		arg = ft_strnew(1);
		arg[0] = (char)va_arg(list, int);
	}
	else
		arg = va_arg(list, char *);
	return(arg);
}

char	*small_res_cs(t_struct data, char *arg)
{
	char	*small_res;
	int		len;

	len = data.precision >= 0 ? (size_t)data.precision : ft_strlen(arg);
	small_res = ft_strnew(len);
	ft_strncpy(small_res, arg, len);
	return (small_res);
}

char	*create_res_cs(t_struct data, char *small_res)
{
	char *result;
	int		len;
	int		i_cpy;

	len = data.width > (int)ft_strlen(small_res) ? data.width : (int)ft_strlen(small_res);
	result = ft_strnew(len);
	result = ft_memset(result, ' ', len);
	if (ft_strchr(data.flags, '-'))
		i_cpy = 0;
	else
		i_cpy = len - ft_strlen(small_res);
	ft_memcpy(result + i_cpy, small_res, ft_strlen(small_res));
	return (result);	
}

int     conv_cs(t_struct *data, va_list list)
{
	char *small_res;
	char *result;
	char	*arg;
	
	arg = get_arg_cs(*data, list);
	if (!arg)
	{
		if (data->precision < 0 || data->precision > 5)
			arg = ft_strdup("(null)");
		else
			arg = ft_strdup("");
	}
	small_res = small_res_cs(*data, arg);
	result = create_res_cs(*data, small_res);
	ft_putstr(result);
	return (ft_strlen(result));
}