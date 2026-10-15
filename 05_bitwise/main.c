/*
 * 05_bitwise/main.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * 第2章 ビット演算
 * #5 ビット演算とは？
 */

#include <stdint.h>
#include <stdio.h>

/* 8ビットの値を2進数で表示する */
static void print_binary8(uint8_t value)
{
    for (int bit = 7; bit >= 0; bit--) {
        printf("%u", (unsigned int)((value >> bit) & 1u));
    }
}

/* 演算名、2進数、10進数を1行に表示する */
static void print_result(const char *name, uint8_t value)
{
    printf("%-5s : ", name);
    print_binary8(value);
    printf("  10進数: %u\n", (unsigned int)value);
}

int main(void)
{
    uint8_t a = 0b11001100;
    uint8_t b = 0b10101010;

    uint8_t and_result = (uint8_t)(a & b);
    uint8_t or_result = (uint8_t)(a | b);
    uint8_t xor_result = (uint8_t)(a ^ b);
    uint8_t not_result = (uint8_t)~a;

    print_result("A", a);
    print_result("B", b);

    printf("\n");
    print_result("AND", and_result);
    print_result("OR", or_result);
    print_result("XOR", xor_result);
    print_result("NOT A", not_result);

    return 0;
}
