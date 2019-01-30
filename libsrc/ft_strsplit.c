/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:51:09 by bclaudio          #+#    #+#             */
/*   Updated: 2018/11/19 14:46:22 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		ft_countwords(const char *s, const char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_charequ(*s, c))
			s++;
		if (*s && !ft_charequ(*s, c))
			count++;
		while (*s && !ft_charequ(*s, c))
			s++;
	}
	return (count);
}

static int		ft_wordlen(const char *s, const char c)
{
	int count;

	count = 0;
	while (*s && !ft_charequ(*s++, c))
		count++;
	return (count);
}

static void		ft_clean(char **array, int delcount)
{
	int i;

	i = 0;
	while (i < delcount)
		ft_strdel(&array[i++]);
	ft_strdel(&array[i]);
}

char			**ft_strsplit(const char *s, const char c)
{
	int		i;
	int		wordscount;
	char	**array;

	if (!s)
		return (NULL);
	i = 0;
	wordscount = ft_countwords(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * wordscount + 1)))
		return (NULL);
	array[wordscount] = 0;
	while (i < wordscount)
	{
		while (*s && ft_charequ(*s, c))
			s++;
		if (!(array[i] = ft_strsub(s, 0, ft_wordlen(s, c))))
		{
			ft_clean(array, i);
			return (NULL);
		}
		s += ft_wordlen(s, c);
		i++;
	}
	return (array);
}
