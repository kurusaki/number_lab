/*
 * 03_hexadecimal/main.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * #3 なぜ16進数なの？
 */

#include <stdint.h>
#include <stdio.h>
#include "../common/binary.h"

int main(void)
{
    uint8_t value = 0xAC;
    uint8_t data[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
    unsigned int red = 0x33;
    unsigned int green = 0x99;
    unsigned int blue = 0xFF;

    printf("1桁の16進数は4ビットに対応\n");
    printf("0xA = 1010\n");
    printf("0xC = 1100\n");
    printf("0xAC = ");
    print_binary8(value);

    printf("\n2桁の16進数で1バイトを表現\n");
    printf("10進数 : %u\n", (unsigned int)value);
    printf("16進数 : 0x%02X\n", (unsigned int)value);
    printf("1バイトの最大値 : 0xFF = %u\n", UINT8_MAX);

    printf("\nメモリアドレス\n");
    printf("valueのアドレス : %p\n", (void *)&value);

    printf("\nカラーコード\n");
    printf("RGB(%u, %u, %u) = #%02X%02X%02X\n",
           red, green, blue, red, green, blue);

    printf("\nダンプ表示\n");
    for (size_t i = 0; i < sizeof(data); i++) {
        printf("%02X ", (unsigned int)data[i]);
    }
    putchar('\n');

    return 0;
}
