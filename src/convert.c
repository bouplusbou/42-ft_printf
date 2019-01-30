#include "ft_printf.h"

int	convert(t_struct data, va_list list)
{
	// (void)list;
	if (data.type == 'c')
	{
		return (convert_char(data, va_arg(list, int)));
	}
	if (data.type == 'p')
	{
		return (convert_ptr(data, va_arg(list, void*)));
	}
	if (data.type == 'x' || data.type == 'X')
	{
		return (convert_hex(data, va_arg(list, unsigned int)));
	}
	return (0);
}
