# プログラマーのための数の教養

## ～0と1から学ぶコンピュータの世界～

# 第2章 ビット演算

#6 ビット演算は何に使う？

---

## はじめに

AND、OR、XOR、NOTは、整数を構成する各ビットを直接操作するための演算です。

これらの演算は、計算結果を求めるためだけでなく、複数のON・OFFの状態を1つの整数で管理するために使われます。

この回では、次の4つの用途をC言語のサンプルで確認します。

- アプリケーションのフラグ管理
- 読み取り・書き込み・実行のアクセス権
- ゲームのプレイヤー状態
- 組み込み機器の制御レジスタ

---

## この章で学ぶこと

- 1ビットで1つのON・OFFを表す方法
- ビットフラグとビットマスクの関係
- ANDでフラグを調べる方法
- ORでフラグをONにする方法
- ANDとNOTでフラグをOFFにする方法
- XORでONとOFFを切り替える方法
- フラグ管理、アクセス権、ゲーム、組み込みでの実用例

---

## 1ビットで1つの状態を表す

1ビットには、0か1のどちらかを保存できます。

```text
0  OFF、無効、許可なし
1  ON、 有効、許可あり
```

このように、状態がONかOFFかを表す値を「フラグ」と呼びます。

8ビットの整数なら、8つのON・OFFを1つの整数にまとめられます。

```text
bit 7  bit 6  bit 5  bit 4  bit 3  bit 2  bit 1  bit 0
  0      0      0      0      1      1      0      1
```

2進数の`00001101`は、10進数の`13`です。それぞれのビットに別の意味を割り当てれば、複数の状態を同時に表せます。

---

## ビットマスク

操作したいビットだけ1にした値を「ビットマスク」と呼びます。

例えば、bit 2のマスクは`00000100`です。C言語では、1を2ビット左に移動して作れます。

```c
#define MASK (1u << 2)
```

フラグ操作の基本は、次の4つです。

```text
調べる      flags & MASK
ONにする   flags | MASK
OFFにする  flags & ~MASK
切り替える flags ^ MASK
```

### 対象のビットを調べる

AND演算でマスクのビットだけを取り出します。

```c
if ((flags & MASK) != 0u) {
    /* 対象のビットはON */
}
```

### 対象のビットをONにする

OR演算を使うと、他のビットを変えずに対象だけを1にできます。

```c
flags |= MASK;
```

### 対象のビットをOFFにする

マスクをNOTで反転し、AND演算を行います。

```c
flags &= (uint8_t)~MASK;
```

### ONとOFFを切り替える

XOR演算を使うと、対象のビットを0から1、1から0へ切り替えられます。

```c
flags ^= MASK;
```

---

## 使い道1：フラグ管理

アプリケーションのサウンド、通知、ダークモードを、次のビットに割り当てます。

```text
bit 0  サウンド
bit 1  通知
bit 2  ダークモード
```

サウンドと通知をONにした後、サウンドだけをOFFにすると、結果は`00000010`になります。

---

## 使い道2：アクセス権

読み取り、書き込み、実行の権限を、次のように表せます。

```text
bit 2  読み取り  100  4
bit 1  書き込み  010  2
bit 0  実行          001  1
```

読み取りと書き込みをOR演算で組み合わせると、`110`、つまり10進数の`6`になります。

```text
  100  読み取り
| 010  書き込み
-----
  110
```

Unix系OSのファイルモードで使われる値も、このように権限ビットの組み合わせです。

※実際のファイルモードには、所有者、グループ、その他などの複数のビットがあります。

---

## 使い道3：ゲームの状態管理

ゲームでは、プレイヤーが毒、シールド、無敵などの状態を同時に持つことがあります。

```text
bit 0  毒状態
bit 1  シールド中
bit 2  無敵状態
```

毒とシールドをONにすると、プレイヤーの状態は`00000011`になります。AND演算を使えば、それぞれの状態がONかを別々に調べられます。

体力や残り時間のように複数の値を持つ情報ではなく、ONとOFFの2状態で表せる情報がビットフラグに向いています。

---

## 使い道4：組み込み機器の制御

組み込み機器では、マイコンのレジスタにある各ビットが、ハードウェアの機能に対応していることがあります。

このサンプルでは、次の仮想的な制御レジスタを使います。

```text
bit 0  LED
bit 1  モーター
bit 2  ブザー
```

LEDとモーターをONにした後、モーターだけをOFFにすると、値は`00000001`になります。LEDのビットは変化しません。

