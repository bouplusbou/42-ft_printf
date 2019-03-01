/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:51:27 by bboucher          #+#    #+#             */
/*   Updated: 2019/03/01 13:51:28 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_struct
{
	char	*flags;
	int		width;
	int		preci;
	char	*size;
	char	type;
	char	*base;
	char	sign;
}				t_struct;

int				ft_printf(const char *format, ...);
int				treat_format(const char *format, va_list list);
void			init_struct(t_struct *data);
void			delete_struct(t_struct *data);
int				is_type(char c);
int				is_flag(char c);
int				is_preci(char c);
int				is_size(char c);
int				is_conv(char c);
int				parse_conv(char *conv, int fd, va_list list);
int				convert(t_struct *data, int fd, va_list list);
int				conv_f(t_struct *data, int fd, va_list list);
int				conv_p(t_struct *data, int fd, va_list list);
int				conv_s(t_struct *data, int fd, va_list list);
int				conv_c(t_struct *data, int fd, va_list list);
int				conv_id(t_struct *data, int fd, va_list list);
int				conv_boux(t_struct *data, int fd, va_list list);
int				conv_perc(t_struct *data, int fd);
uintmax_t		get_arg_boux(t_struct data, va_list list);
long double		get_arg_float(t_struct data, va_list list);
intmax_t		get_arg_decimal(t_struct data, va_list list);
char			find_sign_f(t_struct data, long double arg);
char			find_sign_id(t_struct data, int pos);
char			find_sign_boux(t_struct data, uintmax_t value);
void			parse_star(size_t *i, t_struct *data, va_list list);
int				parse_preci(char *conv, size_t *i, va_list list);
int				parse_width(char *conv, size_t *i);
char			*parse_size(char *conv, size_t *i);
char			*parse_flags(char *conv, size_t *i);

#endif
