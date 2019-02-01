/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/01 09:48:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	printf("Ceci est un test. :)\n");
	ft_printf("%X|\n", 42);                       		//13. OK  -> "2A"
	ft_printf("%x|\n", 0);                          //14. OK (modif ultoa_base)  -> "0"
	ft_printf("%X|\n", 0);                          //15. OK (modif ultoa_base)  -> "0"
	ft_printf("%x|\n", -42);                        //16. OK (utiliser ultoa)  -> "ffffffd6"
	ft_printf("%X|\n", -42);                        //17. OK (utiliser ultoa)  -> "FFFFFFD6"
	ft_printf("%x|\n", 4294967296);                 //18. OK  -> "0"
	ft_printf("%X|\n", 4294967296);                 //19. OK  -> "0"
	ft_printf("%10x|\n", 42);                       //21. OK  -> "        2a"
	ft_printf("%-10x|\n", 42);                      //22. OK  -> "2a        "
	ft_printf("%010x|\n", 542);                     //33. OK  -> "000000021e"000000021e|
	ft_printf("%-15x|\n", 542);                     //34. OK  -> "21e            "21e            |
	ft_printf("%2x|\n", 542);                       //35. OK -> "21e"
	ft_printf("%.2x|\n", 5427);                     //36. OK  -> "1533"
	ft_printf("%5.2x|\n", 5427);                    //37. OK  -> " 1533"
	ft_printf("%#x|\n", 42);                        //38. OK  -> "0x2a"
	ft_printf("%#x|\n", 0);                         //40. OK (rajout de strcmp dans concat et target != 0 dans convert_hex)  -> "0"
	ft_printf("%#x|\n", 42);                        //41. OK  -> "0x2a"
	ft_printf("%#X|\n", 42);                        //42. OK  -> "0X2A"
	ft_printf("%#8x|\n", 42);                       //43. OK  -> "    0x2a"    0x2a|
	ft_printf("%#08x|\n", 42);                      //44. OK  -> "0x00002a"0x00002a|
	ft_printf("%#-08x|\n", 42);                     //45. OK (rajouter !ft_strchr(data.flags, '-') lorsque je choisi entre remplir de '0' ou ' ') -> "0x2a    "
	ft_printf("@moulitest: %#.x %#.0x|\n", 0, 0);   //46. OK (rajoute une condition si precision et target = 0)  -> "@moulitest:  "@moulitest:  |
	ft_printf("@moulitest: %.x %.0x|\n", 0, 0);     //47. OK  -> "@moulitest:  "@moulitest:  |
	ft_printf("@moulitest: %5.x %5.0x|\n", 0, 0);   //48. OK  -> "@moulitest:            "@moulitest:            |
	ft_printf("%lx|\n", 4294967296);                //23. OK  -> "100000000"100000000|
	ft_printf("%llX|\n", 4294967296);               //24. OK  -> "100000000"
	ft_printf("%hx|\n", 4294967296);                //25. OK  -> "0"
	ft_printf("%hhX|\n", 4294967296);               //26. OK  -> "0"
	ft_printf("%llx|\n", 9223372036854775807);      //31. OK  -> "7fffffffffffffff"7fffffffffffffff|
	ft_printf("%#llx|\n", 9223372036854775807);     //39. OK  -> "0x7fffffffffffffff"0x7fffffffffffffff|
	// ft_printf("%jx|\n", 4294967295);                //27. FAIL  -> "ffffffff"
	// ft_printf("%jx|\n", 4294967296);                //28. FAIL  -> "100000000"
	// ft_printf("%jx|\n", -4294967296);               //29. FAIL  -> "ffffffff00000000"
	// ft_printf("%jx|\n", -4294967297);               //30. FAIL  -> "fffffffeffffffff"
	// ft_printf("%llx|\n", 9223372036854775808);      //32. FAIL  -> "7fffffffffffffff"error: variable 'target' is used uninitialized whenever 'if' condition is false [-Werror,-Wsometimes-uninitialized]
	// ft_printf("%x", test);                       //20. FAIL  -> "0"
	return (0);
}
