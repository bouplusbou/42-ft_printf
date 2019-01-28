/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:50:37 by bboucher          #+#    #+#             */
/*   Updated: 2019/01/28 18:53:35 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_size(unsigned long nb, int base)
{
	int	size;

	size = 1;
	while (nb / base)
	{
		nb /= base;
		size++;
	}
	return (size);
}

char	ft_find_value(int i)
{
	char	*base = "0123456789abcdef";

	return (base[i]);
}


char	*ft_ultoabase(unsigned long nb, int base)
{
	char	*str;
	int		size;

	size = ft_find_size(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size] = '\0';
	size--;
	while (nb >= (unsigned long)base)
	{
		str[size] = ft_find_value(nb % base);
		nb = nb / base;
		size--;
	}
	str[size] = ft_find_value(nb);
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n--) // on se sert de n comme d'un index donc on doit commencer par enlever 1
		((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}

int	convert_ptr(t_struct data, void *target)
{
	char	*result;
	char	*hexa;
	int		result_size;
	int		hexa_size;
	
	hexa = ft_ultoabase((unsigned long)target, 16);
	hexa_size = (int)ft_strlen(hexa) + 2; // taille d'hexa + 2 pour "0x"
	result_size = data.width > hexa_size ? data.width : hexa_size;	// Getting string size depending on width.
	result = ft_strnew(result_size);		// Creating string.
	ft_memset(result, ' ', result_size);	// Filling with spaces depending on flags.
	if (data.width > hexa_size && !ft_strchr(data.flags, '-'))
	{
		ft_memcpy(result + (resultSize - hexa_size), hexa, resultSize);
		ft_memcpy(result + (resultSize - hexa_size - 2), "0x", 2);
	}
	else
	{
		ft_memcpy(result, "0x", 2);
		ft_memcpy(result + 2, ft_ultoabase((unsigned long)target, 16), ft_strlen(hexa));
	}
	// ft_putstr("Result of char(p) conversion : []");
	ft_putstr(result);	// Printing result.
	// ft_putstr("[]");
	return (result_size);
}
