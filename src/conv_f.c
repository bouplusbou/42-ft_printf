#include "ft_printf.h"

static long double get_arg_float(t_struct data, va_list list)
{
	long double arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, double);
	else if (ft_strstr(data.size, "L"))
		arg = va_arg(list, long double);
	return (arg);
}

static char	*concat_before(char *before, char *tmp)
{
	char	*result;

	result = ft_strjoin(before, tmp);
	ft_strdel(&tmp);
	return (result);
}

static char	*inf_nan(long double arg, char *small_res)
{
	ft_strdel(&small_res);
	if (arg != arg)
		return (ft_strdup("nan"));
	return (ft_strdup("inf"));
}

static char	*formating_result(t_struct data, long double arg, char *small_res)
{
	char	*result;
	int		result_len;
	int		small_res_len;

	if (arg != arg || arg == +1.0/0.0 || arg == -1.0/0.0)
		small_res = inf_nan(arg, small_res);
	if (data.sign)
		small_res = concat_before("0", small_res);
	small_res_len = (int)ft_strlen(small_res);
	result_len = data.width < small_res_len ? small_res_len : data.width;
	if (!(result = ft_strnew(result_len)))
		return (NULL);
	ft_memset(result, ' ', result_len);												 // else fill with spaces
	if (ft_strchr(data.flags, '0') && !ft_strchr(data.flags, '-'))
		ft_memset(result, '0', result_len);
	if (ft_strchr(data.flags, '-')) // put to the left if flag '-'
		ft_memcpy(result, small_res, small_res_len);
	else
		ft_memcpy(result + (result_len - small_res_len), small_res, small_res_len);
	if (data.sign)																	// Si un signe est requis
		result[ft_get_char_index('0', result)] = data.sign;
	ft_strdel(&small_res);
	return (result);
}

static char	find_sign(t_struct data, long double arg)
{
	if ((1 / arg < 0) || arg == -1.0/0.0 || arg < 0)								// Si arg == -0.0 ou -inf ou est negatif
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

static char	*get_int(t_struct data, long double arg)
{
	return (ft_ulltoa_base((unsigned long long)arg, data.base));
}

static char	*get_float(t_struct data, long double value, char *result)
{
	char	*float_res;
	char	*digit;

	value -= (unsigned long long)value;									//	Extracting float value
	if (!(float_res = ft_strnew(0)))
		return (NULL);
	while (data.precision >= 0)											//	Looping times precision
	{
		value *= 10;													//	Converting first float digit to int
		digit = ft_ulltoa_base((unsigned long long)value, data.base);	//	Socking resulting digit
		float_res = ft_strjoinf(&float_res, &digit, 3);					//	Addin digit to result
		value -= (unsigned long long)value;								//	Removing previously added digit
		data.precision--;
	}
	result = ft_strjoinf(&result, &float_res, 3);						//	Joining int and float value together
	return (result);
}

static char	*manage_precision(t_struct data, long double value, char *result)
{
	int		last_i;
	int		i;

	last_i = ft_get_char_index('.', result) + data.precision;			//	Finding the last digit required by the precision (+1 for the digit used for the rounding)
	if (result[last_i - 1] == '.' && value != 0)					//	If precision = 0, rounding value on the first digit of the int
		result[last_i - 2] += result[last_i] >= '5' ? 1 : 0;
	else if (value != 0)											//	Rounding last digit in the result
		result[last_i - 1] += result[last_i] >= '5' ? 1 : 0;
	i = last_i;
	while (i >= 0)														//	Check the entire result starting from the end
	{
		if (result[i] == ':')											//	If digit has been incremented to 10
		{
			result[i] = '0';											//	Replacing digit with 0
			if (result[i - 1] == '.')									//	If the previous digit is the decimal point
				result[i - 2]++;											//	Incrementing first int digit
			else if (i != 0)											//	Else if we're not on the first int digit
				result[i - 1]++;											//	Incrementing previous digit
			else
			{													//	Else if we're on the first int digit
				result = concat_before("1", result);							//	Adding 1 to the left of the result
				last_i++;										//	Incrementing last digit index to keep matching the precision value
			}
		}
		i--;
	}
	if (result[last_i - 1] == '.' && !ft_strchr(data.flags, '#'))		//	Move the index backward if precision = 0 and the '#' flag is not present
		last_i--;														//	to get rid of the decimal point that is not requested
	result[last_i] = '\0';												//	Nul terminating the result depending on the precision
	return (result);
}

static char *concat_after(char *tmp, char *after)
{
	char	*result;

	result = ft_strjoin(tmp, after);
	ft_strdel(&tmp);
	return (result);
}

int		conv_f(t_struct *data, va_list list)
{
	int			result_len;
	char		*result;
	long double	arg;

	arg = get_arg_float(*data, list);									//	Getting argument value
	data->sign = find_sign(*data, arg);						//	Getting sign
	arg = arg > 0 ? arg : -arg;											//	Switching argument trop positive if it wasn't
	result = get_int(*data, arg);										//	Getting integer value from argument
	data->precision = data->precision == -1 ? 6 : data->precision;		//	Normalising precision value
	if (data->precision >= 0 || ft_strchr(data->flags, '#'))			//	Adding '.' to the result string if required
		result = concat_after(result, ".");
	if (data->precision >= 0)								
	{
		data->precision++;												//	Incrementation de la precision pour les arrondit plus tard (augmente la taille de la string de 1)
		result = get_float(*data, arg, result);							//	Getting float value from argument if required
		result = manage_precision(*data, arg, result);						//	Applying precision on result
	}
	if (!(result = formating_result(*data, arg, result)))							//	Formating result
		result_len = 0;													//	Printing result
	else
	{
		ft_putstr(result);
		result_len = ft_strlen(result);													//	Printing result
	}
	ft_strdel(&result); // clean everything: result, small_res, struct
	delete_struct(data);
	return (result_len);
}
