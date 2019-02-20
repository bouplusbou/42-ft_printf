#include "ft_printf.h"

long double get_arg_float(t_struct data, va_list list)
{
	long double arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, double);
	else if (ft_strstr(data.size, "L"))
		arg = va_arg(list, long double);
	return (arg);
}

char	*small_res_float(t_struct  data, long double arg)
{
	char	*result;
	char	*floating;
	int		preci;

	//		arg = -123.456
	arg = arg < 0 ? -arg : arg; // Passe en positif si neg pour ulltoa_base()
	//		arg = 123.456
	data.precision = data.precision == -1 ? 6 : data.precision;
	preci = data.precision + 1;
	result = ft_ulltoa_base((unsigned long long)arg, data.base); // Recuperation des chiffres avant la virgules
	arg -= (unsigned long long)arg; // Soustraction de l'entier (donc reste que apres la virgules)
	if (data.precision > 0 || ft_strchr(data.flags, '#')) 
		result = ft_strjoin(result, "."); // Place le point si necessaire
	//		result = 123.
	//		arg = 0.456
	floating = ft_strnew(0);
	while (preci--)
	{
		if (arg > 0)
			arg *= 10;
		floating = ft_strjoin(floating, ft_ulltoa_base((unsigned long long)arg, data.base));
		arg -= (unsigned long long)arg;
	}
	result = ft_strjoin(result, floating); // Ajout des chiffres apres la virgule dans result
	//		result = 123.456
	// if (data.sign)
		// result = ft_strjoin("0", result); // A DEPLACER
	//		result = -123.456
	return (result);
}

char	*create_res_float(t_struct data, char *small_res)
{
	char	*result;
	int		result_len;
	int		small_res_len;

	small_res_len = (int)ft_strlen(small_res);
	result_len = data.width < small_res_len ? small_res_len : data.width;
	result = ft_strnew(result_len);
	ft_memset(result, ' ', result_len);												 // else fill with spaces
	if (ft_strchr(data.flags, '0') && data.precision <= 0 && !ft_strchr(data.flags, '-'))
		ft_memset(result, '0', result_len);
	if (ft_strchr(data.flags, '-')) // put to the left if flag '-'
		ft_memcpy(result, small_res, small_res_len);
	else
		ft_memcpy(result + (result_len - small_res_len), small_res, small_res_len);
	if (data.sign)																	// Si un signe est requis
		result[ft_get_char_index('0', result)] = data.sign;
	return (result);
}

char	*handle_precision(t_struct data, char *value)
{
	char	*result;
	int		last;
	int		i;

	(void)data;
	i = 0;
	result = NULL;
	//trouver la virgule et mettre dans last
	//ajouter a last data.precision
	printf("Value = %s\n", value);
	last = ft_get_char_index('.', value) + data.precision;
	printf("Index de la virgule:%i\n", last);
	//Checker valeur juste apres last > 5 ou pas
		//Si superieur, ajouter 1 a last
			//Si last == ':' || 58 alors ajouter 1 a last
				//si last == ":" || 58, ajouter 1 a la valeur precedente
					//Repeter pour chaque valeur MAIS PENSER A REMETTRE LA VALEUR DES CHAR PRECEDENT A 0
	while (value[last] == '9' && (value[last + 1] >= '5' || (value[last + 1] == '.' && value[last + 2] >= '5')))
	{
		value[last]++;
		last--;
		if (value[last] == '.')
			last--;
	}
	if (value[last + 1] == ':' || (value[last + 1] == '.' && value[last + 2] == ':'))
		value[last]++;
	while (value[i])
	{
		if (value[i] == ':')
			value[i] = '0';
		i++;
	}
	if (value[0] == '0')
		value = ft_strjoin("1", value);
	value[ft_get_char_index('.', value) + data.precision + 1] = '\0';
	printf("Value = %s\n", value);
	//Remplacer le char correspondant a last + 1 en '\0'
	//copier string dans result
	//Printf done
	return (result);
}

static char	find_sign(t_struct data, int pos)
{
	if (pos)
	{
		if (ft_strchr(data.flags, '+'))
			return ('+');
		if (ft_strchr(data.flags, ' '))
			return (' ');
	}
	else
		return ('-');
	return (0);
}

int conv_float(t_struct *data, va_list list)
{
	char *small_res;
	// char *result;
	long double arg;

	arg = get_arg_float(*data, list);
	data->sign = find_sign(*data, arg < 0 ? 0 : 1);
	if (!(small_res = small_res_float(*data, arg))) //
		return (0);
	handle_precision(*data, small_res);
	// printf("SmallResult:%s\n", small_res);
	// if (!(result = create_res_float(*data, small_res))) //
		// return (0);
	// ft_putstr(result);
	return (100);
}