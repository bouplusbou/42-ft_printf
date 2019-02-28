/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:43:02 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 11:44:44 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delete_struct(t_struct *data)
{
	ft_strdel(&data->flags);
	ft_strdel(&data->base);
	ft_strdel(&data->size);
	free(data);
	data = NULL;
}

void	init_struct(t_struct *data)
{
	data->width = -1;
	data->preci = -1;
	data->type = '0';
	data->size = NULL;
	data->flags = NULL;
	data->base = NULL;
	data->sign = 'X';
}
