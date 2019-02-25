/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:30:05 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/25 09:40:45 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg_cs(t_struct data, va_list list)
{
	char	*arg;

	if (!(arg = ft_strnew(1))) // init arg quel que soit le type
		return (NULL);
	if (data.type == 'c') // si type 'c' remplir le seul char
	{
		arg[0] = (char)va_arg(list, int);
		return(arg);
	}
	else
	{
		ft_strdel(&arg); // si type 's', free arg et renvoyer directement l'arg de la list
		return (va_arg(list, char *));
	}
}

static char	*small_res_cs(t_struct data, char *arg)
{
	char	*small_res;
	int		len;

	len = data.precision >= 0 ? (size_t)data.precision : ft_strlen(arg); // tronquer le resultat en fonction de la precision
	if (!(small_res = ft_strnew(len)))
		return (NULL);
	ft_strncpy(small_res, arg, len);
	return (small_res);
}

static char	*create_res_cs(t_struct data, char *small_res)
{
	char	*result;
	int		len;
	int		i_cpy;

	len = data.width > (int)ft_strlen(small_res) ? data.width : (int)ft_strlen(small_res); // choisir la taille finale en fonction de la width
	if	(!(result = ft_strnew(len)))
		return (NULL);
	result = ft_memset(result, ' ', len);
	if (ft_strchr(data.flags, '-')) // placer a gauche si flag '-'
		i_cpy = 0;
	else
		i_cpy = len - ft_strlen(small_res); // sinon placer a droite
	ft_memcpy(result + i_cpy, small_res, ft_strlen(small_res));
	ft_strdel(&small_res); // small_res a forcement ete malloc avant si rentre dans cette fonction 
	return (result);	
}

int     conv_cs(t_struct *data, va_list list)
{
	int		result_len;
	char	*arg;
	char	*small_res;
	char	*result;
	
	if (!(arg = get_arg_cs(*data, list))) // recupere arg, si arg == NULL alors lui assigner la string "(null)"
		arg = ft_strdup("(null)");
	result_len = 0;
	if (arg) // protection du malloc ft_strdup("(null)") au dessus, si malloc OK alors go inside
	{
		small_res = small_res_cs(*data, arg); // tronque le resultat en fonction de la precision
		if (small_res && (result = create_res_cs(*data, small_res))) // si les malloc dans small_res_cs() et create_res_cs OK, go inside
		{
			ft_putstr(result);
			result_len = ft_strlen(result);
			ft_strdel(&result); // result a forcement ete malloc si arrive ici
		}
	}
	if (data->type == 'c' || (arg && !ft_strcmp(arg, "(null)"))) // arg a ete malloc que si type 'c' (dans get_arg_cs) ou ft_strdup("(null)") au dessus
		ft_strdel(&arg);
	delete_struct(data);
	return (result_len);
}
