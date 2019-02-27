/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:15:15 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 15:22:16 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_res_c(t_struct data, char arg, int res_len)
{
	char	*res;

	if (!(res = ft_strnew(res_len)))
		return (NULL);
	res = ft_memset(res, ' ', res_len);
	if (ft_strchr(data.flags, '0'))				// remplir de '0' si flag '0', pas obligatoire mais gere
		res = ft_memset(res, '0', res_len);
	if (ft_strchr(data.flags, '-')) 			// placer a gauche si flag '-'
		res[0] = arg;
	else
		res[res_len - 1] = arg;					// sinon placer a droite
	return (res);	
}

void		print_res_c(char *res, int fd, int res_len)
{
	int	i;

	i = 0;
	while (i < res_len)
		write(fd, &res[i++], 1);
}

int			conv_c(t_struct *data, int fd, va_list list)
{
	int		res_len;
	char	arg;
	char	*res;
	
	arg = (char)va_arg(list, int);					
	res_len = data->width > 1 ? data->width : 1; 	// la len du resultat final depend de la width, pas de la precision
	res = create_res_c(*data, arg, res_len);		// creation du res final
	print_res_c(res, fd, res_len);					// doit print les char speciaux, don't believe the '\0', don't use ft_putstr
	ft_strdel(&res);								// free res et delete la struct
	return (res_len);
}
