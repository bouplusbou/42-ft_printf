/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:43:02 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/22 12:07:27 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delete_struct(t_struct *data)
{
	// ft_strdel(&data->flags);
	// ft_strdel(&data->base);
	free(data->flags);
	free(data->base);
	if (data->size)
		// ft_strdel(&data->size);
	free(data);
	data = NULL;
}
