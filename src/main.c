#include "ft_printf.h"

int main()
{
    char	c = 'h';
	
	printf("%200p|\n", &c);
	ft_printf("%200p|\n", &c);
    
	return (0);
}
