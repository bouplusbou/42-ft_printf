/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:57:57 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/22 08:41:56 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*small_res_addr(t_struct data, unsigned long arg)
{
	char	*concat;
	char	*addr;

	if (!(addr = ft_ulltoa_base(arg, data.base)))
		return (NULL);
	concat = ft_strdup("0x");
	concat = ft_strjoinf(&concat, &addr, 3);
	return (concat);
}

static char					*create_res_addr(t_struct data, char *concat)
{
	char	*result;
	int		result_len;
	int		concat_len;

	concat_len = ft_strlen(concat);
	result_len = data.width > concat_len ? data.width : concat_len;	// Getting string len depending on width.
	result = ft_strnew(result_len);		// Creating string.
	ft_memset(result, ' ', result_len);	// Filling with spaces depending on flags.
	if (data.width > concat_len && !ft_strchr(data.flags, '-')) // colle a droite
		ft_memcpy(result + (result_len - concat_len), concat, concat_len);
	else // colle a gauche (si width <= output ou si flag -)
		ft_memcpy(result, concat, concat_len);
	return (result);
}

int						conv_p(t_struct *data, va_list list)
{
	int		result_len;
	char	*result;
	char	*small_res;

	if (!(small_res = small_res_addr(*data, (unsigned long)va_arg(list, void*)))) // small_resenate '0x' + '0's + input translated in addr
		return (0);
	if (!(result = create_res_addr(*data, small_res))) // create the final result
		return (0);
	result_len = ft_strlen(result);
	ft_putstr(result); // print result
	ft_strdel(&result); // clean everything: result, small_res, struct
	ft_strdel(&small_res);
	delete_struct(data);
	return (result_len);
}
