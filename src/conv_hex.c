/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:50:37 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/29 19:57:57 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*concat_target(t_struct data, char *target) // concat hexa + 0x + precision (0)
{
	char	*result;
	int		size;
	
	size = ft_strchr(data.flags, '#') ? ft_strlen(target) + 2 : ft_strlen(target); // + 2 si flag #
	size += data.precision > (int)ft_strlen(target) ? data.precision - ft_strlen(target) : 0; // + le nombre de 0 si precision > strlen(hexa)
	result = ft_strnew(size);		// Creating string
	ft_memset(result, '0', size);	// Filling with 0
	ft_strchr(data.flags, '#') && data.precision < 0 ? result[1] = data.type : 1;
	ft_memcpy(result + (size - ft_strlen(target)), target, ft_strlen(target));
	return (result);
}

int	convert_hex(t_struct data, unsigned int target)
{
	char	*result;
	char	*hexa;
	int		result_size;

	hexa = concat_target(data, ft_itoa_base(target, data.type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	// printf("hexa:%s|\n", hexa);
	result_size = data.width > (int)ft_strlen(hexa) ? data.width : ft_strlen(hexa); // prend le plus grand entre la width ou la taille d'hexa modifiee
	// printf("result_size:%d\n", result_size);
	result = ft_strnew(result_size);		// Creating string.
	ft_memset(result, (ft_strchr(data.flags, '0') && data.precision < 0) ? '0' : ' ', result_size);	// Filling with spaces depending on flags.
	if (!ft_strchr(data.flags, '-')) // colle a droite (si width >)
		ft_memcpy(result + (result_size - ft_strlen(hexa)), hexa, ft_strlen(hexa));
	else // colle a gauche (si width <= output ou si flag -)
		ft_memcpy(result + ft_strlen(hexa), hexa, ft_strlen(hexa));
	ft_strchr(data.flags, '#') && data.precision > 0 ? result[1] = data.type : 1;
	printf("result:%s|\n", result);
	
	
	
	
	// ft_putstr("Result of char(p) conversion : []");
	
	
	
	
	
	
	// if (ft_strchr(data.flags, '0') || data.precision == ft_strchr(data.flags, '#') ? hexa_size - 2 : hexa_size)
	// 	ft_memset(result, '0', hexa_size);
	// else
	// ft_putstr(result);	// Printing result.
	// // ft_putstr("[]");
	return (20);
	// return (result_size);
}

	// si pas de precision et pas de width = strlen(hexa)
	// si precision > width ? precision
		// si precision > strlen(hexa) ? precision
			// si # ? precision + 2
		// si precision < strlen(hexa) ? strlen(hexa)
			// si # ? strlen(hexa) + 2
	// si width > precision ? width
		// si width < strlen(hexa) ? strlen(hexa)