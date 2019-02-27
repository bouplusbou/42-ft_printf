/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:38:32 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 17:22:58 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*small_res_decimal(t_struct data, intmax_t arg)
{
	char	*small_res;
	int		small_res_len;
	char	*arg_str;
	int		arg_str_len;

	if (!(arg_str = ft_uimxtoa_base(arg < 0 ? -arg : arg, data.base))) 			// Converti la valeur brut en string (en prenant en compte la base donnee)
		return (NULL);
	arg_str_len = ft_strlen(arg_str);
	small_res_len = arg_str_len + (data.sign ? 1 : 0); 								// Ajoute 1 a small_res_len si un signe est requis
	if (data.preci > (int)arg_str_len) 											// add enough space for '0's if needed (if preci is longer than input)
		small_res_len += data.preci - arg_str_len;
	if (!(small_res = ft_strnew(small_res_len)))
		return (NULL);
	ft_memset(small_res, '0', small_res_len); 										// fill '0' BEST LIGNE EU
	ft_memcpy(small_res + (small_res_len - arg_str_len), arg_str, arg_str_len); 	// write upon the '0' the input translated into arg_str
	ft_strdel(&arg_str); 															// we don't need arg_str anymore, it is inside small_res now
	return (small_res);
}

static char				*create_res_deci(t_struct data, int res_len, char *small_res)
{
	char	*res;
	int		small_res_len;

	if (!res_len || !(res = ft_strnew(res_len))) 												// if res_len is 0 return NULL directly
		return (NULL);
	ft_memset(res, ' ', res_len); 																// fill with spaces
	if (ft_strchr(data.flags, '0') && data.preci < 0 
		&& !ft_strchr(data.flags, '-')) 														// flag '0' without preci and no flag '-' => fill everything with '0' (La preci cancel le 0)
		ft_memset(res, '0', res_len);
	small_res_len = ft_strlen(small_res);
	if (ft_strchr(data.flags, '-')) 																	// put to the left if flag '-'
		ft_memcpy(res, small_res, small_res_len);
	else
		ft_memcpy(res + (res_len - small_res_len), small_res, small_res_len); 					// put to the right otherwise
	if (data.sign) 																						// Si un signe est requis
		res[ft_get_char_index('0', res)] = data.sign; 										// Placage du signe sur le premier 0 (place dans la petite partie si un signe est requis sans taille avec 0)
	return (res);
}

int						conv_id(t_struct *data, int fd, va_list list)
{
	int				result_len;
	char			*result;
	char			*small_res;
	intmax_t		arg;

	arg = get_arg_decimal(*data, list); 									// Recupere la valeur caste avec le size donnee
	data->sign = find_sign_id(*data, arg >= 0 ? 1 : 0); 						// Defini le signe (ou space) si besoin. 0 si pas de signe
	result_len = 0;
	if ((small_res = small_res_decimal(*data, arg))) 						// Converti le valeur en brut (Sans prendre en compte la size (petit resultat))
	{
		if (!ft_strcmp(small_res, "0") && data->preci == 0) 			// if input is '0' with a preci of 0, write nothing at all
			small_res[0] = '\0';
		result_len = ft_strlen(small_res);
		if (data->width > (int)ft_strlen(small_res)) 						// choose the result's size: the longer between width and small_res (pour malloc de la grande partie)
			result_len = data->width;
		if (!(result = create_res_deci(*data, result_len, small_res)))	// create the final result
			result_len = 0;
		ft_putstr_fd(result, fd); 													// print result
		ft_strdel(&result); 												// clean everything: result, small_res, struct
		ft_strdel(&small_res);
	}
	return (result_len);
}
