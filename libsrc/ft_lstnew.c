/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:59:13 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:50:17 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *li;

	if (!(li = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		li->content = NULL;
		li->content_size = 0;
	}
	else
	{
		if (!(li->content = (void *)ft_memalloc(content_size)))
		{
			ft_memdel((void**)li);
			return (NULL);
		}
		ft_memmove(li->content, content, content_size);
		li->content_size = content_size;
	}
	li->next = NULL;
	return (li);
}
