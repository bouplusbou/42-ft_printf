#include "ft_printf.h"

int main()
{
    ft_printf("Conv here -> %%#4.20hs <- just here %23.6i \n", 42);
    // printf("return de ft_printf: %d\n", ft_printf("Conv here -> %%d %s <- just here\n", 42)); //tester avec %d en fin de str
    return (0);
}