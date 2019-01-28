#include "ft_printf.h"

int main()
{
    char			c = 'h';
	
	printf("in main:%lu\n", (unsigned long)&c);
	printf("%-100p|\n", &c);
	ft_printf("%-100p|\n", &c);
    
	return (0);
}
