/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:06:29 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/29 19:57:58 by bboucher         ###   ########.fr       */
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
}               t_struct;

int     ft_printf(const char *format, ...);
int     treat_format(const char *format, va_list args);
void	printf_write(char c, int *len);
int     treat_conv(char *str, size_t *j, int *len, va_list args);
int		is_type(char c);
int     parse_conv(char *conv, va_list args);
int		is_flag(char c);
int		is_precision(char c);
int		is_size(char c);
int		is_type(char c);
int		is_conv(char c);
int		convert(t_struct data, va_list list);
int		convert_char(t_struct data, int target);
int 	convert_ptr(t_struct data, void *target);
int		convert_hex(t_struct data, unsigned int target);
char	*ft_ultoa_base(unsigned long nbr, const char *basestr);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
