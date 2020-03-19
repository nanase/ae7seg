ae7seg
======

This is an AE-7SEG-BOARD library to use seven-segment led display via 74595 (8-bit shift register/latch).

The library support dot segment, multiple digits, SPI and GPIO for communication.

## Features

- Controlling seven-segment LED using 74595 shift register
- Support display dot segment, and any segments
- Support multiple digits (no limit)
- Support SPI and GPIO (can use any pins as SDI and SCK)

## Usage

After install the library, include `ae7seg.h` to your sketch

```cpp
#include <ae7seg.h>
```

and then declare `AE7SEGSPI` or `AE7SEGGPIO` instance with pin number for latch.

```cpp
// use SPI
AE7SEGSPI ae7seg(PIN_LATCH);

// ...or use GPIO
AE7SEGGPIO ae7seg(PIN_LATCH, PIN_SDI, PIN_SCK);
```

When you want to write a digit, call `writeNumber(number)` function between `beginWrite()` and `endWrite()`.

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(7);  // to display "7"
ae7seg.endWrite();
```

To write multiple digits, call `writeNumber(number)` enough times.

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(4);  // the most significant digit = "4"
ae7seg.writeNumber(2);
ae7seg.endWrite();
```

If you want to display a dot segment, call `writeNumber(number, true)`.

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(4, true);  // display a dot segment
ae7seg.writeNumber(2);        // not display implicitly
ae7seg.endWrite();
```

If you want to display more segment, call `writeDigit(digit)` instead of `writeNumber(number)`.

```cpp
ae7seg.beginWrite();
ae7seg.writeDigit(0b01101110);  // "H"
ae7seg.endWrite();
```


## License

MIT License
