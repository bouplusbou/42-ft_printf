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
	char *result;
	int	neg;
	char	*floating;
	char	*tmpstr;

	tmpstr = ft_strdup(".");
	neg = arg < 0 ? 1 : 0; // Retiens la negation
	arg = arg < 0 ? -arg : arg; // Passe en positif si neg pour ulltoa_base()
	data.precision = data.precision == -1 ? 6 : data.precision;
	if (arg != 0 && data.precision == 0 && arg - (int)arg > 0.5) // Arrondit si precision de 0 (recuparation entier) en fonction du premier chiffre apres la virgule
		arg += 1;
	result = ft_ulltoa_base((unsigned long long)arg, data.base); // Recuperation des chiffres avant la virgules
	arg -= (unsigned long long)arg; // Soustraction de l'entier (donc reste que apres la virgules)
	if (data.precision > 0 || ft_strchr(data.flags, '#')) 
		result = ft_strjoinf(&result, &tmpstr, 3); // Place le point si necessaire
	arg *= ft_power(10, data.precision); // Multiplie les chiffres apres la virgules x 10 au nombre de la precision
	if (data.precision > 0)
	{
		ft_strdel(&tmpstr);
		tmpstr = ft_strnew(data.precision);
		ft_memset(tmpstr, '0', data.precision);
		floating = ft_ulltoa_base((unsigned long long)arg, data.base);
		tmpstr = ft_memcpy(tmpstr, floating, ft_strlen(floating));
		result = ft_strjoinf(&result, &tmpstr, 3); // Ajout des chiffres apres la virgule dans result
	}
	if (data.sign)
	{
		tmpstr = ft_strdup("S");
		result = ft_strjoinf(&tmpstr, &result, 3);
	}
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
	long double arg;

	arg = get_arg_float(*data, list);
	data->sign = find_sign(*data, arg < 0 ? 0 : 1);
	if (!(small_res = small_res_float(*data, arg))) //
		return (0);
	printf("SmallResult:%s\n", small_res);
	
	return (100);
}