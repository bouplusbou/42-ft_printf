/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/03 15:46:22 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int argc, char **argv)
{
	double nb;
	nb = -12547.48;
	printf(" 7 precision + hash:%#.0f$\n", nb);
	ft_printf(" 7 precision + hash:%#.0f$\n", nb);
	// printf("Real printf:%-016f|\n", nb);

		//Precision : chiffre apres la virgule
		//Croision : mettre virgule si jamais precision de 0

	// printf("BLABLA:%#.0f\n", nb1);
	// printf("test basique:");
	// printf("space:% f|\n", nb);
	// printf("plus:%+f|\n", nb);
	// printf("hash:%#f|\n", nb);
	// printf("precision:%.2f|\n", nb);
	// printf("big prec:%.14f|\n", nb);
	// printf("precision + hash:%#.0f|\n", nb);
	// printf("space + prec:% .5f|\n", nb);
	// printf("space + prec + hash:%# .0f|\n", nb);
	// printf("space + prec + hash:% #.0f|\n", nb);
	// printf("Plus + prec / grande:%+.5f|\n", nb);
	// printf("Plus + prec / petite:%+.0f|\n", nb);
	// printf("Plus + prec + hash:%#+.0f|\n", nb);
	// printf("Prec + 0:%0.5f|\n", nb);
	// printf("Prec + minus:%-.5f|\n", nb);
	// printf("size:%5f|\n", nb);
	// printf("size + space:% 5f|\n", nb);
	// printf("size + plus:%+5f|\n", nb);
	// printf("size + space:%# 5f|\n", nb);
	// printf("size + plus:%#+5f|\n", nb);
	// printf("size + minus:%-5f|\n", nb);
	// printf("size + 0:%05f|\n", nb);
	// printf("size + 0 + plus:%+05f|\n", nb);
	// printf("size + 0 + plus:%0+5f|\n", nb);
	// printf("size + 0 + prec:%05.3f|\n", nb);
	// printf("size + 0 + prec + hash:%0#5.0f|\n", nb);
	// printf("size + minus + prec:%-5.3f|\n", nb);
	// printf("size + minus + prec + hash:%-#5.0f|\n", nb);
	// printf("size + plus + 0 + prec:%+05.3f|\n", nb);
	// printf("size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	// printf("size + espace + zero + prec:%0 5.3f|\n", nb);
	// printf("size + espace + zero + prec:% 05.3f|\n", nb);
	// printf("size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	// printf("size + minus + plus + prec:%-+5.3f|\n", nb);
	// printf("size + minus + plus + prec + hash:%-#+5f|\n", nb);
	// long double f;
	// f = 8965421.14893116854;
	// int pre = 20;

	// char *result;
	// char *tmp;
	// int precision;

	// printf("PRINTF:%.20Lf|\n", f);
	// tmp = ft_lltoa_base((unsigned long long int)f, "0123456789");
	// f -= (long long int)f;
	// printf("Entier du float:%s\nReste:%Lf|\n", tmp, f);
	// result = ft_strjoinf(&result, &tmp, 2);
	// precision = pre == -1 ? 6 : pre;
	// while (precision)
	// {
	// 	f *= 10;
	// 	precision--;
	// }
	// if (pre >= 11)
	// 	f += 1;
	// tmp = ft_strdup(".");
	// result = ft_strjoinf(&result, &tmp, 1);
	// tmp = ft_ulltoa_base((unsigned long long int)f, "0123456789");
	// result = ft_strjoinf(&result, &tmp, 2);
	// printf("Result:%s\n", result);
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
