/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_and_none.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclaudio <bclaudio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:43:56 by bclaudio          #+#    #+#             */
/*   Updated: 2019/02/01 15:08:54 by bclaudio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_char_and_none()
{
	char c = 'c';
	printf("OR.Result:%c|\n", c);
	ft_printf("FT.Result:%c|\n\n", c);
	printf("OR.Result:%1c|\n", c);
	ft_printf("FT.Result:%1c|\n\n", c);
	printf("OR.Result:%7c|\n", c);
	ft_printf("FT.Result:%7c|\n\n", c);
	printf("OR.Result:%-1c|\n", c);
	ft_printf("FT.Result:%-1c|\n\n", c);
	printf("OR.Result:%-5c|\n", c);
	ft_printf("FT.Result:%-5c|\n\n", c);
	printf("OR.Result:%c|\n", c);
	ft_printf("FT.Result:%c|\n\n", c);
	printf("OR.Result:%12c|\n", c);
	ft_printf("FT.Result:%12c|\n\n", c);
	printf("OR.Result:%-1c|\n", c);
	ft_printf("FT.Result:%-1c|\n\n", c);
	printf("OR.Result:%1c|\n", c);
	ft_printf("FT.Result:%1c|\n\n", c);
	printf("OR.Result:%5c|\n", c);
	ft_printf("FT.Result:%5c|\n\n", c);
	printf("OR.Result:%-5c|\n", c);
	ft_printf("FT.Result:%-5c|\n\n", c);
	printf("OR.Result:%c|\n", 0);
	ft_printf("FT.Result:%c|\n\n", 0);
	printf("OR.Result:%c|\n", 0);
	ft_printf("FT.Result:%c|\n\n", 0);
	printf("OR.Result:%%|\n");
	ft_printf("FT.Result:%%|\n\n");
	printf("OR.Result:%%%%%d|\n", -120);
	ft_printf("FT.Result:%%%%%d|\n", -120);
}
