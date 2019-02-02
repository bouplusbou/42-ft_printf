/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/02 13:31:46 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int argc, char **argv)
{
	int		nb;
	char	c;

	nb = 0;
	c = 'W';
	ft_printf("%5p|\n", &nb);
	printf("%5p|\n", &nb);
	ft_printf("%-15p|\n", &nb);
	printf("%-15p|\n", &nb);
	ft_printf("%-5p|\n", &nb);
	printf("%-5p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%-18p|\n", &nb);
	printf("%-18p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%5p|\n", &c);
	printf("%5p|\n", &c);
	ft_printf("%-15p|\n", &c);
	printf("%-15p|\n", &c);
	ft_printf("%-5p|\n", &c);
	printf("%-5p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%-18p|\n", &c);
	printf("%-18p|\n", &c);
	ft_printf("%5p|\n", &nb);
	printf("%5p|\n", &nb);
	ft_printf("%-15p|\n", &nb);
	printf("%-15p|\n", &nb);
	ft_printf("%-5p|\n", &nb);
	printf("%-5p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%-18p|\n", &nb);
	printf("%-18p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%5p|\n", &c);
	printf("%5p|\n", &c);
	ft_printf("%-15p|\n", &c);
	printf("%-15p|\n", &c);
	ft_printf("%-5p|\n", &c);
	printf("%-5p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%-18p|\n", &c);
	printf("%-18p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%5p|\n", &nb);
	printf("%5p|\n", &nb);
	ft_printf("%-15p|\n", &nb);
	printf("%-15p|\n", &nb);
	ft_printf("%-5p|\n", &nb);
	printf("%-5p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%-18p|\n", &nb);
	printf("%-18p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%5p|\n", &c);
	printf("%5p|\n", &c);
	ft_printf("%-15p|\n", &c);
	printf("%-15p|\n", &c);
	ft_printf("%-5p|\n", &c);
	printf("%-5p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%-18p|\n", &c);
	printf("%-18p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%5p|\n", &nb);
	printf("%5p|\n", &nb);
	ft_printf("%-15p|\n", &nb);
	printf("%-15p|\n", &nb);
	ft_printf("%-5p|\n", &nb);
	printf("%-5p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%-18p|\n", &nb);
	printf("%-18p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%5p|\n", &c);
	printf("%5p|\n", &c);
	ft_printf("%-15p|\n", &c);
	printf("%-15p|\n", &c);
	ft_printf("%-5p|\n", &c);
	printf("%-5p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%-18p|\n", &c);
	printf("%-18p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%5p|\n", &nb);
	printf("%5p|\n", &nb);
	ft_printf("%-15p|\n", &nb);
	printf("%-15p|\n", &nb);
	ft_printf("%-5p|\n", &nb);
	printf("%-5p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%-18p|\n", &nb);
	printf("%-18p|\n", &nb);
	ft_printf("%42p|\n", &nb);
	printf("%42p|\n", &nb);
	ft_printf("%5p|\n", &c);
	printf("%5p|\n", &c);
	ft_printf("%-15p|\n", &c);
	printf("%-15p|\n", &c);
	ft_printf("%-5p|\n", &c);
	printf("%-5p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	ft_printf("%-18p|\n", &c);
	printf("%-18p|\n", &c);
	ft_printf("%42p|\n", &c);
	printf("%42p|\n", &c);
	if (argc != 2)
		printf("Usage parameter:\n-c --> Char and none.\n-s --> String.\n-f --> Float.\n-d --> Decimal.\n-p --> Pointer.\n-o --> Octal.\n-x --> Hexa.\n-u --> Unsigned.\n");
	else
	{
		if (argv[1][0] == 'c')
			test_char_and_none();
		if (argv[1][0] == 'o')
			test_octal();
	}
	return (0);
}
