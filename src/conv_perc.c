/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:35:11 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/02 15:21:58 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_perc(t_struct *data)
{
	int		result_size;
	char	*result;

	result_size = data->width > 1 ? data->width : 1;
	if (!(result = ft_strnew(result_size)))
		return (0);
	ft_memset(result, ' ', result_size);
	if (ft_strchr(data->flags, '-'))// colle a gauche
		result[0] = '%';
	else
		result[result_size - 1] = '%';
	ft_putstr(result);// print result
	ft_strdel(&result);// clean everything: result, concat, struct
	delete_struct(data);
	return (result_size);
}
