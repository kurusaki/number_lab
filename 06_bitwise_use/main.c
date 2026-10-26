/*
 * 06_bitwise_use/main.c
 *
 * プログラマーのための数の教養
 * ～0と1から学ぶコンピュータの世界～
 *
 * 第2章 ビット演算
 * #6 ビット演算は何に使う？
 */

#include <stdint.h>
#include <stdio.h>

/* アプリケーションの設定フラグ */
#define FLAG_SOUND         (1u << 0)
#define FLAG_NOTIFICATION  (1u << 1)
#define FLAG_DARK_MODE     (1u << 2)

/* アクセス権 */
#define PERMISSION_EXECUTE  (1u << 0)
#define PERMISSION_WRITE    (1u << 1)
#define PERMISSION_READ     (1u << 2)

/* ゲームのプレイヤー状態 */
#define STATE_POISONED    (1u << 0)
#define STATE_SHIELDED    (1u << 1)
#define STATE_INVINCIBLE  (1u << 2)

/* 仮想的な組み込み機器の制御ビット */
#define DEVICE_LED     (1u << 0)
#define DEVICE_MOTOR   (1u << 1)
#define DEVICE_BUZZER  (1u << 2)

/* 8ビットの値を2進数で表示する */
static void print_binary8(uint8_t value)
{
    for (int bit = 7; bit >= 0; bit--) {
        printf("%u", (unsigned int)((value >> bit) & 1u));
    }
}

/* ラベル、2進数、10進数を1行に表示する */
static void print_value(const char *label, uint8_t value)
{
    printf("%s : ", label);
    print_binary8(value);
    printf("  (%u)\n", (unsigned int)value);
}

/* マスクに対応するビットがONかOFFかを表示する */
static void print_on_off(const char *label, uint8_t value, uint8_t mask)
{
    printf("%s : %s\n", label, (value & mask) != 0u ? "ON" : "OFF");
}

int main(void)
{
    uint8_t settings = 0u;
    settings |= FLAG_SOUND;
    settings |= FLAG_NOTIFICATION;
    settings &= (uint8_t)~FLAG_SOUND;

    printf("[1] フラグ管理\n");
    print_value("設定", settings);
    print_on_off("サウンド", settings, FLAG_SOUND);
    print_on_off("通知", settings, FLAG_NOTIFICATION);
    print_on_off("ダークモード", settings, FLAG_DARK_MODE);

    uint8_t permission = (uint8_t)(PERMISSION_READ | PERMISSION_WRITE);

    printf("\n[2] アクセス権\n");
    print_value("権限", permission);
    print_on_off("読み取り", permission, PERMISSION_READ);
    print_on_off("書き込み", permission, PERMISSION_WRITE);
    print_on_off("実行", permission, PERMISSION_EXECUTE);

    uint8_t player_state = 0u;
    player_state |= STATE_POISONED;
    player_state |= STATE_SHIELDED;

    printf("\n[3] ゲームの状態\n");
    print_value("プレイヤー", player_state);
    print_on_off("毒", player_state, STATE_POISONED);
    print_on_off("シールド", player_state, STATE_SHIELDED);
    print_on_off("無敵", player_state, STATE_INVINCIBLE);

    uint8_t control_register = 0u;
    control_register |= DEVICE_LED;
    control_register |= DEVICE_MOTOR;
    control_register &= (uint8_t)~DEVICE_MOTOR;

    printf("\n[4] 組み込み機器の制御\n");
    print_value("制御レジスタ", control_register);
    print_on_off("LED", control_register, DEVICE_LED);
    print_on_off("モーター", control_register, DEVICE_MOTOR);
    print_on_off("ブザー", control_register, DEVICE_BUZZER);

    return 0;
}
