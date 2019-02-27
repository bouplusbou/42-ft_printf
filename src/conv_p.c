/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:57:57 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 15:22:28 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_res_addr(t_struct data, unsigned long arg)
{
	char	*concat;
	char	*addr;

	if (!(addr = ft_ulltoa_base(arg, data.base)))
		return (NULL);
	concat = ft_strdup("0x");
	concat = ft_strjoinf(concat, addr, 3);
	return (concat);
}

static char	*create_res_addr(t_struct data, char *concat)
{
	char	*result;
	int		result_len;
	int		concat_len;

	concat_len = ft_strlen(concat);
	result_len = data.width > concat_len ? data.width : concat_len;			// Getting string len depending on width.
	if (!(result = ft_strnew(result_len)))									// Creating string.
		return (NULL);
	ft_memset(result, ' ', result_len);										// Filling with spaces depending on flags.
	if (data.width > concat_len && !ft_strchr(data.flags, '-')) 			// colle a droite
		ft_memcpy(result + (result_len - concat_len), concat, concat_len);
	else 																	// colle a gauche (si width <= output ou si flag -)
		ft_memcpy(result, concat, concat_len);
	return (result);
}

int			conv_p(t_struct *data, int fd, va_list list)
{
	int		result_len;
	char	*result;
	char	*small_res;

	if (!(small_res = small_res_addr(*data, (unsigned long)va_arg(list, void*)))
		|| (!(result = create_res_addr(*data, small_res)))) 						// create the final result
		result_len = 0;
	else
	{
		result_len = ft_strlen(result);
		ft_putstr_fd(result, fd); 															// print result
		ft_strdel(&result); 														// clean everything: result, small_res, struct
	}
	ft_strdel(&small_res);
	return (result_len);
}
