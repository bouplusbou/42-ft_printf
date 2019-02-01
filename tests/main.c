/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/01 16:21:42 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int argc, char **argv)
{
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
