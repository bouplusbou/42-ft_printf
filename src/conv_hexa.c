/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 08:08:10 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/01 11:20:48 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get the right size directly in va_arg (if size > unsigned int)
** OR cast (if size < unsigned int)
** and put the result in the biggest unsigned type (unsigned long long int)
*/

unsigned long long int	get_size(t_struct data, va_list list)
{
	unsigned long long int	arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "ll"))
		arg = va_arg(list, unsigned long long int);
	else if (ft_strstr(data.size, "l"))
		arg = va_arg(list, unsigned long int);
	else if (ft_strstr(data.size, "h"))
		arg = (unsigned short int)va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "hh"))
		arg = (unsigned char)va_arg(list, unsigned int);
	return (arg);
}

/*
** concatenate a string with '0x' + '000..' + translation in 'hexa'
** depending on '#' & '0' flags and precision
*/

char					*concat_hexa(t_struct data, unsigned long long int arg)
{
	char	*concat;
	int		concat_size;
	int		hexa_size;
	char	*hexa;

	if (data.type == 'x')
		hexa = ft_ulltoa_base(arg, "0123456789abcdef");
	else
		hexa = ft_ulltoa_base(arg, "0123456789ABCDEF");
	hexa_size = ft_strlen(hexa);
	if (ft_strchr(data.flags, '#') && ft_strcmp(hexa, "0"))
		concat_size = hexa_size + 2;
	else
		concat_size = hexa_size;
	if (data.precision > (int)hexa_size)
		concat_size += data.precision - hexa_size;
	if (!(concat = ft_strnew(concat_size)))
		return (NULL);
	ft_memset(concat, '0', concat_size);
	ft_memcpy(concat + (concat_size - hexa_size), hexa, hexa_size);
	return (concat);
}

int						ft_get_char_index(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (0);
}

/*
** create the result based on the concatenated form of hexa
*/

char					*create_res(t_struct data, int res_size, char *concat)
{
	char	*res;
	int		concat_size;

	if (!(res = ft_strnew(res_size)))
		return (NULL);
	if (ft_strchr(data.flags, '0') && data.precision < 0
			&& !ft_strchr(data.flags, '-'))
		ft_memset(res, '0', res_size);
	else
		ft_memset(res, ' ', res_size);
	concat_size = ft_strlen(concat);
	if (!ft_strchr(data.flags, '-'))
		ft_memcpy(res + (res_size - concat_size), concat, concat_size);
	else
		ft_memcpy(res, concat, concat_size);
	if (ft_strchr(data.flags, '#') && ft_strcmp(concat, "0"))
		res[ft_get_char_index(res, '0') + 1] = data.type;
	return (res);
}

/*
** convert into hexadecimal, do all the transformations,
** print the result and return the size of the result
*/

int						conv_hexa(t_struct data, va_list list)
{
	int		result_size;
	char	*result;
	char	*concat;

	if (!(concat = concat_hexa(data, get_size(data, list))))
		return (0);
	if (!ft_strcmp(concat, "0") && data.precision == 0)
		concat[0] = '\0';
	if (data.width > (int)ft_strlen(concat))
		result_size = data.width;
	else
		result_size = ft_strlen(concat);
	result = create_res(data, result_size, concat);
	ft_putstr(result);
	return (result_size);
}
