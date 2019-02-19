/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/19 13:56:23 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// si arg negatif ou si '+' => ajoute le signe, avant les 0 si precision
// flag ' ' ignored avec flag '+'
static void test_float1()
{
        double          nb;
        nb = -12547.58;

                printf("% f$\n", nb);
				ft_printf("% f$\n", nb);
                printf("%+f$\n", nb);
				ft_printf("%+f$\n", nb);
                printf("%#f$\n", nb);
				ft_printf("%#f$\n", nb);
                printf("%.2f$\n", nb);
				ft_printf("%.2f$\n", nb);
                printf("%.14f$\n", nb);
				ft_printf("%.14f$\n", nb);
                printf("%#.0f$\n", nb);
				ft_printf("%#.0f$\n", nb);
                printf("% .5f$\n", nb);
				ft_printf("% .5f$\n", nb);
                printf("%# .0f$\n", nb);
				ft_printf("%# .0f$\n", nb);
                printf("% #.0f$\n", nb);
				ft_printf("% #.0f$\n", nb);
                printf("%+.5f$\n", nb);
				ft_printf("%+.5f$\n", nb);
                printf("%+.0f$\n", nb);
				ft_printf("%+.0f$\n", nb);
                printf("%#+.0f$\n", nb);
				ft_printf("%#+.0f$\n", nb);
                printf("%0.5f$\n", nb);
				ft_printf("%0.5f$\n", nb);
                printf("%-.5f$\n", nb);
				ft_printf("%-.5f$\n", nb);
                printf("%5f$\n", nb);
				ft_printf("%5f$\n", nb);
                printf("% 5f$\n", nb);
				ft_printf("% 5f$\n", nb);
                printf("%+5f$\n", nb);
				ft_printf("%+5f$\n", nb);
                printf("%# 5f$\n", nb);
				ft_printf("%# 5f$\n", nb);
                printf("%#+5f$\n", nb);
				ft_printf("%#+5f$\n", nb);
                printf("%-5f$\n", nb);
				ft_printf("%-5f$\n", nb);
                printf("%05f$\n", nb);
				ft_printf("%05f$\n", nb);
                printf("%+05f$\n", nb);
				ft_printf("%+05f$\n", nb);
                printf("%0+5f$\n", nb);
				ft_printf("%0+5f$\n", nb);
                printf("%05.3f$\n", nb);
				ft_printf("%05.3f$\n", nb);
                printf("%0#5.0f$\n", nb);
				ft_printf("%0#5.0f$\n", nb);
                printf("%-5.3f$\n", nb);
				ft_printf("%-5.3f$\n", nb);
                printf("%-#5.0f$\n", nb);
				ft_printf("%-#5.0f$\n", nb);
                printf("%+05.3f$\n", nb);
				ft_printf("%+05.3f$\n", nb);
                printf("%0+#5.0f$\n", nb);
				ft_printf("%0+#5.0f$\n", nb);
                printf("%0 5.3f$\n", nb);
				ft_printf("%0 5.3f$\n", nb);
                printf("% 05.3f$\n", nb);
				ft_printf("% 05.3f$\n", nb);
                printf("%#0 5.0f$\n", nb);
				ft_printf("%#0 5.0f$\n", nb);
                printf("%-+5.3f$\n", nb);
				ft_printf("%-+5.3f$\n", nb);
                printf("%-#+5.0f$\n", nb);
				ft_printf("%-#+5.0f$\n", nb);
}

