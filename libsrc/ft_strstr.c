/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:35:40 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/16 12:44:42 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		j = 0;
		while (haystack[j] == needle[j])
		{
			j++;
			if (!needle[j])
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
