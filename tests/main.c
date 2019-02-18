/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudios <bclaudios@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/18 19:28:44 by bclaudios        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// si arg negatif ou si '+' => ajoute le signe, avant les 0 si precision
// flag ' ' ignored avec flag '+'

int main(int argc, char **argv)
{
	// int pos = 12345;
	// int neg = -12345;

	(void)argc;
	(void)argv;
	// ft_printf("%010d|\n", 42);
	// printf("%010d|\n", 42);
	// ft_printf("%010.5d|\n", 42);
	// printf("%010.5d|\n", 42);
	// ft_printf("%010.d|\n", 42);
	// printf("%010.d|\n", 42);
	// ft_printf("%5d\n", -42);
	// ft_printf("%-5d\n", -42);
	// ft_printf("%-05d\n", -42);
	// printf("%+ d|\n", pos);
	// // printf("%+ d|\n", neg);
	// printf("%0+d|\n", pos);
	// printf("%0+d|\n", neg);
	// printf("%0 d|\n", pos);
	// printf("%0 d|\n", neg);
	// printf("%0d|\n", pos);
	// printf("%0d|\n", neg);
	// printf("%010d|\n", pos);
	// printf("%010d|\n", neg);
	// printf("%- d|\n", pos);
	// printf("%- d|\n", neg);
	// printf("% d|\n", pos);
	// printf("% d|\n", neg);
	// printf("%+-d|\n", pos);
	// printf("%+-d|\n", neg);

	// char *c = "Bonjour";
	// ft_printf("%-20s\n", c);
	// ft_printf("%1s$\n", c);
	// ft_printf("%7s$\n", c);
	// ft_printf("%-1s$\n", c);
	// ft_printf("%-5s$\n", c);
	// ft_printf("%s$\n", c);
	// ft_printf("%12s$\n", c);
	// ft_printf("%-1s$\n", c);
	// ft_printf("%1s$\n", c);
	// ft_printf("%5s$\n", c);
	// ft_printf("%-5s$\n", c);
	ft_printf("%.5s$\n", NULL);
	return (0);
}
