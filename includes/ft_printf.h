/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:06:29 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 15:46:59 by bclaudio         ###   ########.fr       */
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
    int     preci;
    char    *size;
    char    type;
	char	*base;
	char	sign;
}               t_struct;

int     ft_printf(const char *format, ...);
int     treat_format(const char *format, va_list list);
int		printf_write(char c);
void	delete_struct(t_struct *data);
int		is_type(char c);
int		is_flag(char c);
int		is_preci(char c);
int		is_size(char c);
int		is_type(char c);
int		is_conv(char c);
int     parse_conv(char *conv, int fd, va_list list);
int		convert(t_struct *data, int fd, va_list list);
int		conv_id(t_struct *data, int fd, va_list list);
int		conv_f(t_struct *data, int fd, va_list list);
int		conv_p(t_struct *data, int fd, va_list list);
int		conv_s(t_struct *data, int fd, va_list list);
int		conv_c(t_struct *data, int fd, va_list list);
int		conv_boux(t_struct *data, int fd, va_list list);
int		conv_perc(t_struct *data, int fd);

#endif
