/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:24:27 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/27 15:03:56 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2, int flag)
{
	char *new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		new = ft_strdup(s1 ? s1 : s2);
	else
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
	}
	if (s1 && (flag == 1 || flag == 3))
		ft_strdel(&s1);
	if (s2 && (flag == 2 || flag == 3))
		ft_strdel(&s2);
	return (new);
}
