/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:53:03 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/25 14:16:28 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	printf("===|@moulitest: %#.x %#.0x|\n", 0, 0); 
	ft_printf(">>>|@moulitest: %#.x %#.0x|\n", 0, 0); 
	printf("\n");
	printf("===|@moulitest: %.x %.0x|\n", 0, 0);   
	ft_printf(">>>|@moulitest: %.x %.0x|\n", 0, 0);   
	printf("\n");
	printf("===|@moulitest: %5.x %5.0x|\n", 0, 0); 
	ft_printf(">>>|@moulitest: %5.x %5.0x|\n", 0, 0); 
	printf("\n\n\n\n\n");
	printf("===|@moulitest: %#.o %#.0o|\n", 0, 0); 
	ft_printf(">>>|@moulitest: %#.o %#.0o|\n", 0, 0); 
	printf("\n");
	printf("===|@moulitest: %.o %.0o|\n", 0, 0);   
	ft_printf(">>>|@moulitest: %.o %.0o|\n", 0, 0);   
	printf("\n");
	printf("===|@moulitest: %5.o %5.0o|\n", 0, 0); 
	ft_printf(">>>|@moulitest: %5.o %5.0o|\n", 0, 0); 

	int	nb = 45;
	printf("\n");
	printf("===|%#.5o$\n", nb);
	ft_printf(">>>|%#.5o$\n", nb);
	printf("\n");
	printf("===|%#05.3o$\n", nb);
	ft_printf(">>>|%#05.3o$\n", nb);
	printf("\n");
	printf("===|%0#5.3o$\n", nb);
	ft_printf(">>>|%0#5.3o$\n", nb);
	printf("\n");
	printf("===|%-#7.3o$\n", nb);
	ft_printf(">>>|%-#7.3o$\n", nb);
	
	return (0);
}
