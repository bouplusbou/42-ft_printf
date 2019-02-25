/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:53:03 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/25 14:01:08 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
		// printf("===|@moulitest: %#.x %#.0x|\n", 0, 0); 
		// ft_printf(">>>|@moulitest: %#.x %#.0x|\n", 0, 0); 
		// printf("\n");
		// printf("===|@moulitest: %.x %.0x|\n", 0, 0);   
		// ft_printf(">>>|@moulitest: %.x %.0x|\n", 0, 0);   
		// printf("\n");
		// printf("===|@moulitest: %5.x %5.0x|\n", 0, 0); 
		// ft_printf(">>>|@moulitest: %5.x %5.0x|\n", 0, 0); 
		// printf("\n\n\n\n\n");
		// printf("===|@moulitest: %#.o %#.0o|\n", 0, 0); 
		// ft_printf(">>>|@moulitest: %#.o %#.0o|\n", 0, 0); 
		// printf("\n");
		// printf("===|@moulitest: %.o %.0o|\n", 0, 0);   
		// ft_printf(">>>|@moulitest: %.o %.0o|\n", 0, 0);   
		// printf("\n");
		// printf("===|@moulitest: %5.o %5.0o|\n", 0, 0); 
		// ft_printf(">>>|@moulitest: %5.o %5.0o|\n", 0, 0); 

		int	nb = 0;
	printf("===|%o$\n", nb);
	ft_printf(">>>|%o$\n", nb);
	printf("\n");
	printf("===|%#o$\n", nb);
	ft_printf(">>>|%#o$\n", nb);
	printf("\n");
	printf("===|%.5o$\n", nb);
	ft_printf(">>>|%.5o$\n", nb);
	printf("\n");
	printf("===|%#.5o$\n", nb);
	ft_printf(">>>|%#.5o$\n", nb);
	printf("\n");
	printf("===|%#.1o$\n", nb);
	ft_printf(">>>|%#.1o$\n", nb);
	printf("\n");
	printf("===|%0.5o$\n", nb);
	ft_printf(">>>|%0.5o$\n", nb);
	printf("\n");
	printf("===|%-.5o$\n", nb);
	ft_printf(">>>|%-.5o$\n", nb);
	printf("\n");
	printf("===|%5o$\n", nb);
	ft_printf(">>>|%5o$\n", nb);
	printf("\n");
	printf("===|%7.3o$\n", nb);
	ft_printf(">>>|%7.3o$\n", nb);
	printf("\n");
	printf("===|%-5o$\n", nb);
	ft_printf(">>>|%-5o$\n", nb);
	printf("\n");
	printf("===|%05o$\n", nb);
	ft_printf(">>>|%05o$\n", nb);
	printf("\n");
	printf("===|%#05o$\n", nb);
	ft_printf(">>>|%#05o$\n", nb);
	printf("\n");
	printf("===|%05.3o$\n", nb);
	ft_printf(">>>|%05.3o$\n", nb);
	printf("\n");
	printf("===|%-5.3o$\n", nb);
	ft_printf(">>>|%-5.3o$\n", nb);
	printf("\n");
	printf("===|%#05.3o$\n", nb);
	ft_printf(">>>|%#05.3o$\n", nb);
	printf("\n");
	printf("===|%0#5.3o$\n", nb);
	ft_printf(">>>|%0#5.3o$\n", nb);
	printf("\n");
	printf("===|%-#7.3o$\n", nb);
	ft_printf(">>>|%-#7.3o$\n", nb);
	printf("\n");

	nb = 45;
	printf("===|%o$\n", nb);
	ft_printf(">>>|%o$\n", nb);
	printf("\n");
	printf("===|%#o$\n", nb);
	ft_printf(">>>|%#o$\n", nb);
	printf("\n");
	printf("===|%.5o$\n", nb);
	ft_printf(">>>|%.5o$\n", nb);
	printf("\n");
	printf("===|%.0o$\n", nb);
	ft_printf(">>>|%.0o$\n", nb);
	printf("\n");
	printf("===|%#.5o$\n", nb);
	ft_printf(">>>|%#.5o$\n", nb);
	printf("\n");
	printf("===|%#.1o$\n", nb);
	ft_printf(">>>|%#.1o$\n", nb);
	printf("\n");
	printf("===|%0.5o$\n", nb);
	ft_printf(">>>|%0.5o$\n", nb);
	printf("\n");
	printf("===|%-.5o$\n", nb);
	ft_printf(">>>|%-.5o$\n", nb);
	printf("\n");
	printf("===|%5o$\n", nb);
	ft_printf(">>>|%5o$\n", nb);
	printf("\n");
	printf("===|%7.3o$\n", nb);
	ft_printf(">>>|%7.3o$\n", nb);
	printf("\n");
	printf("===|%-5o$\n", nb);
	ft_printf(">>>|%-5o$\n", nb);
	printf("\n");
	printf("===|%05o$\n", nb); 
	ft_printf(">>>|%05o$\n", nb); 
	printf("\n");
	printf("===|%#05o$\n", nb);
	ft_printf(">>>|%#05o$\n", nb);
	printf("\n");
	printf("===|%05.3o$\n", nb);
	ft_printf(">>>|%05.3o$\n", nb);
	printf("\n");
	printf("===|%-5.3o$\n", nb);
	ft_printf(">>>|%-5.3o$\n", nb);
	printf("\n");
	printf("===|%#05.3o$\n", nb);
	ft_printf(">>>|%#05.3o$\n", nb);
	printf("\n");
	printf("===|%0#5.3o$\n", nb);
	ft_printf(">>>|%0#5.3o$\n", nb);
	printf("\n");
	printf("===|%-#7.3o$\n", nb);
	ft_printf(">>>|%-#7.3o$\n", nb);
	printf("\n");

	nb = 123564789;
	printf("===|%o$\n", nb);
	ft_printf(">>>|%o$\n", nb);
	printf("\n");
	printf("===|%#o$\n", nb);
	ft_printf(">>>|%#o$\n", nb);
	printf("\n");
	printf("===|%.5o$\n", nb);
	ft_printf(">>>|%.5o$\n", nb);
	printf("\n");
	printf("===|%.0o$\n", nb);
	ft_printf(">>>|%.0o$\n", nb);
	printf("\n");
	printf("===|%#.5o$\n", nb);
	ft_printf(">>>|%#.5o$\n", nb);
	printf("\n");
	printf("===|%#.1o$\n", nb);
	ft_printf(">>>|%#.1o$\n", nb);
	printf("\n");
	printf("===|%0.5o$\n", nb);
	ft_printf(">>>|%0.5o$\n", nb);
	printf("\n");
	printf("===|%-.5o$\n", nb);
	ft_printf(">>>|%-.5o$\n", nb);
	printf("\n");
	printf("===|%5o$\n", nb);
	ft_printf(">>>|%5o$\n", nb);
	printf("\n");
	printf("===|%7.3o$\n", nb);
	ft_printf(">>>|%7.3o$\n", nb);
	printf("\n");
	printf("===|%-5o$\n", nb);
	ft_printf(">>>|%-5o$\n", nb);
	printf("\n");
	printf("===|%05o$\n", nb);
	ft_printf(">>>|%05o$\n", nb);
	printf("\n");
	printf("===|%#05o$\n", nb);
	ft_printf(">>>|%#05o$\n", nb);
	printf("\n");
	printf("===|%05.3o$\n", nb);
	ft_printf(">>>|%05.3o$\n", nb);
	printf("\n");
	printf("===|%-5.3o$\n", nb);
	ft_printf(">>>|%-5.3o$\n", nb);
	printf("\n");
	printf("===|%#05.3o$\n", nb);
	ft_printf(">>>|%#05.3o$\n", nb);
	printf("\n");
	printf("===|%0#5.3o$\n", nb);
	ft_printf(">>>|%0#5.3o$\n", nb);
	printf("\n");
	printf("===|%-#7.3o$\n", nb);
	ft_printf(">>>|%-#7.3o$\n", nb);
	printf("\n");

	nb = -1235;
	printf("===|%o$\n", nb);
	ft_printf(">>>|%o$\n", nb);
	printf("\n");
	printf("===|%#o$\n", nb);
	ft_printf(">>>|%#o$\n", nb);
	printf("\n");
	printf("===|%.5o$\n", nb);
	ft_printf(">>>|%.5o$\n", nb);
	printf("\n");
	printf("===|%.0o$\n", nb);
	ft_printf(">>>|%.0o$\n", nb);
	printf("\n");
	printf("===|%#.5o$\n", nb);
	ft_printf(">>>|%#.5o$\n", nb);
	printf("\n");
	printf("===|%#.1o$\n", nb);
	ft_printf(">>>|%#.1o$\n", nb);
	printf("\n");
	printf("===|%0.5o$\n", nb);
	ft_printf(">>>|%0.5o$\n", nb);
	printf("\n");
	printf("===|%-.5o$\n", nb);
	ft_printf(">>>|%-.5o$\n", nb);
	printf("\n");
	printf("===|%5o$\n", nb);
	ft_printf(">>>|%5o$\n", nb);
	printf("\n");
	printf("===|%7.3o$\n", nb);
	ft_printf(">>>|%7.3o$\n", nb);
	printf("\n");
	printf("===|%-5o$\n", nb);
	ft_printf(">>>|%-5o$\n", nb);
	printf("\n");
	printf("===|%05o$\n", nb);
	ft_printf(">>>|%05o$\n", nb);
	printf("\n");
	printf("===|%#05o$\n", nb);
	ft_printf(">>>|%#05o$\n", nb);
	printf("\n");
	printf("===|%05.3o$\n", nb);
	ft_printf(">>>|%05.3o$\n", nb);
	printf("\n");
	printf("===|%-5.3o$\n", nb);
	ft_printf(">>>|%-5.3o$\n", nb);
	printf("\n");
	printf("===|%#05.3o$\n", nb);
	ft_printf(">>>|%#05.3o$\n", nb);
	printf("\n");
	printf("===|%0#5.3o$\n", nb);
	ft_printf(">>>|%0#5.3o$\n", nb);
	printf("\n");
	printf("===|%-#7.3o$\n", nb);
	ft_printf(">>>|%-#7.3o$\n", nb);
	printf("\n");

	unsigned long	ulnb = 12356549864789;
	printf("===|%lo$\n", ulnb);
	ft_printf(">>>|%lo$\n", ulnb);
	printf("\n");
	printf("===|%#lo$\n", ulnb);
	ft_printf(">>>|%#lo$\n", ulnb);
	printf("\n");
	printf("===|%.5lo$\n", ulnb);
	ft_printf(">>>|%.5lo$\n", ulnb);
	printf("\n");
	printf("===|%.0lo$\n", ulnb);
	ft_printf(">>>|%.0lo$\n", ulnb);
	printf("\n");
	printf("===|%#.5lo$\n", ulnb);
	ft_printf(">>>|%#.5lo$\n", ulnb);
	printf("\n");
	printf("===|%#.1lo$\n", ulnb);
	ft_printf(">>>|%#.1lo$\n", ulnb);
	printf("\n");
	printf("===|%0.5lo$\n", ulnb);
	ft_printf(">>>|%0.5lo$\n", ulnb);
	printf("\n");
	printf("===|%-.5lo$\n", ulnb);
	ft_printf(">>>|%-.5lo$\n", ulnb);
	printf("\n");
	printf("===|%5lo$\n", ulnb);
	ft_printf(">>>|%5lo$\n", ulnb);
	printf("\n");
	printf("===|%7.3lo$\n", ulnb);
	ft_printf(">>>|%7.3lo$\n", ulnb);
	printf("\n");
	printf("===|%-5lo$\n", ulnb);
	ft_printf(">>>|%-5lo$\n", ulnb);
	printf("\n");
	printf("===|%05lo$\n", ulnb);
	ft_printf(">>>|%05lo$\n", ulnb);
	printf("\n");
	printf("===|%#05lo$\n", ulnb);
	ft_printf(">>>|%#05lo$\n", ulnb);
	printf("\n");
	printf("===|%05.3lo$\n", ulnb);
	ft_printf(">>>|%05.3lo$\n", ulnb);
	printf("\n");
	printf("===|%-5.3lo$\n", ulnb);
	ft_printf(">>>|%-5.3lo$\n", ulnb);
	printf("\n");
	printf("===|%#05.3lo$\n", ulnb);
	ft_printf(">>>|%#05.3lo$\n", ulnb);
	printf("\n");
	printf("===|%0#5.3lo$\n", ulnb);
	ft_printf(">>>|%0#5.3lo$\n", ulnb);
	printf("\n");
	printf("===|%-#7.3lo$\n", ulnb);
	ft_printf(">>>|%-#7.3lo$\n", ulnb);
	printf("\n");

	nb = 45;
	printf("===|%.5u$\n", nb);
	ft_printf(">>>|%.5u$\n", nb);
	printf("\n");
	printf("===|%0.5u$\n", nb);
	ft_printf(">>>|%0.5u$\n", nb);
	printf("\n");
	printf("===|%-.5u$\n", nb);
	ft_printf(">>>|%-.5u$\n", nb);
	printf("\n");
	printf("===|%5u$\n", nb);
	ft_printf(">>>|%5u$\n", nb);
	printf("\n");
	printf("===|%-5u$\n", nb);
	ft_printf(">>>|%-5u$\n", nb);
	printf("\n");
	printf("===|%05u$\n", nb);
	ft_printf(">>>|%05u$\n", nb);
	printf("\n");
	printf("===|%05.3u$\n", nb);
	ft_printf(">>>|%05.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%050.u$\n", nb);
	ft_printf(">>>|%050.u$\n", nb);
	printf("\n");
	printf("===|%-1.45u$\n", nb);
	ft_printf(">>>|%-1.45u$\n", nb);
	printf("\n");
	printf("===|%-55.35u$\n", nb);
	ft_printf(">>>|%-55.35u$\n", nb);
	printf("\n");

	nb = 123564789;
	printf("===|%.5u$\n", nb);
	ft_printf(">>>|%.5u$\n", nb);
	printf("\n");
	printf("===|%0.5u$\n", nb);
	ft_printf(">>>|%0.5u$\n", nb);
	printf("\n");
	printf("===|%-.5u$\n", nb);
	ft_printf(">>>|%-.5u$\n", nb);
	printf("\n");
	printf("===|%5u$\n", nb);
	ft_printf(">>>|%5u$\n", nb);
	printf("\n");
	printf("===|%-5u$\n", nb);
	ft_printf(">>>|%-5u$\n", nb);
	printf("\n");
	printf("===|%05u$\n", nb);
	ft_printf(">>>|%05u$\n", nb);
	printf("\n");
	printf("===|%05.3u$\n", nb);
	ft_printf(">>>|%05.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%050.u$\n", nb);
	ft_printf(">>>|%050.u$\n", nb);
	printf("\n");
	printf("===|%-1.45u$\n", nb);
	ft_printf(">>>|%-1.45u$\n", nb);
	printf("\n");
	printf("===|%-55.35u$\n", nb);
	ft_printf(">>>|%-55.35u$\n", nb);
	printf("\n");

	nb = -1235;
	printf("===|%.5u$\n", nb);
	ft_printf(">>>|%.5u$\n", nb);
	printf("\n");
	printf("===|%0.5u$\n", nb);
	ft_printf(">>>|%0.5u$\n", nb);
	printf("\n");
	printf("===|%-.5u$\n", nb);
	ft_printf(">>>|%-.5u$\n", nb);
	printf("\n");
	printf("===|%5u$\n", nb);
	ft_printf(">>>|%5u$\n", nb);
	printf("\n");
	printf("===|%-5u$\n", nb);
	ft_printf(">>>|%-5u$\n", nb);
	printf("\n");
	printf("===|%05u$\n", nb);
	ft_printf(">>>|%05u$\n", nb);
	printf("\n");
	printf("===|%05.3u$\n", nb);
	ft_printf(">>>|%05.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%050.u$\n", nb);
	ft_printf(">>>|%050.u$\n", nb);
	printf("\n");
	printf("===|%-1.45u$\n", nb);
	ft_printf(">>>|%-1.45u$\n", nb);
	printf("\n");
	printf("===|%-55.35u$\n", nb);
	ft_printf(">>>|%-55.35u$\n", nb);
	printf("\n");

	ulnb = 56489612321568652;
	printf("===|%.5lu$\n", ulnb);
	ft_printf(">>>|%.5lu$\n", ulnb);
	printf("\n");
	printf("===|%0.5lu$\n", ulnb);
	ft_printf(">>>|%0.5lu$\n", ulnb);
	printf("\n");
	printf("===|%-.5lu$\n", ulnb);
	ft_printf(">>>|%-.5lu$\n", ulnb);
	printf("\n");
	printf("===|%5lu$\n", ulnb);
	ft_printf(">>>|%5lu$\n", ulnb);
	printf("\n");
	printf("===|%-5lu$\n", ulnb);
	ft_printf(">>>|%-5lu$\n", ulnb);
	printf("\n");
	printf("===|%05lu$\n", ulnb);
	ft_printf(">>>|%05lu$\n", ulnb);
	printf("\n");
	printf("===|%05.3lu$\n", ulnb);
	ft_printf(">>>|%05.3lu$\n", ulnb);
	printf("\n");
	printf("===|%-5.3lu$\n", ulnb);
	ft_printf(">>>|%-5.3lu$\n", ulnb);
	printf("\n");
	printf("===|%-5.3lu$\n", ulnb);
	ft_printf(">>>|%-5.3lu$\n", ulnb);
	printf("\n");
	printf("===|%050.lu$\n", ulnb);
	ft_printf(">>>|%050.lu$\n", ulnb);
	printf("\n");
	printf("===|%-1.45lu$\n", ulnb);
	ft_printf(">>>|%-1.45lu$\n", ulnb);
	printf("\n");
	printf("===|%-55.35lu$\n", ulnb);
	ft_printf(">>>|%-55.35lu$\n", ulnb);
	printf("\n");

	nb = 0;
	printf("===|%.5u$\n", nb);
	ft_printf(">>>|%.5u$\n", nb);
	printf("\n");
	printf("===|%0.5u$\n", nb);
	ft_printf(">>>|%0.5u$\n", nb);
	printf("\n");
	printf("===|%-.5u$\n", nb);
	ft_printf(">>>|%-.5u$\n", nb);
	printf("\n");
	printf("===|%5u$\n", nb);
	ft_printf(">>>|%5u$\n", nb);
	printf("\n");
	printf("===|%-5u$\n", nb);
	ft_printf(">>>|%-5u$\n", nb);
	printf("\n");
	printf("===|%05u$\n", nb);
	ft_printf(">>>|%05u$\n", nb);
	printf("\n");
	printf("===|%05.3u$\n", nb);
	ft_printf(">>>|%05.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%-5.3u$\n", nb);
	ft_printf(">>>|%-5.3u$\n", nb);
	printf("\n");
	printf("===|%-1.45u$\n", nb);
	ft_printf(">>>|%-1.45u$\n", nb);
	printf("\n");
	printf("===|%-55.35u$\n", nb);
	ft_printf(">>>|%-55.35u$\n", nb);
	printf("\n");

	nb = 123564789;
	printf("===|%x$\n", nb);
	ft_printf(">>>|%x$\n", nb);
	printf("\n");
	printf("===|%X$\n", nb);
	ft_printf(">>>|%X$\n", nb);
	printf("\n");
	printf("===|%#X$\n", nb);
	ft_printf(">>>|%#X$\n", nb);
	printf("\n");
	printf("===|%.5X$\n", nb);
	ft_printf(">>>|%.5X$\n", nb);
	printf("\n");
	printf("===|%#.5X$\n", nb);
	ft_printf(">>>|%#.5X$\n", nb);
	printf("\n");
	printf("===|%#.1X$\n", nb);
	ft_printf(">>>|%#.1X$\n", nb);
	printf("\n");
	printf("===|%0.5X$\n", nb);
	ft_printf(">>>|%0.5X$\n", nb);
	printf("\n");
	printf("===|%-.5X$\n", nb);
	ft_printf(">>>|%-.5X$\n", nb);
	printf("\n");
	printf("===|%5X$\n", nb);
	ft_printf(">>>|%5X$\n", nb);
	printf("\n");
	printf("===|%7.3X$\n", nb);
	ft_printf(">>>|%7.3X$\n", nb);
	printf("\n");
	printf("===|%-5X$\n", nb);
	ft_printf(">>>|%-5X$\n", nb);
	printf("\n");
	printf("===|%05X$\n", nb);
	ft_printf(">>>|%05X$\n", nb);
	printf("\n");
	printf("===|%#05X$\n", nb);
	ft_printf(">>>|%#05X$\n", nb);
	printf("\n");
	printf("===|%05.3X$\n", nb);
	ft_printf(">>>|%05.3X$\n", nb);
	printf("\n");
	printf("===|%-5.3X$\n", nb);
	ft_printf(">>>|%-5.3X$\n", nb);
	printf("\n");
	printf("===|%#05.3X$\n", nb);
	ft_printf(">>>|%#05.3X$\n", nb);
	printf("\n");
	printf("===|%0#5.3X$\n", nb);
	ft_printf(">>>|%0#5.3X$\n", nb);
	printf("\n");
	printf("===|%-#7.3X$\n", nb);
	ft_printf(">>>|%-#7.3X$\n", nb);
	printf("\n");

	nb = -1235;
	printf("===|%x$\n", nb);
	ft_printf(">>>|%x$\n", nb);
	printf("\n");
	printf("===|%X$\n", nb);
	ft_printf(">>>|%X$\n", nb);
	printf("\n");
	printf("===|%#X$\n", nb);
	ft_printf(">>>|%#X$\n", nb);
	printf("\n");
	printf("===|%.5X$\n", nb);
	ft_printf(">>>|%.5X$\n", nb);
	printf("\n");
	printf("===|%#.5X$\n", nb);
	ft_printf(">>>|%#.5X$\n", nb);
	printf("\n");
	printf("===|%#.1X$\n", nb);
	ft_printf(">>>|%#.1X$\n", nb);
	printf("\n");
	printf("===| %0.5X$\n", nb);
	ft_printf(">>>| %0.5X$\n", nb);
	printf("\n");
	printf("===|%-.5X$\n", nb);
	ft_printf(">>>|%-.5X$\n", nb);
	printf("\n");
	printf("===|%5X$\n", nb);
	ft_printf(">>>|%5X$\n", nb);
	printf("\n");
	printf("===|%7.3X$\n", nb);
	ft_printf(">>>|%7.3X$\n", nb);
	printf("\n");
	printf("===|%-5X$\n", nb);
	ft_printf(">>>|%-5X$\n", nb);
	printf("\n");
	printf("===|%05X$\n", nb);
	ft_printf(">>>|%05X$\n", nb);
	printf("\n");
	printf("===|%#05X$\n", nb);
	ft_printf(">>>|%#05X$\n", nb);
	printf("\n");
	printf("===|%05.3X$\n", nb);
	ft_printf(">>>|%05.3X$\n", nb);
	printf("\n");
	printf("===|%-5.3X$\n", nb);
	ft_printf(">>>|%-5.3X$\n", nb);
	printf("\n");
	printf("===|%#05.3X$\n", nb);
	ft_printf(">>>|%#05.3X$\n", nb);
	printf("\n");
	printf("===|%0#5.3X$\n", nb);
	ft_printf(">>>|%0#5.3X$\n", nb);
	printf("\n");
	printf("===|%-#7.3X$\n", nb);
	ft_printf(">>>|%-#7.3X$\n", nb);
	printf("\n");

	long lnb = 56489612321568652;
	printf("===|%lx$\n", lnb);
	ft_printf(">>>|%lx$\n", lnb);
	printf("\n");
	printf("===|%lX$\n", lnb);
	ft_printf(">>>|%lX$\n", lnb);
	printf("\n");
	printf("===|%#lx$\n", lnb);
	ft_printf(">>>|%#lx$\n", lnb);
	printf("\n");
	printf("===|%.5lx$\n", lnb);
	ft_printf(">>>|%.5lx$\n", lnb);
	printf("\n");
	printf("===|%#.5lx$\n", lnb);
	ft_printf(">>>|%#.5lx$\n", lnb);
	printf("\n");
	printf("===|%#.1lx$\n", lnb);
	ft_printf(">>>|%#.1lx$\n", lnb);
	printf("\n");
	printf("===|%0.5lx$\n", lnb);
	ft_printf(">>>|%0.5lx$\n", lnb);
	printf("\n");
	printf("===|%-.5lx$\n", lnb);
	ft_printf(">>>|%-.5lx$\n", lnb);
	printf("\n");
	printf("===|%5lx$\n", lnb);
	ft_printf(">>>|%5lx$\n", lnb);
	printf("\n");
	printf("===|%7.3lx$\n", lnb);
	ft_printf(">>>|%7.3lx$\n", lnb);
	printf("\n");
	printf("===|%-5lx$\n", lnb);
	ft_printf(">>>|%-5lx$\n", lnb);
	printf("\n");
	printf("===|%05lx$\n", lnb);
	ft_printf(">>>|%05lx$\n", lnb);
	printf("\n");
	printf("===|%#05lx$\n", lnb);
	ft_printf(">>>|%#05lx$\n", lnb);
	printf("\n");
	printf("===|%05.3lx$\n", lnb);
	ft_printf(">>>|%05.3lx$\n", lnb);
	printf("\n");
	printf("===|%-5.3lx$\n", lnb);
	ft_printf(">>>|%-5.3lx$\n", lnb);
	printf("\n");
	printf("===|%#05.3lx$\n", lnb);
	ft_printf(">>>|%#05.3lx$\n", lnb);
	printf("\n");
	printf("===|%0#5.3lx$\n", lnb);
	ft_printf(">>>|%0#5.3lx$\n", lnb);
	printf("\n");
	printf("===|%-#7.3lx$\n", lnb);
	ft_printf(">>>|%-#7.3lx$\n", lnb);
	printf("\n");

	long long llnb = __LONG_LONG_MAX__;
	printf("===|%llx$\n", llnb);
	ft_printf(">>>|%llx$\n", llnb);
	printf("\n");
	printf("===|%llX$\n", llnb);
	ft_printf(">>>|%llX$\n", llnb);
	printf("\n");
	printf("===|%#llx$\n", llnb);
	ft_printf(">>>|%#llx$\n", llnb);
	printf("\n");
	printf("===|%.5llx$\n", llnb);
	ft_printf(">>>|%.5llx$\n", llnb);
	printf("\n");
	printf("===|%#.5llx$\n", llnb);
	ft_printf(">>>|%#.5llx$\n", llnb);
	printf("\n");
	printf("===|%#.1llx$\n", llnb);
	ft_printf(">>>|%#.1llx$\n", llnb);
	printf("\n");
	printf("===|%0.5llx$\n", llnb);
	ft_printf(">>>|%0.5llx$\n", llnb);
	printf("\n");
	printf("===|%-.5llx$\n", llnb);
	ft_printf(">>>|%-.5llx$\n", llnb);
	printf("\n");
	printf("===|%5llx$\n", llnb);
	ft_printf(">>>|%5llx$\n", llnb);
	printf("\n");
	printf("===|%7.3llx$\n", llnb);
	ft_printf(">>>|%7.3llx$\n", llnb);
	printf("\n");
	printf("===|%-5llx$\n", llnb);
	ft_printf(">>>|%-5llx$\n", llnb);
	printf("\n");
	printf("===|%05llx$\n", llnb);
	ft_printf(">>>|%05llx$\n", llnb);
	printf("\n");
	printf("===|%#05llx$\n", llnb);
	ft_printf(">>>|%#05llx$\n", llnb);
	printf("\n");
	printf("===|%05.3llx$\n", llnb);
	ft_printf(">>>|%05.3llx$\n", llnb);
	printf("\n");
	printf("===|%-5.3llx$\n", llnb);
	ft_printf(">>>|%-5.3llx$\n", llnb);
	printf("\n");
	printf("===|%#05.3llx$\n", llnb);
	ft_printf(">>>|%#05.3llx$\n", llnb);
	printf("\n");
	printf("===|%0#5.3llx$\n", llnb);
	ft_printf(">>>|%0#5.3llx$\n", llnb);
	printf("\n");
	printf("===|%-#7.3llx$\n", llnb);
	ft_printf(">>>|%-#7.3llx$\n", llnb);
	printf("\n");




	unsigned char ucnb = CHAR_MAX;
	printf("===|%hhx$\n", ucnb);
	ft_printf(">>>|%hhx$\n", ucnb);
	printf("\n");
	printf("===|%hhx$\n", ucnb);
	ft_printf(">>>|%hhx$\n", ucnb);
	printf("\n");
	printf("===|%#hhx$\n", ucnb);
	ft_printf(">>>|%#hhx$\n", ucnb);
	printf("\n");
	printf("===|%.5hhx$\n", ucnb);
	ft_printf(">>>|%.5hhx$\n", ucnb);
	printf("\n");
	printf("===|%#.5hhx$\n", ucnb);
	ft_printf(">>>|%#.5hhx$\n", ucnb);
	printf("\n");
	printf("===|%#.1hhx$\n", ucnb);
	ft_printf(">>>|%#.1hhx$\n", ucnb);
	printf("\n");
	printf("===|%0.5hhx$\n", ucnb);
	ft_printf(">>>|%0.5hhx$\n", ucnb);
	printf("\n");
	printf("===|%-.5hhx$\n", ucnb);
	ft_printf(">>>|%-.5hhx$\n", ucnb);
	printf("\n");
	printf("===|%5hhx$\n", ucnb);
	ft_printf(">>>|%5hhx$\n", ucnb);
	printf("\n");
	printf("===|%7.3hhx$\n", ucnb);
	ft_printf(">>>|%7.3hhx$\n", ucnb);
	printf("\n");
	printf("===|%-5hhx$\n", ucnb);
	ft_printf(">>>|%-5hhx$\n", ucnb);
	printf("\n");
	printf("===|%05hhx$\n", ucnb);
	ft_printf(">>>|%05hhx$\n", ucnb);
	printf("\n");
	printf("===|%#05hhx$\n", ucnb);
	ft_printf(">>>|%#05hhx$\n", ucnb);
	printf("\n");
	printf("===|%05.3hhx$\n", ucnb);
	ft_printf(">>>|%05.3hhx$\n", ucnb);
	printf("\n");
	printf("===|%-5.3hhx$\n", ucnb);
	ft_printf(">>>|%-5.3hhx$\n", ucnb);
	printf("\n");
	printf("===|%#05.3hhx$\n", ucnb);
	ft_printf(">>>|%#05.3hhx$\n", ucnb);
	printf("\n");
	printf("===|%0#5.3hhx$\n", ucnb);
	ft_printf(">>>|%0#5.3hhx$\n", ucnb);
	printf("\n");
	printf("===|%-#7.3hhx$\n", ucnb);
	ft_printf(">>>|%-#7.3hhx$\n", ucnb);
	printf("\n");
	printf("===|%#.x %#.0x$\n", 0, 0);
	ft_printf(">>>|%#.x %#.0x$\n", 0, 0);
