/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:12:56 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/16 12:42:03 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	fts_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char			*ft_strcat(char *s1, const char *s2)
{
	int len;

	len = fts_strlen(s1);
	while (*s2)
		s1[len++] = *s2++;
	s1[len] = '\0';
	return (s1);
}
