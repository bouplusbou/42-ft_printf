/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:07:46 by bclaudio          #+#    #+#             */
/*   Updated: 2018/12/07 14:01:34 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static t_data	*new_data(int fd)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

static t_data	*get_data(t_data *data, int fd)
{
	t_data	*new;

	if (data->next && data->fd != fd)
		return (get_data(data->next, fd));
	if (data->fd == fd)
		return (data);
	new = new_data(fd);
	data->next = new;
	return (new);
}

static void		del_data(t_data **data, int fd)
{
	t_data	*target;
	t_data	*previous;

	target = *data;
	previous = NULL;
	while (target->fd != fd)
	{
		previous = target;
		target = target->next;
	}
	if (previous)
		previous->next = target->next;
	else
		*data = target->next;
	ft_strdel(&(target->str));
	free(target);
}

static int		get_line(t_data **data, char **line, int fd)
{
	t_data	*target;
	char	*str;
	char	*left;

	target = get_data(*data, fd);
	str = target->str;
	if (!*str)
	{
		del_data(data, fd);
		return (0);
	}
	left = ft_strchr(str, 10);
	if (left)
		*left = '\0';
	*line = ft_strdup(str);
	if (left)
	{
		target->str = ft_strdup(left + 1);
		ft_strdel(&str);
	}
	else
		ft_strdel(&(target->str));
	return (*line ? 1 : -1);
}

int				get_next_line(int const fd, char **line)
{
	static t_data	*data;
	t_data			*target;
	char			*buf;
	int				rd;

	rd = 1;
	if (!line || fd < 0 || (!data && !(data = new_data(fd)))
			|| !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	target = get_data(data, fd);
	while (rd > 0 && (!target->str ||
				(target->str && !ft_strchr(target->str, 10))))
	{
		ft_strclr(buf);
		rd = read(fd, buf, BUFF_SIZE);
		target->str = ft_strjoinf(&(target->str), &buf, target->str ? 1 : 0);
	}
	ft_strdel(&buf);
	if (rd == -1)
		return (-1);
	return (get_line(&data, line, fd));
}
