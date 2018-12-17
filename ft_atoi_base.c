/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:23:38 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/17 17:51:39 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_find_value(char c, char *base, int baselen)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (baselen + 10);
}

int		ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	res;
	int	baselen;

	i = 0;
	if (!ft_check_base(base))
		return (0);
	baselen = 0;
	while (base[baselen])
		baselen++;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == ' '))
		i++;
	neg = 0;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (ft_find_value(str[i], base, baselen) < baselen && str[i])
	{
		res = res * baselen + ft_find_value(str[i], base, baselen);
		i++;
	}
	if (neg)
		res = -res;
	return (res);
}
