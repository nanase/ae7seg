ae7seg
======

This is a library for [AE-7SEG-BOARD](http://akizukidenshi.com/catalog/g/gK-10194/), a 7-segment LED serial driver module from Akizuki Electronics.

The library supports dot segments, multi-digit, SPI or GPIO connections.

## Features

- Controlling seven-segment LED using 74595 shift register
- Support display dot segment, and any segments
- Support multiple digits (no limit)
- Support SPI and GPIO (can use any pins as SDI and SCK)

## Usage

After the library is installed, include the header file to your sketch

```cpp
#include <ae7seg.h>
```

and then, declare `AE7SEGSPI` or `AE7SEGGPIO` and specify the number of LATCH pin.

```cpp
// use SPI
AE7SEGSPI ae7seg(PIN_LATCH);

// ...or use GPIO
AE7SEGGPIO ae7seg(PIN_LATCH, PIN_SDI, PIN_SCK);
```

Call `writeNumber(number)` function with `beginWrite()` and `endWrite()` in order to display one digit.

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(7);  // to display "7"
ae7seg.endWrite();
```

To write multiple digits, call `writeNumber(number)` as many digits as you need.

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(4);  // the most significant digit = "4"
ae7seg.writeNumber(2);
ae7seg.endWrite();
```

To display a dot segment, call `writeNumber(number, true)`. If there is no second argument, it is implicitly hidden.

```cpp
ae7seg.beginWrite();
ae7seg.writeNumber(4, true);  // display a dot segment
ae7seg.writeNumber(2);        // implicitly hidden a dot segment
ae7seg.endWrite();
```

To display any segment, call `writeDigit(digit)` instead of `writeNumber(number)`.

```cpp
ae7seg.beginWrite();
ae7seg.writeDigit(0b01101110);  // "H"
ae7seg.endWrite();
```


## License

MIT License
