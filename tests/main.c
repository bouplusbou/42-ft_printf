/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/22 08:28:55 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int		nb;
	char	c;

	nb = 0;
	c = 'W';
	printf("\n===|%5p$\n", &nb);
	ft_printf(">>>|%5p$\n", &nb);
	printf("\n===|%-15p$\n", &nb);
	ft_printf(">>>|%-15p$\n", &nb);
	printf("\n===|%-5p$\n", &nb);
	ft_printf(">>>|%-5p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%-18p$\n", &nb);
	ft_printf(">>>|%-18p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%5p$\n", &c);
	ft_printf(">>>|%5p$\n", &c);
	printf("\n===|%-15p$\n", &c);
	ft_printf(">>>|%-15p$\n", &c);
	printf("\n===|%-5p$\n", &c);
	ft_printf(">>>|%-5p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%-18p$\n", &c);
	ft_printf(">>>|%-18p$\n", &c);
	printf("\n===|%5p$\n", &nb);
	ft_printf(">>>|%5p$\n", &nb);
	printf("\n===|%-15p$\n", &nb);
	ft_printf(">>>|%-15p$\n", &nb);
	printf("\n===|%-5p$\n", &nb);
	ft_printf(">>>|%-5p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%-18p$\n", &nb);
	ft_printf(">>>|%-18p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%5p$\n", &c);
	ft_printf(">>>|%5p$\n", &c);
	printf("\n===|%-15p$\n", &c);
	ft_printf(">>>|%-15p$\n", &c);
	printf("\n===|%-5p$\n", &c);
	ft_printf(">>>|%-5p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%-18p$\n", &c);
	ft_printf(">>>|%-18p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%5p$\n", &nb);
	ft_printf(">>>|%5p$\n", &nb);
	printf("\n===|%-15p$\n", &nb);
	ft_printf(">>>|%-15p$\n", &nb);
	printf("\n===|%-5p$\n", &nb);
	ft_printf(">>>|%-5p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%-18p$\n", &nb);
	ft_printf(">>>|%-18p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%5p$\n", &c);
	ft_printf(">>>|%5p$\n", &c);
	printf("\n===|%-15p$\n", &c);
	ft_printf(">>>|%-15p$\n", &c);
	printf("\n===|%-5p$\n", &c);
	ft_printf(">>>|%-5p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%-18p$\n", &c);
	ft_printf(">>>|%-18p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%5p$\n", &nb);
	ft_printf(">>>|%5p$\n", &nb);
	printf("\n===|%-15p$\n", &nb);
	ft_printf(">>>|%-15p$\n", &nb);
	printf("\n===|%-5p$\n", &nb);
	ft_printf(">>>|%-5p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%-18p$\n", &nb);
	ft_printf(">>>|%-18p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%5p$\n", &c);
	ft_printf(">>>|%5p$\n", &c);
	printf("\n===|%-15p$\n", &c);
	ft_printf(">>>|%-15p$\n", &c);
	printf("\n===|%-5p$\n", &c);
	ft_printf(">>>|%-5p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%-18p$\n", &c);
	ft_printf(">>>|%-18p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%5p$\n", &nb);
	ft_printf(">>>|%5p$\n", &nb);
	printf("\n===|%-15p$\n", &nb);
	ft_printf(">>>|%-15p$\n", &nb);
	printf("\n===|%-5p$\n", &nb);
	ft_printf(">>>|%-5p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%-18p$\n", &nb);
	ft_printf(">>>|%-18p$\n", &nb);
	printf("\n===|%42p$\n", &nb);
	ft_printf(">>>|%42p$\n", &nb);
	printf("\n===|%5p$\n", &c);
	ft_printf(">>>|%5p$\n", &c);
	printf("\n===|%-15p$\n", &c);
	ft_printf(">>>|%-15p$\n", &c);
	printf("\n===|%-5p$\n", &c);
	ft_printf(">>>|%-5p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);
	printf("\n===|%-18p$\n", &c);
	ft_printf(">>>|%-18p$\n", &c);
	printf("\n===|%42p$\n", &c);
	ft_printf(">>>|%42p$\n", &c);

	return (0);
}
