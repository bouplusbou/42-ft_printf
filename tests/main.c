/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:00:10 by bclaudio          #+#    #+#             */
/*   Updated: 2019/05/23 17:40:22 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	printf("\n|ret:%d|\n", ft_printf("{green}%b", 100));
	printf("\n|ret:%d|\n", ft_printf("ds{{{{{}}}}{red}}{magenta}%s {blue} % b|\n", "OK", "lol"));
	ft_printf("{magenta}Sisi {green}{bold}la {red}{underline}SOURIS{eof} %s, {bold}{yellow}j'aime les bits{cyan} %b \n", "lol", 100);
	ft_printf("Normal {red}RED {green}GREEN {yellow}YELLOW {blue}BLUE {magenta}MAGENTA {cyan}CYAN {white}WHITE\n");
	return (0);
}
