/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:22:31 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:45:57 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	start;
	int				end;

	start = 0;
	if (!s)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	while (ft_iswhitespace(s[start]) && s[start])
		start++;
	while (ft_iswhitespace(s[end]) && end > (int)start)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
