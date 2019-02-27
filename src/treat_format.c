/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:38 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 10:47:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_fd(char *format, size_t *j, va_list list)
{
	if (!ft_strncmp(format, "{fd}", 4)) // tester avec un format vide ou un char
	{
		*j += 4;
		return (va_arg(list, int));
	}
	return (1);
}

int	get_color(char *str, size_t len, int fd)
{
	int is_color;

	is_color = 0;
	if (!len)
		return (0);
	else if ((is_color = !ft_strncmp("red", str, len)))
		ft_putstr_fd("\033[31m", fd);
	else if ((is_color = !ft_strncmp("green", str, len)))
		ft_putstr_fd("\033[32m", fd);
	else if ((is_color = !ft_strncmp("yellow", str, len)))
		ft_putstr_fd("\033[33m", fd);
	else if ((is_color = !ft_strncmp("blue", str, len)))
		ft_putstr_fd("\033[34m", fd);
	else if ((is_color = !ft_strncmp("magenta", str, len)))
		ft_putstr_fd("\033[35m", fd);
	else if ((is_color = !ft_strncmp("white", str, len)))
		ft_putstr_fd("\033[m", fd);
	else if ((is_color = !ft_strncmp("bold", str, len)))
		ft_putstr_fd("\e[1m", fd);
	else if ((is_color = !ft_strncmp("underline", str, len)))
		ft_putstr_fd("\e[4m", fd);
	else if ((is_color = !ft_strncmp("eof", str, len)))
		ft_putstr_fd("\e[0m", fd);
	return (is_color);
}

int	treat_color(char *str, size_t *j, int fd)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (str[i] && end == 0)
	{
		if (str[i] == '}')
			end = 1;
		i++;
	}
	if (end)
	{
		if (get_color(str + 1, i - 2, fd))
		{
			*j += i;
			return (0);
		}
	}
	ft_putchar_fd('{', fd);
	*j += 1;
	return (1);
}

int	treat_conv(char *format, size_t *j, int fd, va_list list)
{
	size_t	i;
	int		type;
	char	*conv;

	i = 1;
	type = 0;
	while (format[i] && is_conv(format[i]) && type == 0)
	{
		if (is_type(format[i]))
			type = 1;
		i++;
	}
	if (type)
	{
		*j += i;
		if (!(conv = ft_strndup(format, i)))
			return (0);
		return (parse_conv(conv, fd, list));
	}
	ft_putchar_fd('%', fd);
	*j += 1;
	return (1);
}

int	treat_format(const char *format, va_list list)
{
	int		len;
	int		fd;
	size_t	i;

	len = 0;
	i = 0;
	fd = 1;
	if (format[0] == '{')
		fd = treat_fd((char*)format, &i, list);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
			len += treat_conv(((char*)format + i), &i, fd, list);
		else if (format[i] == '{')
			len += treat_color(((char*)format + i), &i, fd);
		else
		{
			len++;
			ft_putchar_fd(format[i++], fd);
		}
	}
	return (len);
}
