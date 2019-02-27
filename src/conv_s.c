/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:15:09 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 15:22:34 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_res_s(t_struct data, char *arg)
{
	char	*small_res;
	int		len;

	len = data.precision >= 0 ? (size_t)data.precision : ft_strlen(arg); 		// tronquer le resultat en fonction de la precision
	if (!(small_res = ft_strnew(len)))
		return (NULL);
	ft_strncpy(small_res, arg, len);
	return (small_res);
}

static char	*create_res_s(t_struct data, char *small_res)
{
	char	*res;
	int		len;
	int		i_cpy;

	len = data.width > (int)ft_strlen(small_res) ? 
			data.width : (int)ft_strlen(small_res);						// choisir la taille finale en fonction de la width
	if (!(res = ft_strnew(len)))
		return (NULL);
	res = ft_memset(res, ' ', len);
	if (ft_strchr(data.flags, '-')) 									// placer a gauche si flag '-'
		i_cpy = 0;
	else
		i_cpy = len - ft_strlen(small_res); 							// sinon placer a droite
	ft_memcpy(res + i_cpy, small_res, ft_strlen(small_res));
	ft_strdel(&small_res); 												// small_res a forcement ete malloc avant si rentre dans cette fonction 
	return (res);	
}

int			conv_s(t_struct *data, int fd, va_list list)
{
	int		res_len;
	char	*arg;
	char	*small_res;
	char	*res;
	
	if (!(arg = va_arg(list, char *)))								// recupere arg, si arg == NULL alors lui assigner la string "(null)"
		arg = ft_strdup("(null)");
	res_len = 0;
	if (arg)														// protection du malloc ft_strdup("(null)") au dessus, si malloc OK alors go inside
	{
		if ((small_res = small_res_s(*data, arg))						
			&& (res = create_res_s(*data, small_res)))				// si les malloc dans small_res_s() et create_res_s OK, go inside
		{
				ft_putstr_fd(res, fd);
				res_len = ft_strlen(res);
				ft_strdel(&res);									// res a forcement ete malloc si arrive ici
		}
	}
	if (arg && !ft_strcmp(arg, "(null)"))							// arg a ete malloc que si ft_strdup("(null)") au dessus
		ft_strdel(&arg);
	return (res_len);
}
