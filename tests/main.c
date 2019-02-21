/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudios <bclaudios@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/21 04:03:03 by bclaudios        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	// double f = -8.999;
	// double f1 = -9.99999999;
	// double f2 = -5.789789789;
	// double f3 = -987.999999999;
	// double f4 = -999.9999999;

	// ft_printf("$%.12f\n", f);
	// printf("&%.12f\n", f);
	// ft_printf("$%.5f\n", f1);
	// printf("&%.5f\n", f1);
	// ft_printf("$%.12f\n", f2);
	// printf("&%.12f\n", f2);
	// ft_printf("$%.7f\n", f3);
	// printf("&%.7f\n", f3);
	// ft_printf("$%.5f\n", f3);
	// printf("&%.5f\n", f3);
	
	double		nb;

	nb = -12547.58;
	printf("\n===|% f$\n", nb);
	ft_printf(">>>|% f$\n", nb);
	printf("\n===|%+f$\n", nb);
	ft_printf(">>>|%+f$\n", nb);
	printf("\n===|%#f$\n", nb);
	ft_printf(">>>|%#f$\n", nb);
	printf("\n===|%.2f$\n", nb);
	ft_printf(">>>|%.2f$\n", nb);
	printf("\n===|%.14f$\n", nb);
	ft_printf(">>>|%.14f$\n", nb);
	printf("\n===|%.14f$\n", nb);
	ft_printf(">>>|%.14f$\n", nb);
	printf("\n===|%#.0f$\n", nb);
	ft_printf(">>>|%#.0f$\n", nb);
	printf("\n===|% .5f$\n", nb);
	ft_printf(">>>|% .5f$\n", nb);
	printf("\n===|%# .0f$\n", nb);
	ft_printf(">>>|%# .0f$\n", nb);
	printf("\n===|% #.0f$\n", nb);
	ft_printf(">>>|% #.0f$\n", nb);
	printf("\n===|%+.5f$\n", nb);
	ft_printf(">>>|%+.5f$\n", nb);
	printf("\n===|%+.0f$\n", nb);
	ft_printf(">>>|%+.0f$\n", nb);
	printf("\n===|%#+.0f$\n", nb);
	ft_printf(">>>|%#+.0f$\n", nb);
	printf("\n===|%0.5f$\n", nb);
	ft_printf(">>>|%0.5f$\n", nb);
	printf("\n===|%-.5f$\n", nb);
	ft_printf(">>>|%-.5f$\n", nb);
	printf("\n===|%5f$\n", nb);
	ft_printf(">>>|%5f$\n", nb);
	printf("\n===|% 5f$\n", nb);
	ft_printf(">>>|% 5f$\n", nb);
	printf("\n===|%+5f$\n", nb);
	ft_printf(">>>|%+5f$\n", nb);
	printf("\n===|%# 5f$\n", nb);
	ft_printf(">>>|%# 5f$\n", nb);
	printf("\n===|%#+5f$\n", nb);
	ft_printf(">>>|%#+5f$\n", nb);
	printf("\n===|%-5f$\n", nb);
	ft_printf(">>>|%-5f$\n", nb);
	printf("\n===|%05f$\n", nb);
	ft_printf(">>>|%05f$\n", nb);
	printf("\n===|%+05f$\n", nb);
	ft_printf(">>>|%+05f$\n", nb);
	printf("\n===|%0+5f$\n", nb);
	ft_printf(">>>|%0+5f$\n", nb);
	printf("\n===|%05.3f$\n", nb);
	ft_printf(">>>|%05.3f$\n", nb);
	printf("\n===|%0#5.0f$\n", nb);
	ft_printf(">>>|%0#5.0f$\n", nb);
	printf("\n===|%-5.3f$\n", nb);
	ft_printf(">>>|%-5.3f$\n", nb);
	printf("\n===|%-#5.0f$\n", nb);
	ft_printf(">>>|%-#5.0f$\n", nb);
	printf("\n===|%+05.3f$\n", nb);
	ft_printf(">>>|%+05.3f$\n", nb);
	printf("\n===|%0+#5.0f$\n", nb);
	ft_printf(">>>|%0+#5.0f$\n", nb);
	printf("\n===|%0 5.3f$\n", nb);
	ft_printf(">>>|%0 5.3f$\n", nb);
	printf("\n===|% 05.3f$\n", nb);
	ft_printf(">>>|% 05.3f$\n", nb);
	printf("\n===|%#0 5.0f$\n", nb);
	ft_printf(">>>|%#0 5.0f$\n", nb);
	printf("\n===|%-+5.3f$\n", nb);
	ft_printf(">>>|%-+5.3f$\n", nb);
	printf("\n===|%-#+5.0f$\n", nb);
	ft_printf(">>>|%-#+5.0f$\n", nb);

	nb = 0;
	printf("\n===|% f$\n", nb);
	ft_printf(">>>|% f$\n", nb);
	printf("\n===|%+f$\n", nb);
	ft_printf(">>>|%+f$\n", nb);
	printf("\n===|%#f$\n", nb);
	ft_printf(">>>|%#f$\n", nb);
	printf("\n===|%.2f$\n", nb);
	ft_printf(">>>|%.2f$\n", nb);
	printf("\n===|%.14f$\n", nb);
	ft_printf(">>>|%.14f$\n", nb);
	printf("\n===|%#.0f$\n", nb);
	ft_printf(">>>|%#.0f$\n", nb);
	printf("\n===|% .5f$\n", nb);
	ft_printf(">>>|% .5f$\n", nb);
	printf("\n===|%# .0f$\n", nb);
	ft_printf(">>>|%# .0f$\n", nb);
	printf("\n===|% #.0f$\n", nb);
	ft_printf(">>>|% #.0f$\n", nb);
	printf("\n===|%+.5f$\n", nb);
	ft_printf(">>>|%+.5f$\n", nb);
	printf("\n===|%+.0f$\n", nb);
	ft_printf(">>>|%+.0f$\n", nb);
	printf("\n===|%#+.0f$\n", nb);
	ft_printf(">>>|%#+.0f$\n", nb);
	printf("\n===|%0.5f$\n", nb);
	ft_printf(">>>|%0.5f$\n", nb);
	printf("\n===|%-.5f$\n", nb);
	ft_printf(">>>|%-.5f$\n", nb);
	printf("\n===|%5f$\n", nb);
	ft_printf(">>>|%5f$\n", nb);
	printf("\n===|% 5f$\n", nb);
	ft_printf(">>>|% 5f$\n", nb);
	printf("\n===|%+5f$\n", nb);
	ft_printf(">>>|%+5f$\n", nb);
	printf("\n===|%# 5f$\n", nb);
	ft_printf(">>>|%# 5f$\n", nb);
	printf("\n===|%#+5f$\n", nb);
	ft_printf(">>>|%#+5f$\n", nb);
	printf("\n===|%-5f$\n", nb);
	ft_printf(">>>|%-5f$\n", nb);
	printf("\n===|%05f$\n", nb);
	ft_printf(">>>|%05f$\n", nb);
	printf("\n===|%+05f$\n", nb);
	ft_printf(">>>|%+05f$\n", nb);
	printf("\n===|%0+5f$\n", nb);
	ft_printf(">>>|%0+5f$\n", nb);
	printf("\n===|%05.3f$\n", nb);
	ft_printf(">>>|%05.3f$\n", nb);
	printf("\n===|%0#5.0f$\n", nb);
	ft_printf(">>>|%0#5.0f$\n", nb);
	printf("\n===|%-5.3f$\n", nb);
	ft_printf(">>>|%-5.3f$\n", nb);
	printf("\n===|%-#5.0f$\n", nb);
	ft_printf(">>>|%-#5.0f$\n", nb);
	printf("\n===|%+05.3f$\n", nb);
	ft_printf(">>>|%+05.3f$\n", nb);
	printf("\n===|%0+#5.0f$\n", nb);
	ft_printf(">>>|%0+#5.0f$\n", nb);
	printf("\n===|%0 5.3f$\n", nb);
	ft_printf(">>>|%0 5.3f$\n", nb);
	printf("\n===|% 05.3f$\n", nb);
	ft_printf(">>>|% 05.3f$\n", nb);
	printf("\n===|%#0 5.0f$\n", nb);
	ft_printf(">>>|%#0 5.0f$\n", nb);
	printf("\n===|%-+5.3f$\n", nb);
	ft_printf(">>>|%-+5.3f$\n", nb);
	printf("\n===|%-#+5.0f$\n", nb);
	ft_printf(">>>|%-#+5.0f$\n", nb);

	nb = 45.123456789;
	printf("\n===|% f$\n", nb);
	ft_printf(">>>|% f$\n", nb);
	printf("\n===|%+f$\n", nb);
	ft_printf(">>>|%+f$\n", nb);
	printf("\n===|%#f$\n", nb);
	ft_printf(">>>|%#f$\n", nb);
	printf("\n===|%.2f$\n", nb);
	ft_printf(">>>|%.2f$\n", nb);
	printf("\n===|%.14f$\n", nb);
	ft_printf(">>>|%.14f$\n", nb);
	printf("\n===|%#.0f$\n", nb);
	ft_printf(">>>|%#.0f$\n", nb);
	printf("\n===|% .5f$\n", nb);
	ft_printf(">>>|% .5f$\n", nb);
	printf("\n===|%# .0f$\n", nb);
	ft_printf(">>>|%# .0f$\n", nb);
	printf("\n===|% #.0f$\n", nb);
	ft_printf(">>>|% #.0f$\n", nb);
	printf("\n===|%+.5f$\n", nb);
	ft_printf(">>>|%+.5f$\n", nb);
	printf("\n===|%+.0f$\n", nb);
	ft_printf(">>>|%+.0f$\n", nb);
	printf("\n===|%#+.0f$\n", nb);
	ft_printf(">>>|%#+.0f$\n", nb);
	printf("\n===|%0.5f$\n", nb);
	ft_printf(">>>|%0.5f$\n", nb);
	printf("\n===|%-.5f$\n", nb);
	ft_printf(">>>|%-.5f$\n", nb);
	printf("\n===|%5f$\n", nb);
	ft_printf(">>>|%5f$\n", nb);
	printf("\n===|% 5f$\n", nb);
	ft_printf(">>>|% 5f$\n", nb);
	printf("\n===|%+5f$\n", nb);
	ft_printf(">>>|%+5f$\n", nb);
	printf("\n===|%# 5f$\n", nb);
	ft_printf(">>>|%# 5f$\n", nb);
	printf("\n===|%#+5f$\n", nb);
	ft_printf(">>>|%#+5f$\n", nb);
	printf("\n===|%-5f$\n", nb);
	ft_printf(">>>|%-5f$\n", nb);
	printf("\n===|%05f$\n", nb);
	ft_printf(">>>|%05f$\n", nb);
	printf("\n===|%+05f$\n", nb);
	ft_printf(">>>|%+05f$\n", nb);
	printf("\n===|%0+5f$\n", nb);
	ft_printf(">>>|%0+5f$\n", nb);
	printf("\n===|%05.3f$\n", nb);
	ft_printf(">>>|%05.3f$\n", nb);
	printf("\n===|%0#5.0f$\n", nb);
	ft_printf(">>>|%0#5.0f$\n", nb);
	printf("\n===|%-5.3f$\n", nb);
	ft_printf(">>>|%-5.3f$\n", nb);
	printf("\n===|%-#5.0f$\n", nb);
	ft_printf(">>>|%-#5.0f$\n", nb);
	printf("\n===|%+05.3f$\n", nb);
	ft_printf(">>>|%+05.3f$\n", nb);
	printf("\n===|%0+#5.0f$\n", nb);
	ft_printf(">>>|%0+#5.0f$\n", nb);
	printf("\n===|%0 5.3f$\n", nb);
	ft_printf(">>>|%0 5.3f$\n", nb);
	printf("\n===|% 05.3f$\n", nb);
	ft_printf(">>>|% 05.3f$\n", nb);
	printf("\n===|%#0 5.0f$\n", nb);
	ft_printf(">>>|%#0 5.0f$\n", nb);
	printf("\n===|%-+5.3f$\n", nb);
	ft_printf(">>>|%-+5.3f$\n", nb);
	printf("\n===|%-#+5.0f$\n", nb);
	ft_printf(">>>|%-#+5.0f$\n", nb);

	
	nb = -8965421.12356432156;
	printf("\n===|% f$\n", nb);
	ft_printf(">>>|% f$\n", nb);
	printf("\n===|%+f$\n", nb);
	ft_printf(">>>|%+f$\n", nb);
	printf("\n===|%#f$\n", nb);
	ft_printf(">>>|%#f$\n", nb);
	printf("\n===|%.2f$\n", nb);
	ft_printf(">>>|%.2f$\n", nb);
	printf("\n===|%.14f$\n", nb);
	ft_printf(">>>|%.14f$\n", nb);
	printf("\n===|%#.0f$\n", nb);
	ft_printf(">>>|%#.0f$\n", nb);
	printf("\n===|% .5f$\n", nb);
	ft_printf(">>>|% .5f$\n", nb);
	printf("\n===|%# .0f$\n", nb);
	ft_printf(">>>|%# .0f$\n", nb);
	printf("\n===|% #.0f$\n", nb);
	ft_printf(">>>|% #.0f$\n", nb);
	printf("\n===|%+.5f$\n", nb);
	ft_printf(">>>|%+.5f$\n", nb);
	printf("\n===|%+.0f$\n", nb);
	ft_printf(">>>|%+.0f$\n", nb);
	printf("\n===|%#+.0f$\n", nb);
	ft_printf(">>>|%#+.0f$\n", nb);
	printf("\n===|%0.5f$\n", nb);
	ft_printf(">>>|%0.5f$\n", nb);
	printf("\n===|%-.5f$\n", nb);
	ft_printf(">>>|%-.5f$\n", nb);
	printf("\n===|%5f$\n", nb);
	ft_printf(">>>|%5f$\n", nb);
	printf("\n===|% 5f$\n", nb);
	ft_printf(">>>|% 5f$\n", nb);
	printf("\n===|%+5f$\n", nb);
	ft_printf(">>>|%+5f$\n", nb);
	printf("\n===|%# 5f$\n", nb);
	ft_printf(">>>|%# 5f$\n", nb);
	printf("\n===|%#+5f$\n", nb);
	ft_printf(">>>|%#+5f$\n", nb);
	printf("\n===|%-5f$\n", nb);
	ft_printf(">>>|%-5f$\n", nb);
	printf("\n===|%05f$\n", nb);
	ft_printf(">>>|%05f$\n", nb);
	printf("\n===|%+05f$\n", nb);
	ft_printf(">>>|%+05f$\n", nb);
	printf("\n===|%0+5f$\n", nb);
	ft_printf(">>>|%0+5f$\n", nb);
	printf("\n===|%05.3f$\n", nb);
	ft_printf(">>>|%05.3f$\n", nb);
	printf("\n===|%0#5.0f$\n", nb);
	ft_printf(">>>|%0#5.0f$\n", nb);
	printf("\n===|%-5.3f$\n", nb);
	ft_printf(">>>|%-5.3f$\n", nb);
	printf("\n===|%-#5.0f$\n", nb);
	ft_printf(">>>|%-#5.0f$\n", nb);
	printf("\n===|%+05.3f$\n", nb);
	ft_printf(">>>|%+05.3f$\n", nb);
	printf("\n===|%0+#5.0f$\n", nb);
	ft_printf(">>>|%0+#5.0f$\n", nb);
	printf("\n===|%0 5.3f$\n", nb);
	ft_printf(">>>|%0 5.3f$\n", nb);
	printf("\n===|% 05.3f$\n", nb);
	ft_printf(">>>|% 05.3f$\n", nb);
	printf("\n===|%#0 5.0f$\n", nb);
	ft_printf(">>>|%#0 5.0f$\n", nb);
	printf("\n===|%-+5.3f$\n", nb);
	ft_printf(">>>|%-+5.3f$\n", nb);
	printf("\n===|%-#+5.0f$\n", nb);
	ft_printf(">>>|%-#+5.0f$\n", nb);

	//	TEST "NAN" && "INF" PAS ENCORE IMPLEMENTER

	// nb = 1.0/0.0;
	
	// printf("\n===|%f$\n", nb);
	// ft_printf(">>>|%f$\n", nb);
	// printf("\n===|%12f$\n", nb);
	// ft_printf(">>>|%12f$\n", nb);
	// printf("\n===|%-12f$\n", nb);
	// ft_printf(">>>|%-12f$\n", nb);
	// printf("\n===|%5.9f$\n", nb);
	// ft_printf(">>>|%5.9f$\n", nb);
