/*
 * 04_byte/main.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * #4 1バイトはなぜ256通り？
 */

#include <stdint.h>
#include <stdio.h>
#include "../common/binary.h"

int main(void)
{
    uint8_t minimum = 0;
    uint8_t maximum = UINT8_MAX;
    unsigned int number_of_patterns = (unsigned int)UINT8_MAX + 1;

    uint8_t red = UINT8_MAX;
    uint8_t green = 0;
    uint8_t blue = 0;

    uint8_t ascii_code = 65;

    printf("1バイトは8ビット\n");
    printf("最小のビットパターン : ");
    print_binary8(minimum);
    printf("最大のビットパターン : ");
    print_binary8(maximum);

    printf("\n8ビットで表せる組み合わせ\n");
    printf("2の8乗 = %u通り\n", number_of_patterns);
    printf("符号なし整数の範囲 = %uから%u\n",
           (unsigned int)minimum,
           (unsigned int)maximum);
    printf("最大値を16進数で表示 = 0x%02X\n",
           (unsigned int)maximum);

    printf("\nRGBとの関係\n");
    printf("RGB(%u, %u, %u) = #%02X%02X%02X\n",
           (unsigned int)red,
           (unsigned int)green,
           (unsigned int)blue,
           (unsigned int)red,
           (unsigned int)green,
           (unsigned int)blue);

    printf("\nASCIIとの関係\n");
    printf("文字Aのコード = %u = 0x%02X = ",
           (unsigned int)ascii_code,
           (unsigned int)ascii_code);
    print_binary8(ascii_code);

    return 0;
}
