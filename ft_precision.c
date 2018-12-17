/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:38:09 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/17 16:16:54 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <float.h>

long long int		ft_ceil(double x)
{
	return (x + 0.5);
}

double	ft_precision(float nbr, int dec_pos)
{
	int		offset;

	offset = 10;
	while (--dec_pos > 0)
		offset *= 10;
	return((double)ft_ceil(nbr * offset) / offset);
}

int main() 
{ 
//	float num = -5.489;
	float test = FLT_MAX; 
	printf("%f\n", test);

//	num = ceil(10000 * num); 
//	printf("vrai ceil: %f\n", num); 
//	num /= 10000; 
//	printf("num:				%f\n", num); 

	test = ft_precision(test, 0); 
//	printf("test ceil: %f\n", test); 
	printf("test:				%f\n", test); 

//	printf("%f\n", 5.48958123); 
	printf("printf with precision:		%.0f\n", test); 
	return 0; 
} 

/*
   float ft_round_nbr(float nbr, int dec)
   {

   }
   */
