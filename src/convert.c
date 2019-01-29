#include "ft_printf.h"

int	convert(t_struct data, va_list list)
{
	// (void)list;
	if (data.type == 'c')
	{
		printf("Convertion of type C.\n");
		return (convert_char(data, va_arg(list, int)));
	}
	if (data.type == 'p')
	{
		printf("Convertion of type P.\n");
		return (convert_ptr(data, va_arg(list, void*)));
	}
	return (0);
}
