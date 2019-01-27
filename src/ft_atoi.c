/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:06:23 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/27 16:29:59 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\v'
			|| c == '\n'
			|| c == '\r'
			|| c == '\f');
}

int			ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int			ft_atoi(const char *s)
{
	int	neg;
	int	res;

	while (ft_isspace(*s))
		s++;
	neg = (*s == '-');
	if (*s == '-' || *s == '+')
		s++;
	res = 0;
	while (ft_isdigit(*s))
	{
		res *= 10;
		res += (*s - '0');
		s++;
	}
	return (neg ? -res : res);
}
