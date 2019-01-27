/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:20:08 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/27 17:28:36 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flags(char *str_flags, int *i)
{
	int l;

	l = 0;
	while (is_flag(str_flags[l]))
		l++;
	*i += l;
	return (ft_strndup(str_flags, l));
}

int		parse_width(char *str_width, int *i)
{
	int l;

	l = 0;
	while (is_width(str_width[l]))
		l++;
	*i += l;
	return (ft_atoi(ft_strndup(str_width, l)));
}

int		parse_precision(char *str_precision, int *i)
{
	int l;

	l = 1;
	while (is_precision(str_precision[l]))
		l++;
	*i += l;
	return (ft_atoi(ft_strndup(str_precision + 1, l)));
}

char	*parse_size(char *str_size, int *i)
{
	int	l;

	l = 0;
	while (is_size(str_size[l]))
		l++;
	*i += l;
	return (ft_strndup(str_size, l));
}

 /*
 ** Ne fonctionne que si les elements sont dans l'ordre
 ** %[flags][width][.precision][size]type
 */

int		parse_conv(char *conv, va_list args)
{
	t_struct	t_conv;
	int			i;

	i = 1;
	if (is_flag(conv[i]))
		t_conv.flags = parse_flags(conv + i, &i);
	else
		t_conv.flags = NULL;
	if (ft_isdigit(conv[i]))
		t_conv.width = parse_width(conv + i, &i);
	else
		t_conv.width = -1;
	if (conv[i] == '.')
		t_conv.precision = parse_precision(conv + i, &i);
	else
		t_conv.precision = -1;
	if (is_size(conv[i]))
		t_conv.size = parse_size(conv + i, &i);
	else
		t_conv.size = NULL;
	if (is_type(conv[i]))
		t_conv.type = conv[i];
	printf("|||");
	printf("\nflags:%s\n", t_conv.flags);
	printf("width:%d\n", t_conv.width);
	printf("precision:%d\n", t_conv.precision);
	printf("size:%s\n", t_conv.size);
	printf("type:%c\n", t_conv.type);
	printf("|||\n");
	(void)args;
	return (20);
	// return (convert(t_conv, args)));
}
