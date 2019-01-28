#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

// int		ft_find_size(unsigned long nb, int base)
// {
// 	int	size;

// 	size = 1;
// 	while (nb / base)
// 	{
// 		nb /= base;
// 		size++;
// 	}
// 	return (size);
// }

// char	ft_find_value(int i)
// {
// 	char	*base = "0123456789abcdef";

// 	return (base[i]);
// }


// char	*ft_ultoabase(unsigned long nb, int base)
// {
// 	char	*str;
// 	int		size;

// 	size = ft_find_size(nb, base);
// 	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
// 		return (0);
// 	str[size] = '\0';
// 	size--;
// 	while (nb >= base)
// 	{
// 		str[size] = ft_find_value(nb % base);
// 		nb = nb / base;
// 		size--;
// 	}
// 	str[size] = ft_find_value(nb);
// 	return (str);
// }


// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	while (n--)
// 		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
// 	return (dst);
// }

// int ft_printf(char *format, ...)
// {
// 	va_list	args;

// 	va_start(args, format);

// 	unsigned long s = va_arg(args, unsigned long);

// 	printf("%lu\n", (unsigned long)s);
	
// 	va_end(args);
// 	return 0;
// }


int main()
{
  /*   printf("%%[flags][width][.precision][size]type\n");
    printf("%%[#,0,-,+,' '][1-x][.0-x][h,hh,l,ll,L]type\n");
 */
	int		i = 42;
	char	*s = "hello";


	printf("%p\n", i);
	printf("%p\n", p);
	// void			*s = "coucou";

	// ft_printf("hello", &s);
	// printf("%lu\n", (unsigned long)&s);
	// unsigned long	ptr = (unsigned long)&s;
	// printf("%p\n", &s);
	// printf("0x%s\n", ft_ultoabase(ptr, 16));

	// printf("%lu\n", sizeof(signed long));




	// printf("%p\n", j);
    // printf("%100.2p\n", j);
    // printf("%hp\n", j);
    // printf("%hhp\n", j);
    // printf("%lp\n", j);
    // printf("%llp\n", j);
    // printf("%Lp\n", j);
    // printf("%-p\n", j);
    // printf("%1p\n", j);
    // printf("%12p\n", j);
    // printf("%-100p|\n", j);
    // printf("%#p\n", j); // pas à gerer
    // printf("%0p\n", j); // pas à gerer
    // printf("%+p\n", j); // pas à gerer
    // printf("% p\n", j); // pas à gerer
// 0x10dd39f8e
//                                                                                          0x10dd39f8e
// 0x10f19df8e                                                                                         |
/* 
    printf("\nc : Char\n");
    printf("printf(\"%%c\\n\", 45)\n");
    printf("%c\n", 45);
    printf("printf(\"%%c\\n\", 'b')\n");
    printf("%c\n", 'b');

    printf("\ns : Chaine de caractères\n");
    printf("printf(\"Hello World\")\n");
    printf("Hello World\n");
    printf("printf(\"%%s\\n\", \"Hello World\")\n");
    printf("%s\n", "Hello World");
    printf("printf(\"%%12s\\n\", \"Hello World\") // width 12\n");
    printf("%12s\n", "Hello World");
    printf("printf(\"%%-20s\\n\", \"Hello World\") // flag -, width 20\n");
    printf("%-20s\n", "Hello World");
    printf("printf(\"%%-s\\n\", \"Hello World\") // flag -\n");
    printf("%-s\n", "Hello World");
    printf("printf(\"%%.2s\\n\", \"Hello World\") // precision .2\n");
    printf("%.2s\n", "Hello World");
    printf("printf(\"%%.12s\\n\", \"Hello World\") // precision .12\n");
    printf("%.12s\n", "Hello World");
    printf("printf(\"%%3.2s\\n\", \"Hello World\") // width 3, precision .2\n");
    printf("%3.2s\n", "Hello World");
    printf("printf(\"%%-3.2s\\n\", \"Hello World\") // flag -, width 3, precision .2\n");
    printf("%-3.2s\n", "Hello World");
    printf("flag 0, flag #, flag +, flag ' ', all sizes h,hh,l,ll,L = undefined behavior\n");
    printf("%%.-2s, %%-3 .2s = invalid specifier\n");

    printf("\np : Adresse d'un pointeur en hexadécimal\n");
    printf("printf(\"%%p\\n\", \"Coucou\")\n");
    printf("%p\n", "Coucou");
    
    printf("\nd : Entier décimal signé\n");
    printf("printf(\"%%d\\n\", 45)\n");
    printf("%d\n", 45);
    printf("printf(\"%%0-d\\n\", 45)\n");
    printf("%+-d\n", 45);
    
    printf("\ni : Entier décimal signé\n");
    printf("printf(\"%%i\\n\", +45)\n");
    printf("%i\n", +45);
    printf("printf(\"%%i\\n\", -45)\n");
    printf("%i\n", -45);
    printf("printf(\"%%5i\\n\", 13) // width 5\n");
    printf("%5i\n", 13);   
    printf("printf(\"%%05i\\n\", 13) // flag 0, width 5\n");
    printf("%05i\n", 13);

    printf("\no : Entier octal non signé\n");
    printf("printf(\"%%o\\n\", 7)\n");
    printf("%o\n", 7);
    printf("printf(\"%%o\\n\", 8)\n");
    printf("%o\n", 8);
    printf("printf(\"%%#o\\n\", 8) // flag #\n");
    printf("%#o\n", 8);

    printf("\nu : Entier décimal non signé\n");
    printf("printf(\"%%n\\n\", -1)\n");
    printf("%u\n", -1);
    
    printf("\nx : Entier hexadécimal non signé avec lettre en minuscule\n");
    printf("printf(\"%%x\\n\", 10)\n");
    printf("%x\n", 10);
    printf("printf(\"%%#x\\n\", 10) // flag #\n");
    printf("%#x\n", 10);
    printf("printf(\"%%6x\\n\", 10) // width 6\n");
    printf("%6x\n", 10);
    printf("printf(\"%%06x\\n\", 10) // flag 0, width 6\n");
    printf("%06x\n", 10);

    printf("\nX : Entier hexadécimal non signé avec lettre en majuscule\n");
    printf("printf(\"%%X\\n\", 10)\n");
    printf("%X\n", 10);
    printf("printf(\"%%#X\\n\", 10) // flag #\n");
    printf("%#X\n", 10);

    printf("\nf : Chiffre a virgule. Le nombre de chiffres après la virgule dépend de la précision. (6 par défaut)\n");
    printf("printf(\"%%f\\n\", 45.10)\n");
    printf("%f\n", 45.10);
    
    printf("\nMix\n");
    printf("printf(\"%%s %%f\\n\", \" Hello\", 45.10)\n");
    printf("%s %f\n", " Hello", 45.10);

    int i = 2147483647;
    long l = 2147483647;
    long long ll = 9223372036854775807;
    char c = 0;
    intmax_t im = 9223372036854775807;
    unsigned int ui = 4294967295;

    printf("printf(\"%%#0-+ 123456789.0123456789hlLcdi\")\n");

    printf("%%\n");
    printf("%%%d\n", 42);
    printf("%d\n", 42);
    printf("%d%d\n", 42, 41);
    printf("%d%d%d\n", 42, 43, 44);
    printf("%ld\n", l);
    printf("%lld\n", ll);
    printf("%x\n", 505);
    printf("%X\n", 505);
    printf("%p\n", &im);
    printf("%20.15d\n", 54321);
    printf("%-10d\n", 3);
    printf("% d\n", 3);
    printf("%+d\n", 3);
    printf("%010d\n", 1);
    printf("%hhd\n", c);
    printf("%jd\n", 9223372036854775807);
    printf("%zd\n", 4294967295);
    printf("%U\n", ui);
    printf("%u\n", ui);
    printf("%x\n", 1000);
    printf("%#X\n", 1000);
    printf("%s\n", NULL);
    printf("%S\n", L"ݗݜशব");
    printf("%s%s\n", "test", "test");
    printf("%s%s%s\n", "test", "test", "test");
    printf("%C\n", 15000);
    printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
    printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
    printf("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
    printf("%x %#X %S %s%s\n", 1000, 1000, L"ݗݜशব", "test", "test2");

    printf("\n");
    printf("dfsd %%s"); */
    return (0);
}