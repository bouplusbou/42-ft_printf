/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:53:03 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/26 14:45:30 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	ft_printf("ds {cyan} LOL\n");
	// ft_printf("{magenta}Sisi {green}{bold}la {red}{underline}SOURIS{eof} %s, {bold}{yellow}j'aime les bits{cyan} %b \n", "lol", 100);
	// ft_printf("Normal {red}RED {green}GREEN {yellow}YELLOW {blue}BLUE {magenta}MAGENTA {cyan}CYAN {white}WHITE\n");
	return (0);
}
