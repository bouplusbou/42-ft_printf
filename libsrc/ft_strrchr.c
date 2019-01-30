/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:35:01 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/16 12:44:03 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*match;

	match = NULL;
	while (*s)
	{
		if (*s == (char)c)
			match = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		match = (char *)s;
	return (match);
}
