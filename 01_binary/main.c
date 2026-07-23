/*
 * 01_binary/main.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * #1 なぜプログラマーは2進数を学ぶの？
 */

#include <stdio.h>
#include "../common/binary.h"

int main(void)
{
    unsigned char number = 65;
    char ch = 'A';

    printf("10進数 : %u\n", number);
    printf("2進数  : ");
    print_binary8(number);

    printf("\n");

    printf("文字 : %c\n", ch);
    printf("文字コード : %d\n", ch);
    printf("2進数  : ");
    print_binary8(ch);

    return 0;
}
