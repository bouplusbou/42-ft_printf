#include <stdio.h>

int main()
{
    printf("%%[flags][width][.precision][size]type\n");
    printf("%%[#,0,-,+,' '][1-x][.0-x][h,hh,l,ll,L]type\n");

    printf("\nc : Char\n");
    printf("printf(\"%%c\\n\", 45)\n");
    printf("%c\n", 45);
    printf("printf(\"%%c\\n\", 'b')\n");
    printf("%c\n", 'b');


    printf("printf(\"%%#s\\n\", \"Hello World\")\n");
    printf("%+s\n", "Hello World");




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

    return (0);
}