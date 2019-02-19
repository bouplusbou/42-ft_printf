/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:43:02 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/02 16:15:36 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delete_struct(t_struct *data)
{
	ft_strdel(&data->flags);
	if (data->size)
		ft_strdel(&data->size);
	free(data);
	data = NULL;
}
