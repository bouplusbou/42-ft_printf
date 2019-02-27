/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:20:35 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/27 17:25:24 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			find_sign_f(t_struct data, long double arg)
{
	if ((1 / arg < 0) || arg == -1.0 / 0.0 || arg < 0)
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

char				find_sign_id(t_struct data, int pos)
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

char						find_sign_boux(t_struct data, uintmax_t value)
{
	if (ft_strchr(data.flags, '#') && value != 0)
	{
		if (data.type == 'x')
			return ('x');
		if (data.type == 'X')
			return ('X');
		if (data.type == 'o')
			return ('0');
	}
	return (0);
}