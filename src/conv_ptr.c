#include "ft_printf.h"

#include <stdlib.h>
#include <stdio.h>

int		ft_find_size(int nb, int base)
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
	char	*base = "0123456789ABCDEF";

	return (base[i]);
}


char	*ft_itoabase(int nb, int base)
{
	char	*str;
	int		size;

	size = ft_find_size(nb, base);
	if (nb < 0)
		size++;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[size] = '\0';
	size--;
	printf("nb:%d\n", nb);
	while (nb >= base)
	{
		str[size] = ft_find_value(nb % base);
		nb = nb / base;
		size--;
	}
	str[size] = ft_find_value(nb);
	return (str);
}

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	while (n--) // on se sert de n comme d'un index donc on doit commencer par enlever 1
// 		((char *)dst)[n] = ((char *)src)[n];
// 	return (dst);
// }

int convert_ptr(t_struct data, void *target)
{
	char	*result;
	int		resultSize;
	int 	ptr = (int)&target;

	resultSize = data.width > 11 ? data.width : 11;	// Getting string size depending on width.
	result = ft_strnew(resultSize);		// Creating string.
	ft_memset(result, ' ', resultSize);	// Filling with spaces depending on flags.
	if ((data.width <= 11) || ft_strchr(data.flags, '-'))
		ft_memcpy(result, ptr, 11);
	else
		ft_memcpy(result, ptr, data.width - 1);
	ft_putstr("Result of char(p) conversion : []");
	ft_putstr(result);	// Printing result.
	ft_putstr("[]");
	return (resultSize);
}