static void test_float2()
{

        double          nb;
        nb = 0;

                printf("% f$\n", nb);
				ft_printf("% f$\n", nb);
                printf("\n");
				printf("%+f$\n", nb);
				ft_printf("%+f$\n", nb);
                printf("\n");
				printf("%#f$\n", nb);
				ft_printf("%#f$\n", nb);
                printf("\n");
				printf("%.2f$\n", nb);
				ft_printf("%.2f$\n", nb);
                printf("\n");
				printf("%.14f$\n", nb);
				ft_printf("%.14f$\n", nb);
                printf("\n");
				printf("%#.0f$\n", nb);
				ft_printf("%#.0f$\n", nb);
                printf("\n");
				printf("% .5f$\n", nb);
				ft_printf("% .5f$\n", nb);
                printf("\n");
				printf("%# .0f$\n", nb);
				ft_printf("%# .0f$\n", nb);
                printf("\n");
				printf("% #.0f$\n", nb);
				ft_printf("% #.0f$\n", nb);
                printf("\n");
				printf("%+.5f$\n", nb);
				ft_printf("%+.5f$\n", nb);
                printf("\n");
				printf("%+.0f$\n", nb);
				ft_printf("%+.0f$\n", nb);
                printf("\n");
				printf("%#+.0f$\n", nb);
				ft_printf("%#+.0f$\n", nb);
                printf("\n");
				printf("%0.5f$\n", nb);
				ft_printf("%0.5f$\n", nb);
                printf("\n");
				printf("%-.5f$\n", nb);
				ft_printf("%-.5f$\n", nb);
                printf("\n");
				printf("%5f$\n", nb);
				ft_printf("%5f$\n", nb);
                printf("\n");
				printf("% 5f$\n", nb);
				ft_printf("% 5f$\n", nb);
                printf("\n");
				printf("%+5f$\n", nb);
				ft_printf("%+5f$\n", nb);
                printf("\n");
				printf("%# 5f$\n", nb);
				ft_printf("%# 5f$\n", nb);
                printf("\n");
				printf("%#+5f$\n", nb);
				ft_printf("%#+5f$\n", nb);
                printf("\n");
				printf("%-5f$\n", nb);
				ft_printf("%-5f$\n", nb);
                printf("\n");
				printf("%05f$\n", nb);
				ft_printf("%05f$\n", nb);
                printf("\n");
				printf("%+05f$\n", nb);
				ft_printf("%+05f$\n", nb);
                printf("\n");
				printf("%0+5f$\n", nb);
				ft_printf("%0+5f$\n", nb);
                printf("\n");
				printf("%05.3f$\n", nb);
				ft_printf("%05.3f$\n", nb);
                printf("\n");
				printf("%0#5.0f$\n", nb);
				ft_printf("%0#5.0f$\n", nb);
                printf("\n");
				printf("%-5.3f$\n", nb);
				ft_printf("%-5.3f$\n", nb);
                printf("\n");
				printf("%-#5.0f$\n", nb);
				ft_printf("%-#5.0f$\n", nb);
                printf("\n");
				printf("%+05.3f$\n", nb);
				ft_printf("%+05.3f$\n", nb);
                printf("\n");
				printf("%0+#5.0f$\n", nb);
				ft_printf("%0+#5.0f$\n", nb);
                printf("\n");
				printf("%0 5.3f$\n", nb);
				ft_printf("%0 5.3f$\n", nb);
                printf("\n");
				printf("% 05.3f$\n", nb);
				ft_printf("% 05.3f$\n", nb);
                printf("\n");
				printf("%#0 5.0f$\n", nb);
				ft_printf("%#0 5.0f$\n", nb);
                printf("\n");
				printf("%-+5.3f$\n", nb);
				ft_printf("%-+5.3f$\n", nb);
                printf("\n");
				printf("%-#+5.0f$\n", nb);
				ft_printf("%-#+5.0f$\n", nb);
}

static void test_float3()
{
        double          nb;
    nb = 45.123456789;

                printf("% f$\n", nb);
				ft_printf("% f$\n", nb);
                printf("%+f$\n", nb);
				ft_printf("%+f$\n", nb);
                printf("%#f$\n", nb);
				ft_printf("%#f$\n", nb);
                printf("%.2f$\n", nb);
				ft_printf("%.2f$\n", nb);
                printf("%.14f$\n", nb);
				ft_printf("%.14f$\n", nb);
                printf("%#.0f$\n", nb);
				ft_printf("%#.0f$\n", nb);
                printf("% .5f$\n", nb);
				ft_printf("% .5f$\n", nb);
                printf("%# .0f$\n", nb);
				ft_printf("%# .0f$\n", nb);
                printf("% #.0f$\n", nb);
				ft_printf("% #.0f$\n", nb);
                printf("%+.5f$\n", nb);
				ft_printf("%+.5f$\n", nb);
                printf("%+.0f$\n", nb);
				ft_printf("%+.0f$\n", nb);
                printf("%#+.0f$\n", nb);
				ft_printf("%#+.0f$\n", nb);
                printf("%0.5f$\n", nb);
				ft_printf("%0.5f$\n", nb);
                printf("%-.5f$\n", nb);
				ft_printf("%-.5f$\n", nb);
                printf("%5f$\n", nb);
				ft_printf("%5f$\n", nb);
                printf("% 5f$\n", nb);
				ft_printf("% 5f$\n", nb);
                printf("%+5f$\n", nb);
				ft_printf("%+5f$\n", nb);
                printf("%# 5f$\n", nb);
				ft_printf("%# 5f$\n", nb);
                printf("%#+5f$\n", nb);
				ft_printf("%#+5f$\n", nb);
                printf("%-5f$\n", nb);
				ft_printf("%-5f$\n", nb);
                printf("%05f$\n", nb);
				ft_printf("%05f$\n", nb);
                printf("%+05f$\n", nb);
				ft_printf("%+05f$\n", nb);
                printf("%0+5f$\n", nb);
				ft_printf("%0+5f$\n", nb);
                printf("%05.3f$\n", nb);
				ft_printf("%05.3f$\n", nb);
                printf("%0#5.0f$\n", nb);
				ft_printf("%0#5.0f$\n", nb);
                printf("%-5.3f$\n", nb);
				ft_printf("%-5.3f$\n", nb);
                printf("%-#5.0f$\n", nb);
				ft_printf("%-#5.0f$\n", nb);
                printf("%+05.3f$\n", nb);
				ft_printf("%+05.3f$\n", nb);
                printf("%0+#5.0f$\n", nb);
				ft_printf("%0+#5.0f$\n", nb);
                printf("%0 5.3f$\n", nb);
				ft_printf("%0 5.3f$\n", nb);
                printf("% 05.3f$\n", nb);
				ft_printf("% 05.3f$\n", nb);
                printf("%#0 5.0f$\n", nb);
				ft_printf("%#0 5.0f$\n", nb);
                printf("%-+5.3f$\n", nb);
				ft_printf("%-+5.3f$\n", nb);
                printf("%-#+5.0f$\n", nb);
				ft_printf("%-#+5.0f$\n", nb);
}

