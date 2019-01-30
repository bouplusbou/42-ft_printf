/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:40:54 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/23 20:39:36 by alastri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	t_list *next;

	next = (*alst)->next;
	(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
	*alst = next;
}
