#pragma once
#include <Arduino.h>

#define AE7SEG_DIGIT_DOT 0x01
#define AE7SEG_DIGIT_ALL 0xfe

enum {
  AE7SEG_DIGITS_CLEAR = 0b00000000,
  AE7SEG_DIGITS_0     = 0b11111100,
  AE7SEG_DIGITS_1     = 0b01100000,
  AE7SEG_DIGITS_2     = 0b11011010,
  AE7SEG_DIGITS_3     = 0b11110010,
  AE7SEG_DIGITS_4     = 0b01100110,
  AE7SEG_DIGITS_5     = 0b10110110,
  AE7SEG_DIGITS_6     = 0b10111110,
  AE7SEG_DIGITS_7     = 0b11100000,
  AE7SEG_DIGITS_8     = 0b11111110,
  AE7SEG_DIGITS_9     = 0b11110110,
  AE7SEG_DIGITS_A     = 0b11101110,
  AE7SEG_DIGITS_B     = 0b00111110,
  AE7SEG_DIGITS_C     = 0b00011010,
  AE7SEG_DIGITS_D     = 0b01111010,
  AE7SEG_DIGITS_E     = 0b10011110,
  AE7SEG_DIGITS_F     = 0b10001110,
};

class AE7SEGBase {
 protected:
  uint8_t latchPin;

  uint8_t generateDigit(uint8_t number);

 public:
  AE7SEGBase(uint8_t latchPin);

  void beginWrite();
  void endWrite();

  void writeNumber(uint8_t number);
  void writeNumber(uint8_t number, bool dot);
  virtual void writeDigit(uint8_t digit) = 0;

  void clear();
  void clear(bool dot);
};

class AE7SEGSPI : public AE7SEGBase {
 public:
  AE7SEGSPI(uint8_t latchPin);

  void writeDigit(uint8_t digit) override;
};

class AE7SEGGPIO : public AE7SEGBase {
 private:
  uint8_t sdiPin;
  uint8_t sckPin;

 public:
  AE7SEGGPIO(uint8_t latchPin, uint8_t sdiPin, uint8_t sckPin);

  void writeDigit(uint8_t digit) override;
};
