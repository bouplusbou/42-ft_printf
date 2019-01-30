/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:52:35 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/21 17:59:59 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static size_t	fts_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

static char		*fts_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (*src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}

char			*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = ft_strnew(fts_strlen(s1))))
		return (NULL);
	fts_strcpy(s2, s1);
	return (s2);
}
