/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:50:37 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/30 13:28:46 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Renvoie l'index de la premiere occurence trouvee
*/

int	ft_find_index(const char *s, int c)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

char	*concat_target(t_struct data, char *target) // concat hexa + 0x + precision (0)
{
	char	*result;
	int		size;
	
	size = ft_strchr(data.flags, '#') ? ft_strlen(target) + 2 : ft_strlen(target); // + 2 si flag #
	size += data.precision > (int)ft_strlen(target) ? data.precision - ft_strlen(target) : 0; // + le nombre de 0 si precision > strlen(hexa)
	result = ft_strnew(size);		// Creating string
	ft_memset(result, '0', size);	// Filling with 0
	// ft_strchr(data.flags, '#') && data.precision < 0 ? result[1] = data.type : 1;
	ft_memcpy(result + (size - ft_strlen(target)), target, ft_strlen(target));
	return (result);
}

int	convert_hex(t_struct data, unsigned int target)
{
	char	*result;
	char	*hexa;
	int		result_size;

	hexa = concat_target(data, ft_itoa_base(target, data.type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	result_size = data.width > (int)ft_strlen(hexa) ? data.width : ft_strlen(hexa); // prend le plus grand entre la width ou la taille d'hexa modifiee
	result = ft_strnew(result_size);		// Creating string.
	ft_memset(result, (ft_strchr(data.flags, '0') && data.precision < 0) ? '0' : ' ', result_size);	// Filling with spaces depending on flags.
	if (!ft_strchr(data.flags, '-')) // colle a droite (si width >)
		ft_memcpy(result + (result_size - ft_strlen(hexa)), hexa, ft_strlen(hexa));
	else // colle a gauche (si width <= output ou si flag -)
		ft_memcpy(result, hexa, ft_strlen(hexa));
	if (ft_strchr(data.flags, '#'))
		result[ft_find_index(result, '0') + 1] = data.type; // si #, remplacer le 2e '0' par un 'x' ou 'X'
	// printf("result:%s|\n", result);	// Printing result.
	// ft_putstr("Result of char(p) conversion : []");
	// ft_putstr(result);	// Printing result.
	return (ft_strlen(result));
}