static void test_float4()
{
        double          nb;
    nb = 12389123798;

                printf("% f$\n", nb);
				ft_printf("% f$\n", nb);
                printf("%+f$\n", nb);
				ft_printf("%+f$\n", nb);
                printf("%#f$\n", nb);
				ft_printf("%#f$\n", nb);
                printf("%.2f$\n", nb);
				ft_printf("%.2f$\n", nb);
                printf("%.14f$\n", nb);
				ft_printf("%.14f$\n", nb);
                printf("%#.0f$\n", nb);
				ft_printf("%#.0f$\n", nb);
                printf("% .5f$\n", nb);
				ft_printf("% .5f$\n", nb);
                printf("%# .0f$\n", nb);
				ft_printf("%# .0f$\n", nb);
                printf("% #.0f$\n", nb);
				ft_printf("% #.0f$\n", nb);
                printf("%+.5f$\n", nb);
				ft_printf("%+.5f$\n", nb);
                printf("%+.0f$\n", nb);
				ft_printf("%+.0f$\n", nb);
                printf("%#+.0f$\n", nb);
				ft_printf("%#+.0f$\n", nb);
                printf("%0.5f$\n", nb);
				ft_printf("%0.5f$\n", nb);
                printf("%-.5f$\n", nb);
				ft_printf("%-.5f$\n", nb);
                printf("%5f$\n", nb);
				ft_printf("%5f$\n", nb);
                printf("% 5f$\n", nb);
				ft_printf("% 5f$\n", nb);
                printf("%+5f$\n", nb);
				ft_printf("%+5f$\n", nb);
                printf("%# 5f$\n", nb);
				ft_printf("%# 5f$\n", nb);
                printf("%#+5f$\n", nb);
				ft_printf("%#+5f$\n", nb);
                printf("%-5f$\n", nb);
				ft_printf("%-5f$\n", nb);
                printf("%05f$\n", nb);
				ft_printf("%05f$\n", nb);
                printf("%+05f$\n", nb);
				ft_printf("%+05f$\n", nb);
                printf("%0+5f$\n", nb);
				ft_printf("%0+5f$\n", nb);
                printf("%05.3f$\n", nb);
				ft_printf("%05.3f$\n", nb);
                printf("%0#5.0f$\n", nb);
				ft_printf("%0#5.0f$\n", nb);
                printf("%-5.3f$\n", nb);
				ft_printf("%-5.3f$\n", nb);
                printf("%-#5.0f$\n", nb);
				ft_printf("%-#5.0f$\n", nb);
                printf("%+05.3f$\n", nb);
				ft_printf("%+05.3f$\n", nb);
                printf("%0+#5.0f$\n", nb);
				ft_printf("%0+#5.0f$\n", nb);
                printf("%0 5.3f$\n", nb);
				ft_printf("%0 5.3f$\n", nb);
                printf("% 05.3f$\n", nb);
				ft_printf("% 05.3f$\n", nb);
                printf("%#0 5.0f$\n", nb);
				ft_printf("%#0 5.0f$\n", nb);
                printf("%-+5.3f$\n", nb);
				ft_printf("%-+5.3f$\n", nb);
                printf("%-#+5.0f$\n", nb);
				ft_printf("%-#+5.0f$\n", nb);
}

