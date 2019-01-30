/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:31:21 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/09 12:54:04 by bclaudio         ###   ########.fr       */
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

static	void	fts_putstr_fd(char const *s, int fd)
{
	write(fd, s, fts_strlen(s));
}

void			ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		fts_putstr_fd(s, fd);
		fts_putstr_fd("\n", fd);
	}
}
