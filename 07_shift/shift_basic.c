/*
 * 07_shift/shift_basic.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * 第2章 ビット演算
 * #7 シフト演算
 */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t value = 12;

    printf("value      : %u\n", (unsigned int)value);
    printf("value << 1 : %u\n", (unsigned int)(value << 1));
    printf("value << 2 : %u\n", (unsigned int)(value << 2));
    printf("value >> 1 : %u\n", (unsigned int)(value >> 1));
    printf("value >> 2 : %u\n", (unsigned int)(value >> 2));

    return 0;
}
