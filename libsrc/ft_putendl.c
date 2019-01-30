/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:28:38 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/12 12:21:21 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static size_t	fts_strlen(char const *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

static	void	fts_putstr(char const *s)
{
	write(1, s, fts_strlen(s));
}

void			ft_putendl(char const *s)
{
	if (s)
	{
		fts_putstr(s);
		fts_putstr("\n");
	}
}