// 
    // nb = -1.0/0.0;
	
	// printf("\n===|%f$\n", nb);
	// ft_printf(">>>|%f$\n", nb);
	// printf("\n===|%12f$\n", nb);
	// ft_printf(">>>|%12f$\n", nb);
	// printf("\n===|%-12f$\n", nb);
	// ft_printf(">>>|%-12f$\n", nb);
	// printf("\n===|%5.9f$\n", nb);
	// ft_printf(">>>|%5.9f$\n", nb);
// 
	// nb = 0.0/0.0;
	
	// printf("\n===|%f$\n", nb);
	// ft_printf(">>>|%f$\n", nb);
	// printf("\n===|%12f$\n", nb);
	// ft_printf(">>>|%12f$\n", nb);
	// printf("\n===|%-12f$\n", nb);
	// ft_printf(">>>|%-12f$\n", nb);
	// printf("\n===|%5.9f$\n", nb);
	// ft_printf(">>>|%5.9f$\n", nb);

	return (0);
}


/* RESULTAT SUR MON SUPER PC LINUX DE LA MORT

=== PRINTF
>>> FT_PRINTF

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.58$
>>>|-12547.58$

===|-12547.57999999999993$
>>>|-12547.57999999999993$

===|-12547.57999999999993$
>>>|-12547.57999999999993$

===|-12548.$
>>>|-12548.$

===|-12547.58000$
>>>|-12547.58000$

===|-12548.$
>>>|-12548.$

===|-12548.$
>>>|-12548.$

===|-12547.58000$
>>>|-12547.58000$

===|-12548$
>>>|-12548$

===|-12548.$
>>>|-12548.$

===|-12547.58000$
>>>|-12547.58000$

===|-12547.58000$
>>>|-12547.58000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580000$
>>>|-12547.580000$

===|-12547.580$
>>>|-12547.580$

===|-12548.$
>>>|-12548.$

===|-12547.580$
>>>|-12547.580$

===|-12548.$
>>>|-12548.$

===|-12547.580$
>>>|-12547.580$

===|-12548.$
>>>|-12548.$

===|-12547.580$
>>>|-12547.580$

===|-12547.580$
>>>|-12547.580$

===|-12548.$
>>>|-12548.$

===|-12547.580$
>>>|-12547.580$

===|-12548.$
>>>|-12548.$

===| 0.000000$
>>>| 0.000000$

===|+0.000000$
>>>|+0.000000$

===|0.000000$
>>>|0.000000$

===|0.00$
>>>|0.00$

===|0.00000000000000$
>>>|0.00000000000000$

===|0.$
>>>|0.$

===| 0.00000$
>>>| 0.00000$

===| 0.$
>>>| 0.$

===| 0.$
>>>| 0.$

===|+0.00000$
>>>|+0.00000$

===|+0$
>>>|+0$

===|+0.$
>>>|+0.$

===|0.00000$
>>>|0.00000$

===|0.00000$
>>>|0.00000$

===|0.000000$
>>>|0.000000$

===| 0.000000$
>>>| 0.000000$

===|+0.000000$
>>>|+0.000000$

===| 0.000000$
>>>| 0.000000$

===|+0.000000$
>>>|+0.000000$

===|0.000000$
>>>|0.000000$

===|0.000000$
>>>|0.000000$

===|+0.000000$
>>>|+0.000000$

===|+0.000000$
>>>|+0.000000$

===|0.000$
>>>|0.000$

===|0000.$
>>>|0000.$

===|0.000$
>>>|0.000$

===|0.   $
>>>|0.   $

===|+0.000$
>>>|+0.000$

===|+000.$
>>>|+000.$

===| 0.000$
>>>| 0.000$

===| 0.000$
>>>| 0.000$

===| 000.$
>>>| 000.$

===|+0.000$
>>>|+0.000$

===|+0.  $
>>>|+0.  $

===| 45.123457$
>>>| 45.123457$

===|+45.123457$
>>>|+45.123457$

===|45.123457$
>>>|45.123457$

===|45.12$
>>>|45.12$

===|45.12345678900000$
>>>|45.12345678900000$

===|45.$
>>>|45.$

===| 45.12346$
>>>| 45.12346$

===| 45.$
>>>| 45.$

===| 45.$
>>>| 45.$

===|+45.12346$
>>>|+45.12346$

===|+45$
>>>|+45$

===|+45.$
>>>|+45.$

===|45.12346$
>>>|45.12346$

===|45.12346$
>>>|45.12346$

===|45.123457$
>>>|45.123457$

===| 45.123457$
>>>| 45.123457$

===|+45.123457$
>>>|+45.123457$

===| 45.123457$
>>>| 45.123457$

===|+45.123457$
>>>|+45.123457$

===|45.123457$
>>>|45.123457$

===|45.123457$
>>>|45.123457$

===|+45.123457$
>>>|+45.123457$

===|+45.123457$
>>>|+45.123457$

===|45.123$
>>>|45.123$

===|0045.$
>>>|0045.$

===|45.123$
>>>|45.123$

===|45.  $
>>>|45.  $

===|+45.123$
>>>|+45.123$

===|+045.$
>>>|+045.$

===| 45.123$
>>>| 45.123$

===| 45.123$
>>>| 45.123$

===| 045.$
>>>| 045.$

===|+45.123$
>>>|+45.123$

===|+45. $
>>>|+45. $

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.12$
>>>|-8965421.12$

===|-8965421.12356432154775$
>>>|-8965421.12356432154775$

===|-8965421.$
>>>|-8965421.$

===|-8965421.12356$
>>>|-8965421.12356$

===|-8965421.$
>>>|-8965421.$

===|-8965421.$
>>>|-8965421.$

===|-8965421.12356$
>>>|-8965421.12356$

===|-8965421$
>>>|-8965421$

===|-8965421.$
>>>|-8965421.$

===|-8965421.12356$
>>>|-8965421.12356$

===|-8965421.12356$
>>>|-8965421.12356$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.123564$
>>>|-8965421.123564$

===|-8965421.124$
>>>|-8965421.124$

===|-8965421.$
>>>|-8965421.$

===|-8965421.124$
>>>|-8965421.124$

===|-8965421.$
>>>|-8965421.$

===|-8965421.124$
>>>|-8965421.124$

===|-8965421.$
>>>|-8965421.$

===|-8965421.124$
>>>|-8965421.124$

===|-8965421.124$
>>>|-8965421.124$

===|-8965421.$
>>>|-8965421.$

===|-8965421.124$
>>>|-8965421.124$

===|-8965421.$
>>>|-8965421.$

*/