/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:17:32 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/19 13:17:52 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get the right size directly in va_arg (if size > int)
** OR cast (if size < int)
** and put the result in the biggest type (long long int)
*/

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

/*
** small_resenate a string with '0x' + '000..' + translation in 'hexa'
** depending on '#' & '0' flags and precision
*/

char *small_res_float(t_struct data, long double arg)
{
	char *result;
	char *tmpstr;
	int neg;
	char *relou;

	neg = arg < 0 ? 1 : 0;
	arg = arg < 0 ? -arg : arg;
	data.precision = data.precision == -1 ? 6 : data.precision;
	if (arg > 0 && data.precision == 0 && arg - (int)arg > 0.5)
		arg += 1;
	result = ft_ulltoa_base((unsigned long long)arg, "0123456789"); // Ajout de l'entier dans result
	// printf("After ulltotrigjrihjer:%s\n", result);
	arg -= (unsigned long long)arg;
	if (data.precision > 0 || ft_strchr(data.flags, '#'))
	{
		tmpstr = ft_strdup(".");
		result = ft_strjoinf(&result, &tmpstr, 3);
	}
	arg *= ft_power(10, data.precision);
	// arg += 1;
	if (data.precision > 0)
	{
		tmpstr = ft_strnew(data.precision);
		ft_memset(tmpstr, '0', data.precision);
		relou = ft_ulltoa_base((unsigned long long)arg, "0123456789");
		tmpstr = ft_memcpy(tmpstr, relou, ft_strlen(relou));
		result = ft_strjoinf(&result, &tmpstr, 3); // Ajout des chiffres apres la virgule dans result
	}
	if (!neg && ft_strchr(data.flags, ' '))
	{
		tmpstr = ft_strdup(" ");
		result = ft_strjoinf(&tmpstr, &result, 3);
	}
	return (result);
}

/*
** create the final result:
** place the small_resenated form of hexa
*/

char *create_res_float(t_struct data, int result_len, char *small_res, int neg)
{
	char *result;
	int small_res_size;
	int i;
	char	c;

	i = 0;
	c = ' ';
	if (ft_strchr(data.flags, '+') || neg || (ft_strchr(data.flags, ' ') && neg))
		c = neg ? '-' : '+';
	if (!result_len || !(result = ft_strnew(result_len))) // if result_len is 0 return NULL directly
		return (NULL);
	ft_memset(result, ' ', result_len);												 // else fill with spaces
	if (ft_strchr(data.flags, '0') && data.precision <= 0 && !ft_strchr(data.flags, '-')) // flag '0' without precision and no flag '-' => fill everything with '0'
		ft_memset(result, '0', result_len);
	small_res_size = ft_strlen(small_res);
	if (ft_strchr(data.flags, '-')) // put to the left if flag '-'
		ft_memcpy(result, small_res, small_res_size);
	else
		ft_memcpy(result + (result_len - small_res_size), small_res, small_res_size); // put to the right otherwise
	if (neg || ft_strchr(data.flags, '+') || ft_strchr(data.flags, ' ')) // add the 'x' or 'X' to the second '0' char with flag '#'
	{
		while (!ft_isdigit(result[i]))
			i++;
		result[i == 0 ? 0 : (i - 1)] = c;
	}
	return (result);
}

/*
** convert into hexadecimal, do all the transformations,
** print the result and return the size of the result
*/

int conv_float(t_struct *data, va_list list)
{
	int result_len;
	char *result;
	char *small_res;
	long double arg;

	arg = get_arg_float(*data, list);
	if (!(small_res = small_res_float(*data, arg))) //
		return (0);
	result_len = ft_strlen(small_res);
	result_len = data->width > result_len ? data->width : result_len;		   // choose the result's size: the longer between width and small_res
	if (!(result = create_res_float(*data, result_len, small_res, arg < 0 ? 1 : 0))) // create the final result
		return (0);
	ft_putstr(result);  // print result
	ft_strdel(&result); // clean everything: result, small_res, struct
	ft_strdel(&small_res);
	delete_struct(data);
	return (100);
}