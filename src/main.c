#include "ft_printf.h"

int main()
{
	
	// printf("result:%#-x|\n", 1000);
	printf("result:%#x|\n", 1000);
	printf("result:%#.x|\n", 1000);
	printf("result:%#.100x|\n", 1000);
	printf("result:%#100.x|\n", 1000);
	printf("result:%#100.100x|\n", 1000);
	printf("result:%#100.99x|\n", 1000);
	printf("result:%#99.100x|\n", 1000);
	ft_printf("%x\n", 1000);
    
	return (0);
}
