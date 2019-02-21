/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/21 15:38:36 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	size_printed;

	if (data->type == 'c')
		return (0); // return char conversion fonction call
	if (data->type == 'p')
		return (0); // return pointer conversion fonction call
	if (data->type == 'x' || data->type == 'X')
		return (0); // return hexa conversion fonction call
	if (data->type == 's')
		return (0); // return string conversion fonction call
	if (data->type == 'i' || data->type == 'd')
		size_printed = conv_decimal(data, list); // return decimal conversion fonction call
	if (data->type == 'o')
		return (0); // return octal conversion fonction call
	if (data->type == 'u')
		return (0); // return unsigned decimal conversion fonction call
	if (data->type == 'f')
		return (0); // return float conversion fonction call
	return (size_printed);
}
