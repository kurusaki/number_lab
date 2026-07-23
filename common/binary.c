/*
 * binary.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * 共通ライブラリ
 * 2進数表示用関数
 */

#include <stdio.h>
#include "binary.h"

/*
 * 8ビットを2進数で表示する
 */
void print_binary8(uint8_t value)
{
    for (int i = 7; i >= 0; i--) {
        putchar((value & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}