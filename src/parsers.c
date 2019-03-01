/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:28:14 by bboucher          #+#    #+#             */
/*   Updated: 2019/03/01 13:50:22 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flags(char *conv, size_t *i)
{
	char	*flags;
	size_t	l;

	l = 0;
	while (is_flag(conv[l]))
		l++;
	*i += l;
	if (l != 0)
	{
		if (!(flags = ft_strndup(conv, l)))
			exit(EXIT_FAILURE);
		return (flags);
	}
	if (!(flags = ft_strnew(0)))
		exit(EXIT_FAILURE);
	return (flags);
}

int		parse_width(char *conv, size_t *i)
{
	int		width_int;
	size_t	l;
	char	*width_str;

	l = 0;
	while (ft_isdigit(conv[l]))
		l++;
	*i += l;
	if (!(width_str = ft_strndup(conv, l)))
		exit(EXIT_FAILURE);
	width_int = ft_atoi(width_str);
	ft_strdel(&width_str);
	return (width_int);
}

int		parse_preci(char *conv, size_t *i, va_list list)
{
	int		preci_int;
	size_t	l;
	char	*preci_str;

	l = 1;
	if (conv[1] == '*')
	{
		preci_int = va_arg(list, int);
		*i += 2;
		return (preci_int < 0 ? -1 : preci_int);
	}
	while (is_preci(conv[l]))
		l++;
	*i += l;
	if (!(preci_str = ft_strndup(conv + 1, l)))
		exit(EXIT_FAILURE);
	preci_int = ft_atoi(preci_str);
	ft_strdel(&preci_str);
	return (preci_int);
}

char	*parse_size(char *conv, size_t *i)
{
	char	*size;
	size_t	l;

	l = 0;
	while (is_size(conv[l]))
		l++;
	*i += l;
	if (!(size = ft_strndup(conv, l)))
		exit(EXIT_FAILURE);
	return (size);
}

void	parse_star(size_t *i, t_struct *data, va_list list)
{
	int arg;

	arg = va_arg(list, int);
	if (arg < 0)
		data->flags = ft_strjoinf(data->flags, "-", 1);
	data->width = arg < 0 ? -arg : arg;
	*i += 1;
}