static void test_float5()
{
        double          nb;
    nb = -8965421.12356432156;

                printf("% f$\n", nb);
				ft_printf("% f$\n", nb);
                printf("\n");
				printf("%+f$\n", nb);
				ft_printf("%+f$\n", nb);
                printf("\n");
				printf("%#f$\n", nb);
				ft_printf("%#f$\n", nb);
                printf("\n");
				printf("%.2f$\n", nb);
				ft_printf("%.2f$\n", nb);
                printf("\n");
				printf("%.14f$\n", nb);
				ft_printf("%.14f$\n", nb);
                printf("\n");
				printf("%#.0f$\n", nb);
				ft_printf("%#.0f$\n", nb);
                printf("\n");
				printf("% .5f$\n", nb);
				ft_printf("% .5f$\n", nb);
                printf("\n");
				printf("%# .0f$\n", nb);
				ft_printf("%# .0f$\n", nb);
                printf("\n");
				printf("% #.0f$\n", nb);
				ft_printf("% #.0f$\n", nb);
                printf("\n");
				printf("%+.5f$\n", nb);
				ft_printf("%+.5f$\n", nb);
                printf("\n");
				printf("%+.0f$\n", nb);
				ft_printf("%+.0f$\n", nb);
                printf("\n");
				printf("%#+.0f$\n", nb);
				ft_printf("%#+.0f$\n", nb);
                printf("\n");
				printf("%0.5f$\n", nb);
				ft_printf("%0.5f$\n", nb);
                printf("\n");
				printf("%-.5f$\n", nb);
				ft_printf("%-.5f$\n", nb);
                printf("\n");
				printf("%5f$\n", nb);
				ft_printf("%5f$\n", nb);
                printf("\n");
				printf("% 5f$\n", nb);
				ft_printf("% 5f$\n", nb);
                printf("\n");
				printf("%+5f$\n", nb);
				ft_printf("%+5f$\n", nb);
                printf("\n");
				printf("%# 5f$\n", nb);
				ft_printf("%# 5f$\n", nb);
                printf("\n");
				printf("%#+5f$\n", nb);
				ft_printf("%#+5f$\n", nb);
                printf("\n");
				printf("%-5f$\n", nb);
				ft_printf("%-5f$\n", nb);
                printf("\n");
				printf("%05f$\n", nb);
				ft_printf("%05f$\n", nb);
                printf("\n");
				printf("%+05f$\n", nb);
				ft_printf("%+05f$\n", nb);
                printf("\n");
				printf("%0+5f$\n", nb);
				ft_printf("%0+5f$\n", nb);
                printf("\n");
				printf("%05.3f$\n", nb);
				ft_printf("%05.3f$\n", nb);
                printf("\n");
				printf("%0#5.0f$\n", nb);
				ft_printf("%0#5.0f$\n", nb);
                printf("\n");
				printf("%-5.3f$\n", nb);
				ft_printf("%-5.3f$\n", nb);
                printf("\n");
				printf("%-#5.0f$\n", nb);
				ft_printf("%-#5.0f$\n", nb);
                printf("\n");
				printf("%+05.3f$\n", nb);
				ft_printf("%+05.3f$\n", nb);
                printf("\n");
				printf("%0+#5.0f$\n", nb);
				ft_printf("%0+#5.0f$\n", nb);
                printf("\n");
				printf("%0 5.3f$\n", nb);
				ft_printf("%0 5.3f$\n", nb);
                printf("\n");
				printf("% 05.3f$\n", nb);
				ft_printf("% 05.3f$\n", nb);
                printf("\n");
				printf("%#0 5.0f$\n", nb);
				ft_printf("%#0 5.0f$\n", nb);
                printf("\n");
				printf("%-+5.3f$\n", nb);
				ft_printf("%-+5.3f$\n", nb);
                printf("\n");
				printf("%-#+5.0f$\n", nb);
				ft_printf("%-#+5.0f$\n", nb);
}

