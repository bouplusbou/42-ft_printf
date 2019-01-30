/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:47:27 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:43:00 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *str;

	size++;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
		str[size] = 0;
	return (str);
}
