/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/21 15:20:46 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct *data, va_list list)
{
	int	size_printed;

	if (data->type == 'c')
		size_printed = conv_cs(data, list);
	if (data->type == 'p')
		return (0); // return pointer conversion fonction call
	if (data->type == 'x' || data->type == 'X')
		return (0); // return hexa conversion fonction call
	if (data->type == 's')
		size_printed = conv_cs(data, list);
	if (data->type == 'i' || data->type == 'd')
		return (0); // return decimal conversion fonction call
	if (data->type == 'o')
		return (0); // return hexa conversion fonction call
	if (data->type == 'u')
		return (0); // return hexa conversion fonction call
	if (data->type == 'f')
		return (0); // return float conversion fonction call
	return (size_printed);
}
