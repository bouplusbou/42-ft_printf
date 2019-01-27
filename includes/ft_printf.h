/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:06:29 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/27 16:12:47 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

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
int     ft_strlen(const char *s);
int     ft_isdigit(int c);
int     treat_conv(char *str, int *j, int *len, va_list args);
int		is_type(char c);
char	*ft_strndup(const char *s1, int len);
int     parse_conv(char *conv, va_list args);
int		is_flag(char c);
int		is_width(char c);
int		is_precision(char c);
int		is_size(char c);
int		is_type(char c);
int		is_conv(char c);
int     ft_atoi(const char *s);
int     convert(t_struct t_conv, va_list args);

#endif