printf("\n");




	printf("===|%x$\n", 42);
	ft_printf(">>>|%x$\n", 42);
	printf("\n");
	printf("===|%X$\n", 42);
	ft_printf(">>>|%X$\n", 42);
	printf("\n");
	printf("===|%x$\n", 0);
	ft_printf(">>>|%x$\n", 0);
	printf("\n");
	printf("===|%X$\n", 0);
	ft_printf(">>>|%X$\n", 0);
	printf("\n");
	printf("===|%x$\n", -42);
	ft_printf(">>>|%x$\n", -42);
	printf("\n");
	printf("===|%X$\n", -42);
	ft_printf(">>>|%X$\n", -42);
	printf("\n");
	// printf("===|%x$\n", 4294967296);
	// ft_printf(">>>|%x$\n", 4294967296);
	// printf("\n");
	// printf("===|%X$\n", 4294967296);
	// ft_printf(">>>|%X$\n", 4294967296);
	printf("\n");
	printf("===|%10x$\n", 42);
	ft_printf(">>>|%10x$\n", 42);
	printf("\n");
	printf("===|%-10x$\n", 42);
	ft_printf(">>>|%-10x$\n", 42);
	printf("\n");
	// printf("===|%lx$\n", 4294967296);
	// ft_printf(">>>|%lx$\n", 4294967296);
	// printf("\n");
	// printf("===|%llX$\n", 4294967296);
	// ft_printf(">>>|%llX$\n", 4294967296);
	// printf("\n");
	// printf("===|%hx$\n", 4294967296);
	// ft_printf(">>>|%hx$\n", 4294967296);
	// printf("\n");
	// printf("===|%hhX$\n", 4294967296);
	// ft_printf(">>>|%hhX$\n", 4294967296);
	// printf("\n");
	// printf("===|%jx$\n", 4294967295);
	// ft_printf(">>>|%jx$\n", 4294967295);
	// printf("\n");
	// printf("===|%jx$\n", 4294967296);
	// ft_printf(">>>|%jx$\n", 4294967296);
	// printf("\n");
	// printf("===|%jx$\n", -4294967296);
	// ft_printf(">>>|%jx$\n", -4294967296);
	// printf("\n");
	// printf("===|%jx$\n", -4294967297);
	// ft_printf(">>>|%jx$\n", -4294967297);
	// printf("\n");
	// printf("===|%llx$\n", 9223372036854775807);
	// ft_printf(">>>|%llx$\n", 9223372036854775807);
	// printf("\n");
	// printf("===|%llx$\n", 9223372036854775808);
	// ft_printf(">>>|%llx$\n", 9223372036854775808);
	printf("\n");
	printf("===|%010x$\n", 542);
	ft_printf(">>>|%010x$\n", 542);
	printf("\n");
	printf("===|%-15x$\n", 542);
	ft_printf(">>>|%-15x$\n", 542);
	printf("\n");
	printf("===|%2x$\n", 542);
	ft_printf(">>>|%2x$\n", 542);
	printf("\n");
	printf("===|%.2x$\n", 5427);
	ft_printf(">>>|%.2x$\n", 5427);
	printf("\n");
	printf("===|%5.2x$\n", 5427);
	ft_printf(">>>|%5.2x$\n", 5427);
	printf("\n");
	printf("===|%#x$\n", 42);
	ft_printf(">>>|%#x$\n", 42);
	printf("\n");
	// printf("===|%#llx$\n", 9223372036854775807);
	// ft_printf(">>>|%#llx$\n", 9223372036854775807);
	printf("\n");
	printf("===|%#x$\n", 0);
	ft_printf(">>>|%#x$\n", 0);
	printf("\n");
	printf("===|%#x$\n", 42);
	ft_printf(">>>|%#x$\n", 42);
	printf("\n");
	printf("===|%#X$\n", 42);
	ft_printf(">>>|%#X$\n", 42);
	printf("\n");
	printf("===|%#8x$\n", 42);
	ft_printf(">>>|%#8x$\n", 42);
	printf("\n");
	printf("===|%#08x$\n", 42);
	ft_printf(">>>|%#08x$\n", 42);
	// printf("\n");
	// printf("===|%#-08x$\n", 42);
	// ft_printf(">>>|%#-08x$\n", 42);
	printf("\n");
	printf("===|@%#.x %#.0x$\n", 0, 0);
	ft_printf(">>>|@%#.x %#.0x$\n", 0, 0);
	printf("\n");
	printf("===|@%.x %.0x$\n", 0, 0);
	ft_printf(">>>|@%.x %.0x$\n", 0, 0);
	printf("\n");
	printf("===|@%5.x %5.0x$\n", 0, 0);
	ft_printf(">>>|@%5.x %5.0x$\n", 0, 0);
	printf("\n");
	return (0);
}
