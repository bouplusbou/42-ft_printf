/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:20:08 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 15:31:24 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_flags(char *conv, size_t *i)
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
			return (NULL);
		return (flags);
	}
	return (ft_strdup("FFF"));
}

static int	parse_width(char *conv, size_t *i)
{
	int		width_int;
	size_t	l;
	char	*width_str;

	l = 0;
	while (ft_isdigit(conv[l]))
		l++;
	*i += l;
	if (!(width_str = ft_strndup(conv, l)))
		return (0);
	width_int = ft_atoi(width_str);
	ft_strdel(&width_str);
	return (width_int);
}

static int	parse_precision(char *conv, size_t *i)
{
	int		precision_int;
	size_t	l;
	char	*precision_str;

	l = 1;
	while (is_precision(conv[l]))
		l++;
	*i += l;
	if (!(precision_str = ft_strndup(conv + 1, l)))
		return (0);
	precision_int = ft_atoi(precision_str);
	ft_strdel(&precision_str);
	return (precision_int);
}

static char	*parse_size(char *conv, size_t *i)
{
	char	*size;
	size_t	l;

	l = 0;
	while (is_size(conv[l]))
		l++;
	*i += l;
	if (!(size = ft_strndup(conv, l)))
		return (NULL);
	return (size);
}

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

static void	init_data_struct(t_struct *data)
{
	data->width = -1;
	data->precision = -1;
	data->type = '0';
	data->size = NULL;
	data->flags = NULL;
	data->base = NULL;
	data->sign = 'X';
}

static void	parse_star(size_t *i, t_struct *data, va_list list)
{

	int arg;
	
	arg = va_arg(list, int);
	if (arg < 0)
		ft_strjoinf(data->flags, "-", 0);
	data->width = arg < 0 ? -arg : arg;
	*i += 1;
}

int			parse_conv(char *conv, int fd, va_list list)
{
	t_struct	*data;
	size_t		i;

	i = 1;
	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	init_data_struct(data);
	if (is_flag(conv[i]))
		data->flags = parse_flags(conv + i, &i);
	if (conv[i] == '*')
		parse_star(&i, data, list);
	if (ft_isdigit(conv[i]))
		data->width = parse_width(conv + i, &i);
	if (conv[i] == '*')
		parse_star(&i, data, list);
	if (conv[i] == '.')
		data->precision = parse_precision(conv + i, &i);
	if (is_size(conv[i]))
		data->size = parse_size(conv + i, &i);
	data->type = conv[i];
	if (!(data->base = ft_strdup(get_base(data->type))))
		return (0);
	ft_strdel(&conv);
	return (convert(data, fd, list));
}
