/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:50:37 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/29 13:16:15 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_ptr(t_struct data, void *target)
{
	char	*result;
	char	*hexa;
	int		result_size;
	int		hexa_size;
	
	hexa = ft_ultoa_base((unsigned long)target, "0123456789abcdef");
	hexa_size = (int)ft_strlen(hexa) + 2; // taille d'hexa + 2 pour "0x"
	result_size = data.width > hexa_size ? data.width : hexa_size;	// Getting string size depending on width.
	result = ft_strnew(result_size);		// Creating string.
	ft_memset(result, ' ', result_size);	// Filling with spaces depending on flags.
	if (data.width > hexa_size && !ft_strchr(data.flags, '-')) // colle a droite (si width >)
	{
		ft_memcpy(result + (result_size - ft_strlen(hexa)), hexa, ft_strlen(hexa));
		ft_memcpy(result + (result_size - ft_strlen(hexa) - 2), "0x", 2);
	}
	else // colle a gauche (si width <= output ou si flag -)
	{
		ft_memcpy(result + 2, hexa, ft_strlen(hexa));
		ft_memcpy(result, "0x", 2);
	}
	// ft_putstr("Result of char(p) conversion : []");
	ft_putstr(result);	// Printing result.
	// ft_putstr("[]");
	return (result_size);
}
