/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:39:18 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:48:33 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstback(t_list **alst, t_list *new)
{
	while ((*alst)->next)
	{
		*alst = (*alst)->next;
	}
	(*alst)->next = new;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *li;
	t_list *oli;

	li = (*f)(lst);
	oli = li;
	lst = lst->next;
	while (lst)
	{
		ft_lstback(&li, (*f)(lst));
		li = li->next;
		lst = lst->next;
	}
	return (oli);
}
