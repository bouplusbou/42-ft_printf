/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:05:57 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 11:39:08 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	return (ft_strchr("#0-+ ", c) != NULL);
}

int		is_preci(char c)
{
	return (ft_strchr(".0123456789", c) != NULL);
}

int		is_size(char c)
{
	return (ft_strchr("hljzL", c) != NULL);
}

int		is_type(char c)
{
	return (ft_strchr("cspdibouUxXf%", c) != NULL);
}

int		is_conv(char c)
{
	return (ft_strchr("#0-+ .0123456789hljzLcspdibouUxXf%*", c) != NULL);
}
