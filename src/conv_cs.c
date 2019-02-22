/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:30:05 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/22 18:52:34 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg_cs(t_struct data, va_list list)
{
																																					// LEAKS ARG OK
	char	*arg;

	if (!(arg = ft_strnew(1)))
		return (NULL);
	if (data.type == 'c')
	{
		arg[0] = (char)va_arg(list, int);
		return(arg);
	}
	else
		return (va_arg(list, char *));
																																											// tester return NULL
}

static char	*small_res_cs(t_struct data, char *arg)
{
																																					// LEAKS SMALL_RES OK
	char	*small_res;
	int		len;

	len = data.precision >= 0 ? (size_t)data.precision : ft_strlen(arg);
	if (!(small_res = ft_strnew(len)))
		return (NULL);
	ft_strncpy(small_res, arg, len);
																																											// tester de return NULL
	return (small_res);
}

static char	*create_res_cs(t_struct data, char *small_res)
{
	char	*result;
	int		len;
	int		i_cpy;

	len = data.width > (int)ft_strlen(small_res) ? data.width : (int)ft_strlen(small_res);
	if	(!(result = ft_strnew(len)))
		return (NULL);
	result = ft_memset(result, ' ', len);
	if (ft_strchr(data.flags, '-'))
		i_cpy = 0;
	else
		i_cpy = len - ft_strlen(small_res);
	ft_memcpy(result + i_cpy, small_res, ft_strlen(small_res));
	return (result);	
}

int     conv_cs(t_struct *data, va_list list)
{
	char	*small_res;
	char	*result;
	int		result_len;
	char	*arg;
	
	result_len = 1;
	arg = get_arg_cs(*data, list);
	if (!arg)
	{
		if (data->precision < 0 || data->precision > 5)
		{
			if (!(arg = ft_strdup("(null)")))
				result_len = 0;		
		}
		else
			if (!(arg = ft_strdup("")))
				result_len = 0;		
	}
	if (result_len) // if result_len == 1, malloc went good, we can keep going
	{
		small_res = small_res_cs(*data, arg);
		result = create_res_cs(*data, small_res);
		ft_strdel(&small_res);
		ft_putstr(result);
		result_len = ft_strlen(result);
		ft_strdel(&result);
	}
	if (data->type == 'c')
		ft_strdel(&arg);
	delete_struct(data);
	return (result_len);
}

// trouver comment concilier les 'c' et les 's' ('null' et '') aui doivent free arg
// quand les le reste des 's' ne doit pas free arg