static void test_float6()
{
        double          nb;

    nb = 1.0/0.0;
                printf("%f$\n", nb);
				ft_printf("%f$\n", nb);
                printf("%12f$\n", nb);
				ft_printf("%12f$\n", nb);
                printf("%-12f$\n", nb);
				ft_printf("%-12f$\n", nb);
                printf("%5.9f$\n", nb);
				ft_printf("%5.9f$\n", nb);

    nb = -1.0/0.0;
                printf("%f$\n", nb);
				ft_printf("%f$\n", nb);
                printf("%12f$\n", nb);
				ft_printf("%12f$\n", nb);
                printf("%-12f$\n", nb);
				ft_printf("%-12f$\n", nb);
                printf("%5.9f$\n", nb);
				ft_printf("%5.9f$\n", nb);

        nb = 0.0/0.0;
                printf("%f$\n", nb);
				ft_printf("%f$\n", nb);
                printf("%12f$\n", nb);
				ft_printf("%12f$\n", nb);
                printf("%-12f$\n", nb);
				ft_printf("%-12f$\n", nb);
                printf("%5.9f$\n", nb);
				ft_printf("%5.9f$\n", nb);
}

static void test_float7()
{
        float           nb;
        nb = -0.000;

                printf("% f$\n", nb);
				ft_printf("% f$\n", nb);
                printf("%+f$\n", nb);
				ft_printf("%+f$\n", nb);
                printf("%#f$\n", nb);
				ft_printf("%#f$\n", nb);
                printf("%.2f$\n", nb);
				ft_printf("%.2f$\n", nb);
                printf("%.14f$\n", nb);
				ft_printf("%.14f$\n", nb);
                printf("%#.0f$\n", nb);
				ft_printf("%#.0f$\n", nb);
                printf("% .5f$\n", nb);
				ft_printf("% .5f$\n", nb);
                printf("%# .0f$\n", nb);
				ft_printf("%# .0f$\n", nb);
                printf("% #.0f$\n", nb);
				ft_printf("% #.0f$\n", nb);
                printf("%+.5f$\n", nb);
				ft_printf("%+.5f$\n", nb);
                printf("%+.0f$\n", nb);
				ft_printf("%+.0f$\n", nb);
                printf("%#+.0f$\n", nb);
				ft_printf("%#+.0f$\n", nb);
                printf("%0.5f$\n", nb);
				ft_printf("%0.5f$\n", nb);
                printf("%-.5f$\n", nb);
				ft_printf("%-.5f$\n", nb);
                printf("%5f$\n", nb);
				ft_printf("%5f$\n", nb);
                printf("% 5f$\n", nb);
				ft_printf("% 5f$\n", nb);
                printf("%+5f$\n", nb);
				ft_printf("%+5f$\n", nb);
                printf("%# 5f$\n", nb);
				ft_printf("%# 5f$\n", nb);
                printf("%#+5f$\n", nb);
				ft_printf("%#+5f$\n", nb);
                printf("%-5f$\n", nb);
				ft_printf("%-5f$\n", nb);
                printf("%05f$\n", nb);
				ft_printf("%05f$\n", nb);
                printf("%+05f$\n", nb);
				ft_printf("%+05f$\n", nb);
                printf("%0+5f$\n", nb);
				ft_printf("%0+5f$\n", nb);
                printf("%05.3f$\n", nb);
				ft_printf("%05.3f$\n", nb);
                printf("%0#5.0f$\n", nb);
				ft_printf("%0#5.0f$\n", nb);
                printf("%-5.3f$\n", nb);
				ft_printf("%-5.3f$\n", nb);
                printf("%-#5.0f$\n", nb);
				ft_printf("%-#5.0f$\n", nb);
                printf("%+05.3f$\n", nb);
				ft_printf("%+05.3f$\n", nb);
                printf("%0+#5.0f$\n", nb);
				ft_printf("%0+#5.0f$\n", nb);
                printf("%0 5.3f$\n", nb);
				ft_printf("%0 5.3f$\n", nb);
                printf("% 05.3f$\n", nb);
				ft_printf("% 05.3f$\n", nb);
                printf("%#0 5.0f$\n", nb);
				ft_printf("%#0 5.0f$\n", nb);
                printf("%-+5.3f$\n", nb);
				ft_printf("%-+5.3f$\n", nb);
                printf("%-#+5.0f$\n", nb);
				ft_printf("%-#+5.0f$\n", nb);
}

void test_ft_float()
{
        // test_float1();
        test_float2();
        // test_float3();`
        // test_float4();`
        // test_float5();`
        // test_float6();`
        // test_float7();
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	double nb = 123.456;
	double nb2 = -123.456;

	// test_ft_float();
	ft_printf("%f", nb);
	ft_printf("%f", nb2);
	// nb = -12547.48;
	// printf(" 7 precision + hash:%#.0f$\n", nb);
		// ft_printf(" 7 precision + hash:%#.0f$\n", nb);
	// ft_printf(" 7 precision + hash:%#.0f$\n", nb);
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
	return (0);
}
