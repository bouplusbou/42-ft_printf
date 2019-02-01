/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 10:34:17 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/01 10:50:50 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_char_index(char c, char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
