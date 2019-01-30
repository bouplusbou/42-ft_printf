#include "ft_printf.h"

int convert_char(t_struct data, int target)
{
	char	*result;
	int	resultSize;

	resultSize = data.width > 0 ? data.width : 1;	// Getting string size depending on width.
	result = ft_strnew(resultSize);		// Creating string.
	if (ft_strchr(data.flags, '0') && !ft_strchr(data.flags, '-'))
		ft_memset(result, '0', resultSize);	//Filling with 0 depending on flags.
	else
		ft_memset(result, ' ', resultSize);	// Filling with spaces depending on flags.
	result[ft_strchr(data.flags, '-') ? 0 : resultSize - 1] = target;	// Assigning char to the start/end of the result.
	// ft_putstr(result);	// Printing result.
	return (resultSize);
}
