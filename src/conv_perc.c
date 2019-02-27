/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:02:49 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 15:26:25 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_perc(t_struct *data, int fd)
{
	int		result_size;
	char	*result;

	result_size = data->width > 1 ? data->width : 1;
	if (!(result = ft_strnew(result_size)))
		result_size = 0;
	else
	{
		ft_memset(result, ' ', result_size);
		if (ft_strchr(data->flags, '-'))				// colle a gauche
			result[0] = '%';
		else
			result[result_size - 1] = '%';
		ft_putstr_fd(result, fd);								// print result
		ft_strdel(&result);								// clean everything: result, concat, struct
	}
	return (result_size);
}
