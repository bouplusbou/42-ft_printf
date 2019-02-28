/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:33:04 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/28 14:29:21 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_power(int nb, int power)
{
	long long	result;
	int			count;

	result = nb;
	count = 1;
	while (count < power)
	{
		result *= nb;
		count++;
	}
	return (result);
}
