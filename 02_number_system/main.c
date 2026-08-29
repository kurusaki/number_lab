/*
 * 02_number_system/main.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * #2 10進数・2進数・8進数・16進数とは？
 */

#include <stdio.h>
#include "../common/binary.h"

int main(void)
{
    int decimal = 10;
    int binary = 0b1010;
    int octal = 012;
    int hexadecimal = 0xA;

    printf("10進数リテラル : %d\n", decimal);
    printf("2進数リテラル  : %d\n", binary);
    printf("8進数リテラル  : %d\n", octal);
    printf("16進数リテラル : %d\n", hexadecimal);

    printf("\n10をそれぞれの進数で表示\n");

    printf("10進数 : %d\n", decimal);

    printf("2進数  : ");
    print_binary8(decimal);

    printf("8進数  : %o\n", decimal);
    printf("16進数 : %X\n", decimal);

    return 0;
}
