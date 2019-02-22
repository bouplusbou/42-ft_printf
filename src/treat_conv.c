/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:46 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/22 10:02:52 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_conv(char *str, size_t *j, int *len, va_list list)
{
	size_t	i;
	int		type;
	char	*conv;

	i = 1;
	type = 0;
	while (str[i] && is_conv(str[i]) && type == 0)
	{
		if (is_type(str[i]))
			type = 1;
		i++;
	}
	if (type)
	{
		*j += i;
		if (!(conv = ft_strndup(str, i)))
			return (0);
		return (parse_conv(conv, list));
	}
	printf_write('%', len);
	*j += 1;
	return (-1);
}
