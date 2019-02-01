/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:38 by bclaudio          #+#    #+#             */
/*   Updated: 2019/01/31 14:08:39 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(t_struct data, va_list list)
{
	(void)list;
	if (data.type == 'c')
		return (0); // return char conversion fonction call
	if (data.type == 'p')
		return (0); // return pointer conversion fonction call
	if (data.type == 'x' || data.type == 'X')
		return (0); // return hexa conversion fonction call
	if (data.type == 's')
		return (0); // return string conversion fonction call
	if (data.type == 'i' || data.type == 'd')
		return (0); // return decimal conversion fonction call
	if (data.type == 'o')
		return (0); // return octal conversion fonction call
	if (data.type == 'u')
		return (0); // return unsigned decimal conversion fonction call
	if (data.type == 'f')
		return (0); // return float conversion fonction call
	return (0);
}
