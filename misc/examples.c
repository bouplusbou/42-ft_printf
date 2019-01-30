#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
  /*   printf("%%[flags][width][.precision][size]type\n");
    printf("%%[#,0,-,+,' '][1-x][.0-x][h,hh,l,ll,L]type\n");
 */
	unsigned short s = 100;
	unsigned char c = 255;
	unsigned long l = 100;
	unsigned long long ll = 100;

	printf("%x|\n", 12345678);
	printf("%#x|\n", 12345678);
	printf("%.10x|\n", 12345678);
	printf("%#.10x|\n", 12345678);
	printf("%#10x|\n", 12345678);
	// printf("%0x\n", 100);
	// printf("%020x\n", 100);
	// printf("%0.20x\n", 100);
	// printf("%0.20x\n", 100);
	// printf("%#x\n", 100);
	// printf("%#-x\n", 100);
	// printf("%#0x\n", 100);
	// printf("%#20x\n", 100);
	// printf("%#.20x\n", 100);
	// printf("%#20.20x\n", 100);
	// printf("%0x\n", 100);
	// printf("%-x\n", 100);
	// printf("%-20x|\n", 100);
	// printf("%10x\n", 100);
	// printf("%.20x\n", 100);
	// printf("%#.20x\n", 100);
	// printf("%hx\n", s);
	// printf("%hhx\n", c);
	// printf("%lx\n", l);
	// printf("%llx\n", ll);



	// printf("result:%#-100.99X|\n", 1000);
	// ft_printf("%#-100.99X|\n", 1000);
	// printf("result:%-100X|\n", 1000);
	// ft_printf("%-100X|\n", 1000);
	// printf("result:%-2.2X|\n", 1000);
	// ft_printf("%-2.2X|\n", 1000);
	// printf("result:%100X|\n", 1000);
	// ft_printf("%100X|\n", 1000);	
	// printf("result:%X|\n", 1000);
	// ft_printf("%X|\n", 1000);
	// printf("result:%02X|\n", 1000);
	// ft_printf("%02X|\n", 1000);
	// printf("result:%0100X|\n", 1000);
	// ft_printf("%0100X|\n", 1000);
	// printf("result:%02.2X|\n", 1000);
	// ft_printf("%02.2X|\n", 1000);
	// printf("result:%#x|\n", 1000);
	// ft_printf("%#x|\n", 1000);
	// printf("result:%#.x|\n", 1000);
	// ft_printf("%#.x|\n", 1000);
	// printf("result:%#.100x|\n", 1000);
	// ft_printf("%#.100x|\n", 1000);
	// printf("result:%#100.x|\n", 1000);
	// ft_printf("%#100.x|\n", 1000);
	// printf("result:%#100.100x|\n", 1000);
	// ft_printf("%#100.100x|\n", 1000);
	// printf("result:%#100.99x|\n", 1000);
	// ft_printf("%#100.99x|\n", 1000);
	// printf("result:%#99.100x|\n", 1000);
	// ft_printf("%#99.100x|\n", 1000);



	// printf("%+x", 100); // pas a gerer
	// printf("% x", 100); // pas a gerer
	// printf("%Lx", 100); // pas a gerer
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