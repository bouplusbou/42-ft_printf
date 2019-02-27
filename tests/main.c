/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:53:03 by bboucher          #+#    #+#             */
/*   Updated: 2019/02/27 10:45:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	// int	pf;

	// pf = fopen("coucou.txt", "w");
	
	// if (!pf)
	// 	printf("SORRY\n");
	// else
	// {
	// 	printf("OK\n");
	// 	// fprintf(pf, "%s", "WRITEOK");
		ft_printf("{fd}*%*s\n", 2, "saucisse");
	// }
	// fprintf(stderr, "%s", "Stack overflow!\n");
	return (0);
}
