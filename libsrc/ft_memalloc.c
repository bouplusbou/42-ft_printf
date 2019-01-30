/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:23:14 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:49:20 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(ptr = (void *)malloc(size)))
		return (NULL);
	while (size--)
		((unsigned char *)ptr)[size] = 0;
	return (ptr);
}
