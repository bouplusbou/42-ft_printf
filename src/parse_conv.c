/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:20:08 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/15 18:14:47 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *parse_flags(char *str_flags, int *i)
{
	int l;

	l = 0;
	while (is_flag(str_flags[l]))
		l++;
	*i += l;
	return (ft_strndup(str_flags, l));
}

int parse_width(char *str_width, int *i)
{
	int l;

	l = 0;
	while (ft_isdigit(str_width[l]))
		l++;
	*i += l;
	return (ft_atoi(ft_strndup(str_width, l)));
}

int parse_precision(char *str_precision, int *i)
{
	int l;

	l = 1;
	while (is_precision(str_precision[l]))
		l++;
	*i += l;
	return (ft_atoi(ft_strndup(str_precision + 1, l)));
}

char *parse_size(char *str_size, int *i)
{
	int l;

	l = 0;
	while (is_size(str_size[l]))
		l++;
	*i += l;
	return (ft_strndup(str_size, l));
}

char *get_base(char type)
{
	if (type == 'd' || type == 'i')
		return ("0123456789");
	if (type == 'x')
		return ("0123456789abcdef");
	if (type == 'X')
		return ("0123456789ABCDEF");
	if (type == 'o')
		return ("01234567");
	return (NULL);
}

int parse_conv(char *conv, va_list args)
{
	t_struct *data;
	int i;

	i = 1;
	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	data->flags = ft_strdup("X");
	if (is_flag(conv[i]))
		data->flags = parse_flags(conv + i, &i);
	data->width = -1;
	if (ft_isdigit(conv[i]))
		data->width = parse_width(conv + i, &i);
	data->precision = -1;
	if (conv[i] == '.')
		data->precision = parse_precision(conv + i, &i);
	data->size = NULL;
	if (is_size(conv[i]))
		data->size = parse_size(conv + i, &i);
	data->type = conv[i];
	data->base = ft_strdup(get_base(data->type));
	return (convert(data, args));
}
