/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:24:11 by bclaudio          #+#    #+#             */
/*   Updated: 2018/12/03 13:24:20 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strctrim(char const *s, char c)
{
	unsigned int	start;
	int				end;

	start = 0;
	if (!s)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	while (s[start] == c && s[start])
		start++;
	while (s[end] == c && end > (int)start)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
