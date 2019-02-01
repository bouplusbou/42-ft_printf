/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:11:28 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/01 19:13:48 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get the right size directly in va_arg (if size > int)
** OR cast (if size < int)
** and put the result in the biggest type (long long int)
*/

long long int	get_size_decimal(t_struct data, va_list list)
{
	long long int	arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, int);
	else if (ft_strstr(data.size, "ll"))
		arg = va_arg(list, long long int);
	else if (ft_strstr(data.size, "l"))
		arg = va_arg(list, long int);
	else if (ft_strstr(data.size, "h"))
		arg = (short int)va_arg(list, int);
	else if (ft_strstr(data.size, "hh"))
		arg = (char)va_arg(list, int);
	return (arg);
}

/*
** concatenate a string with '0x' + '000..' + translation in 'hexa'
** depending on '#' & '0' flags and precision
*/

char					*concat_decimal(t_struct data, long long int arg)
{
	char	*concat;
	int		concat_size;
	char	*decimal;
	int		decimal_size;

	if (!(decimal = ft_lltoa_base(arg, "0123456789"))) // if malloc decimal didn't work
		return (NULL);
	decimal_size = ft_strlen(decimal);
	if (ft_strchr(data.flags, '#') && ft_strcmp(decimal, "0")) // add enough space for '0' if needed
		concat_size = decimal_size + 1;
	else
		concat_size = decimal_size;
	if (data.precision > (int)decimal_size) // add enough space for '0's if needed (if precision is longer than input)
		concat_size += data.precision - decimal_size;
	if (!(concat = ft_strnew(concat_size)))
		return (NULL);
	ft_memset(concat, '0', concat_size); // fill '0'
	ft_memcpy(concat + (concat_size - decimal_size), decimal, decimal_size); // write upon the '0' the input translated into decimal
	ft_strdel(&decimal); // we don't need decimal anymore, it is inside concat now
	return (concat);
}

/*
** create the final result:
** place the concatenated form of hexa
*/

char					*create_res_decimal(t_struct data, int result_size, char *concat)
{
	char	*result;
	int		concat_size;

	if (!result_size || !(result = ft_strnew(result_size))) // if result_size is 0 return NULL directly
		return (NULL);
	if (ft_strchr(data.flags, '0') && data.precision < 0
			&& !ft_strchr(data.flags, '-')) // flag '0' without precision and no flag '-' => fill everything with '0'
		ft_memset(result, '0', result_size);
	else
		ft_memset(result, ' ', result_size); // else fill with spaces
	concat_size = ft_strlen(concat);
	if (ft_strchr(data.flags, '-')) // put to the left if flag '-'
		ft_memcpy(result, concat, concat_size);
	else
		ft_memcpy(result + (result_size - concat_size), concat, concat_size); // put to the right otherwise
	// if (ft_strchr(data.flags, '#') && ft_strcmp(concat, "0")) // add the 'x' or 'X' to the second '0' char with flag '#'
	// if (ft_strchr(data.flags, '#') && ft_strcmp(concat, "0")) // add the 'x' or 'X' to the second '0' char with flag '#'
		// result[ft_get_char_index('0', result) + 1] = data.type;
	return (result);
}

/*
** convert into hexadecimal, do all the transformations,
** print the result and return the size of the result
*/

int						conv_decimal(t_struct *data, va_list list)
{
	int		result_size;
	char	*result;
	char	*concat;

	if (!(concat = concat_decimal(*data, get_size_decimal(*data, list)))) // concatenate '0x' + '0's + input translated in hexa
		return (0);
	if (!ft_strcmp(concat, "0") && data->precision == 0) // if input is '0' with a precision of 0, write nothing at all
		concat[0] = '\0';
	if (data->width > (int)ft_strlen(concat)) // choose the result's size: the longer between width and concat 
		result_size = data->width;
	else
		result_size = ft_strlen(concat);
	if (!(result = create_res_decimal(*data, result_size, concat))) // create the final result
		return (0);
	ft_putstr(result); // print result
	ft_strdel(&result); // clean everything: result, concat, struct
	ft_strdel(&concat);
	delete_struct(data);
	return (result_size);
}
