/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:06:29 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/25 16:14:52 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

/* A supprimer */
#include <stdio.h>

typedef struct  s_struct
{
    char    *flags;
    int     width;
    int     precision;
    char    *size;
    char    type;
	char	*base;
	char	sign;
}               t_struct;

int     ft_printf(const char *format, ...);
int     treat_format(const char *format, va_list list);
void	printf_write(char c, int *len);
void	delete_struct(t_struct *data);
int		is_type(char c);
int		is_flag(char c);
int		is_precision(char c);
int		is_size(char c);
int		is_type(char c);
int		is_conv(char c);
int     treat_conv(char *str, size_t *j, int *len, va_list list);
int     parse_conv(char *conv, va_list list);
int		convert(t_struct *data, va_list list);
int		conv_id(t_struct *data, va_list list);
int		conv_f(t_struct *data, va_list list);
int		conv_p(t_struct *data, va_list list);
int		conv_s(t_struct *data, va_list list);
int		conv_c(t_struct *data, va_list list);
int		conv_oux(t_struct *data, va_list list);
int		conv_perc(t_struct *data);

#endif
