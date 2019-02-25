/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_oux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:12:50 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/25 13:19:34 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	get_arg_oux(t_struct data, va_list list)
{
	unsigned long long int arg;

	arg = 0;
	if (!data.size)
		arg = va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "ll"))
		arg = va_arg(list, unsigned long long int);
	else if (ft_strstr(data.size, "l"))
		arg = va_arg(list, unsigned long int);
	else if (ft_strstr(data.size, "h") && !ft_strstr(data.size, "hh"))
		arg = (unsigned short int)va_arg(list, unsigned int);
	else if (ft_strstr(data.size, "hh"))
		arg = (unsigned char)va_arg(list, unsigned int);
	return (arg);
}

static char						find_sign(t_struct data, unsigned long long int value)
{
	if (ft_strchr(data.flags, '#') && value != 0)
	{
		if (data.type == 'x')
			return ('x'); 			// a placer en +1
		if (data.type == 'X')
			return ('X');
		if (data.type == 'o')
			return ('0');
	}
	return (0);
}

static char						*small_res_oux(t_struct data, unsigned long long int arg)
{
	char	*small_res;
	int		small_res_len;
	char	*arg_str;
	int		arg_str_len;

	if (!(arg_str = ft_ulltoa_base(arg, data.base))) 							// Converti la valeur brut en string (en prenant en compte la base donnee)
		return (NULL);
	arg_str_len = ft_strlen(arg_str);
	small_res_len = arg_str_len; 												// Ajoute 1 a small_res_len si un signe est requis
	if (data.sign)
	{
		if (data.type == 'x' || data.type == 'X')
			small_res_len += 2; 												// Ajoute 1 a small_res_len si un signe est requis
		else
			small_res_len += 1;
	}
	if (data.precision > (int)arg_str_len) 										// add enough space for '0's if needed (if precision is longer than input)
		small_res_len += data.precision - arg_str_len;
	if (!(small_res = ft_strnew(small_res_len)))
		return (NULL);
	ft_memset(small_res, '0', small_res_len);									// fill '0' BEST LIGNE EU
	ft_memcpy(small_res + (small_res_len - arg_str_len), arg_str, arg_str_len); // write upon the '0' the input translated into arg_str
	ft_strdel(&arg_str);														// we don't need arg_str anymore, it is inside small_res now
	return (small_res);
}

static char						*create_res_oux(t_struct data, int res_len, char *small_res)
{
	char	*res;
	int		small_res_len;
	int		sign_i;

	if (!res_len || !(res = ft_strnew(res_len))) 								// if res_len is 0 return NULL directly
		return (NULL);
	ft_memset(res, ' ', res_len);											 	// fill with spaces
	if (ft_strchr(data.flags, '0') 
		&& data.precision < 0 && !ft_strchr(data.flags, '-'))					// flag '0' without precision and no flag '-' => fill everything with '0' (La precision cancel le 0)
		ft_memset(res, '0', res_len);
	small_res_len = ft_strlen(small_res);
	if (ft_strchr(data.flags, '-')) 											// put to the left if flag '-'
		ft_memcpy(res, small_res, small_res_len);
	else
		ft_memcpy(res + (res_len - small_res_len), small_res, small_res_len); 	// put to the right otherwise
	if (data.sign)																// Si un signe est requis
	{
		sign_i = ft_get_char_index('0', res);
		if (data.type == 'x' || data.type == 'X')
			sign_i++;
		res[sign_i] = data.sign; 												// Placage du signe sur le premier 0 (place dans la petite partie si un signe est requis sans taille avec 0)
	}
	return (res);
}

int								conv_oux(t_struct *data, va_list list)
{
	int						result_len;
	char					*result;
	char					*small_res;
	unsigned long long int	arg;

	arg = get_arg_oux(*data, list);				 						// Recupere la valeur caste avec le size donnee
	data->sign = find_sign(*data, arg);			  						// Defini le signe (ou space) si besoin. 0 si pas de signe
	result_len = 0;
	if ((small_res = small_res_oux(*data, arg)))						// Converti la valeur en brut (Sans prendre en compte la size (petit resultat))
	{
		if (!ft_strcmp(small_res, "0") && data->precision == 0) 		// if input is '0' with a precision of 0, write nothing at all
		{
			if (ft_strchr(data->flags, '#'))
				small_res[0] = data->type == 'o' ? '0' : '\0';
			else
				small_res[0] = data->type == 'o' ? '\0' : '0';
		}
		result_len = ft_strlen(small_res);
		if (data->width > (int)ft_strlen(small_res)) 					// choose the result's size: the longer between width and small_res (pour malloc de la grande partie)
			result_len = data->width;
		if (!(result = create_res_oux(*data, result_len, small_res)))	// create the final result
			result_len = 0;
		ft_putstr(result); 												// print result
		ft_strdel(&result);												// clean everything: result, small_res, struct
		ft_strdel(&small_res);
	}
	delete_struct(data);
	return (result_len);
}