実際の開発では、レジスタのアドレス、各ビットの意味、読み書きの条件を、対象のマイコンのデータシートで確認する必要があります。

---

## ソースコード

ファイル名：`06_bitwise_use/main.c`

```c
#include <stdint.h>
#include <stdio.h>

#define FLAG_SOUND         (1u << 0)
#define FLAG_NOTIFICATION  (1u << 1)
#define FLAG_DARK_MODE     (1u << 2)

#define PERMISSION_EXECUTE  (1u << 0)
#define PERMISSION_WRITE    (1u << 1)
#define PERMISSION_READ     (1u << 2)

#define STATE_POISONED    (1u << 0)
#define STATE_SHIELDED    (1u << 1)
#define STATE_INVINCIBLE  (1u << 2)

#define DEVICE_LED     (1u << 0)
#define DEVICE_MOTOR   (1u << 1)
#define DEVICE_BUZZER  (1u << 2)

static void print_binary8(uint8_t value)
{
    for (int bit = 7; bit >= 0; bit--) {
        printf("%u", (unsigned int)((value >> bit) & 1u));
    }
}

static void print_value(const char *label, uint8_t value)
{
    printf("%s : ", label);
    print_binary8(value);
    printf("  (%u)\n", (unsigned int)value);
}

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
```

---

## コードの解説

### マスクを定義する

```c
#define FLAG_SOUND         (1u << 0)
#define FLAG_NOTIFICATION  (1u << 1)
#define FLAG_DARK_MODE     (1u << 2)
```

`1u << 0`は`00000001`、`1u << 1`は`00000010`、`1u << 2`は`00000100`です。

数値を直接書かず、意味が分かる定数名を付けることで、どのビットを操作しているかが読み取りやすくなります。

### ANDで状態を調べる

```c
(value & mask) != 0u
```

対象のビットが1なら結果は0以外になり、0なら結果は0になります。

### ORとAND・NOTで状態を変える

```c
settings |= FLAG_SOUND;
settings &= (uint8_t)~FLAG_SOUND;
```

1行目はサウンドをONにし、2行目はサウンドだけをOFFにします。

`uint8_t`の値を8ビットの範囲で扱う意図を明確にするため、反転したマスクを`uint8_t`へ明示的に変換しています。

---

## コンパイル

ターミナルで`06_bitwise_use`ディレクトリへ移動し、次のコマンドを実行します。

```bash
clang -std=c23 -Wall -Wextra -Wpedantic main.c -o bitwise_use
```

---

## 実行

```bash
./bitwise_use
```

実行結果：

```text
[1] フラグ管理
設定 : 00000010  (2)
サウンド : OFF
通知 : ON
ダークモード : OFF

[2] アクセス権
権限 : 00000110  (6)
読み取り : ON
書き込み : ON
実行 : OFF

[3] ゲームの状態
プレイヤー : 00000011  (3)
毒 : ON
シールド : ON
無敵 : OFF

[4] 組み込み機器の制御
制御レジスタ : 00000001  (1)
LED : ON
モーター : OFF
ブザー : OFF
```

---

## ビットフラグを使う理由

- 複数のON・OFFを1つの整数にまとめられる
- 必要なビットだけを調べたり変更したりできる
- ファイルや通信データにまとめて保存しやすい
- ハードウェアのレジスタと相性がよい

ビットの意味が分からないコードは読みにくくなります。`FLAG_SOUND`や`PERMISSION_READ`のような意味の分かる名前を使い、各ビットの役割を明確にすることが大切です。

---

## まとめ

- 1ビットで1つのON・OFFを表せる
- 1つの整数で複数のフラグを管理できる
- ANDでフラグを調べる
- ORでフラグをONにする
- ANDとNOTでフラグをOFFにする
- XORでフラグを切り替える
- 同じ仕組みが、設定、権限、ゲームの状態、組み込み機器の制御に使われる

---

## シリーズ一覧

- [#1 なぜプログラマーは2進数を学ぶの？](../01_binary/)
- [#2 10進数・2進数・8進数・16進数とは？](../02_number_system/)
- [#3 なぜ16進数なの？](../03_hexadecimal/)
- [#4 1バイトはなぜ256通り？](../04_byte/)
- [#5 ビット演算とは？AND・OR・XOR・NOTを0と1から理解しよう！](../05_bitwise/)
- **#6 ビット演算は何に使う？**
- #7 ビットシフトとは？（予定）
- #8 二の補数とは？（予定）
