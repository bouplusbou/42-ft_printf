/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:57:57 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/02 13:30:02 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** concatenate a string with '0x' + '000..' + translation in 'addr'
** depending on '#' & '0' flags and precision
*/

char					*concat_addr(unsigned long arg)
{
	char	*concat;
	int		concat_size;
	char	*addr;
	int		addr_size;

	if (!(addr = ft_ulltoa_base(arg, "0123456789abcdef")))
		return (NULL);
	addr_size = ft_strlen(addr); // taille d'addr + 2 pour "0x"
	concat_size = addr_size + 2;
	if (!(concat = ft_strnew(concat_size)))
		return (NULL);
	ft_memcpy(concat + (concat_size - addr_size), addr, addr_size); // write upon the '0' the input translated into addr
	ft_memcpy(concat, "0x", 2);
	ft_strdel(&addr); // we don't need addr anymore, it is inside concat now
	// printf("concat:%s|\n", concat);
	return (concat);
}

/*
** create the final result:
** place the concatenated form of addr
*/

char					*create_res_addr(t_struct data, char *concat)
{
	char	*result;
	int		result_size;
	int		concat_size;

	concat_size = ft_strlen(concat);
	result_size = data.width > concat_size ? data.width : concat_size;	// Getting string size depending on width.
	result = ft_strnew(result_size);		// Creating string.
	ft_memset(result, ' ', result_size);	// Filling with spaces depending on flags.
	if (data.width > concat_size && !ft_strchr(data.flags, '-')) // colle a droite
		ft_memcpy(result + (result_size - concat_size), concat, concat_size);
	else // colle a gauche (si width <= output ou si flag -)
		ft_memcpy(result, concat, concat_size);
	return (result);
}

/*
** convert into addrdecimal, do all the transformations,
** print the result and return the size of the result
*/

int						conv_addr(t_struct *data, va_list list)
{
	int		result_size;
	char	*result;
	char	*concat;

	if (!(concat = concat_addr((unsigned long)va_arg(list, void*)))) // concatenate '0x' + '0's + input translated in addr
		return (0);
	if (!(result = create_res_addr(*data, concat))) // create the final result
		return (0);
	result_size = ft_strlen(result);
	ft_putstr(result); // print result
	ft_strdel(&result); // clean everything: result, concat, struct
	ft_strdel(&concat);
	delete_struct(data);
	return (result_size);
}
