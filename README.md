ae7seg
======

[English version is here.](README_en.md)

秋月電子の 7セグメントLEDシリアルドライバモジュール [AE-7SEG-BOARD](http://akizukidenshi.com/catalog/g/gK-10194/) のためのライブラリです。

ドット表示、複数桁、SPI または GPIO による接続に対応しています。

## 特徴

- シフトレジスタ 74595 を使った7セグLEDの制御
- ドット表示対応
- 任意のセグメントの表示に対応
- 複数桁対応（桁数に制限なし）
- SPI または GPIO による接続に対応 (SDI, SCKピンを任意に指定可)

## 使用方法

ライブラリをインストール後、 `ae7seg.h` をインクルードしてください。

```cpp
#include <ae7seg.h>
```

その後、 `AE7SEGSPI` または `AE7SEGGPIO` を宣言し、Latchピンの番号を指定してください。

```cpp
// use SPI
AE7SEGSPI ae7seg(PIN_LATCH);

// ...or use GPIO
AE7SEGGPIO ae7seg(PIN_LATCH, PIN_SDI, PIN_SCK);
```

一桁表示させる際は、`writeNumber(number)` 関数を `beginWrite()` と `endWrite()` で囲って呼んでください。

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(7);  // to display "7"
ae7seg.endWrite();
```

複数桁表示させる際は、`writeNumber(number)` を必要な桁の数だけ呼んでください。

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(4);  // the most significant digit = "4"
ae7seg.writeNumber(2);
ae7seg.endWrite();
```

ドットを表示させる際は、`writeNumber(number, true)` を呼んでください。

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(4, true);  // display a dot segment
ae7seg.writeNumber(2);        // not display implicitly
ae7seg.endWrite();
```

任意のセグメントを表示させる際は、`writeNumber(number)` の代わりに `writeDigit(digit)` を呼んでください。

```cpp
ae7seg.beginWrite();
ae7seg.writeDigit(0b01101110);  // "H"
ae7seg.endWrite();
```


## ライセンス

MIT License
