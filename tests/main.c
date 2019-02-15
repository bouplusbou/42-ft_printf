/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/15 17:45:01 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// si arg negatif ou si '+' => ajoute le signe, avant les 0 si precision
// flag ' ' ignored avec flag '+'

int main(int argc, char **argv)
{
	int pos = 12345;
	int neg = -12345;

	(void)argc;
	(void)argv;
	ft_printf("%010d|\n", 42);
	printf("%010d|\n", 42);
	ft_printf("%010.5d|\n", 42);
	printf("%010.5d|\n", 42);
	ft_printf("%010.d|\n", 42);
	printf("%010.d|\n", 42);
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

	return (0);
}
