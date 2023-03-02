# Extended Pin Change Interrupt Library
## 概要
Arduino Unoの外部割込み機能を全デジタルピンで使えるように拡張するライブラリです．
* 純正の機能と殆ど同じように使えます．
* 全てのデジタルピンで使えます．
* 立ち上がり，立下りは自分で判断する必要があります．

例えばZ相の存在するロータリーエンコーダをデコードするなどといった用途にも使えます．

## 使い方
Arduino標準関数と似た様な使い方ができます．
```c++
#include <PinChangeInterrupt.h>

void pin_change_cb()

const uint8_t pcint_pin = 10; // 使いたいデジタルピン
PinChangeInterrupt pcint;

void setup() {
  pcint.attachInterrupt(pcint_pin, pin_change_cb);
}

void loop() {}

// 割り込み時に呼び出される関数
void pin_change_cb() {
  if (digitalRead(pcint)) {
    // 立ち上りのときの処理
  } else {
    // 立ち下りのときの処理
  }
}
```

割り込みを解除するときは`detachInterrupt()`を呼び出してください．


※ 2017年頃に[僕が書いた記事](http://fugufugu.blog.jp/archives/1068651729.html)の奴を漸く上げました．
