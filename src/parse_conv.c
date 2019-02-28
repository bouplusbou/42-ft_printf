/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:20:08 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 11:29:18 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_base(char type)
{
	if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	if (type == 'X')
		return ("0123456789ABCDEF");
	if (type == 'o')
		return ("01234567");
	if (type == 'b')
		return ("01");
	return ("0123456789");
}

int			parse_conv(char *conv, int fd, va_list list)
{
	t_struct	*data;
	size_t		i;

	i = 1;
	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	init_struct(data);
	if (is_flag(conv[i]))
		data->flags = parse_flags(conv + i, &i);
	if (conv[i] == '*')
		parse_star(&i, data, list);
	if (ft_isdigit(conv[i]))
		data->width = parse_width(conv + i, &i);
	if (conv[i] == '*')
		parse_star(&i, data, list);
	if (conv[i] == '.')
		data->preci = parse_preci(conv + i, &i);
	if (is_size(conv[i]))
		data->size = parse_size(conv + i, &i);
	data->type = conv[i];
	if (!(data->base = ft_strdup(get_base(data->type))))
		exit(EXIT_FAILURE);
	ft_strdel(&conv);
	return (convert(data, fd, list));
}
