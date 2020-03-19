#include "ae7seg.h"

#include <SPI.h>

AE7SEGBase::AE7SEGBase(uint8_t latchPin) {
  this->latchPin = latchPin;
  pinMode(latchPin, OUTPUT);
  digitalWrite(latchPin, HIGH);
}

uint8_t AE7SEGBase::generateDigit(uint8_t number) {
  switch (number) {
    case 0:
      return AE7SEG_DIGITS_0;
    case 1:
      return AE7SEG_DIGITS_1;
    case 2:
      return AE7SEG_DIGITS_2;
    case 3:
      return AE7SEG_DIGITS_3;
    case 4:
      return AE7SEG_DIGITS_4;
    case 5:
      return AE7SEG_DIGITS_5;
    case 6:
      return AE7SEG_DIGITS_6;
    case 7:
      return AE7SEG_DIGITS_7;
    case 8:
      return AE7SEG_DIGITS_8;
    case 9:
      return AE7SEG_DIGITS_9;
    case 10:
      return AE7SEG_DIGITS_A;
    case 11:
      return AE7SEG_DIGITS_B;
    case 12:
      return AE7SEG_DIGITS_C;
    case 13:
      return AE7SEG_DIGITS_D;
    case 14:
      return AE7SEG_DIGITS_E;
    case 15:
      return AE7SEG_DIGITS_F;
    default:
      return AE7SEG_DIGITS_CLEAR;
  }
}

void AE7SEGBase::beginWrite() {
  digitalWrite(this->latchPin, LOW);
}

void AE7SEGBase::endWrite() {
  digitalWrite(this->latchPin, HIGH);
}

void AE7SEGBase::writeNumber(uint8_t number) {
  this->writeNumber(number, false);
}

void AE7SEGBase::writeNumber(uint8_t number, bool dot) {
  if (dot)
    this->writeDigit(generateDigit(number) | AE7SEG_DIGIT_DOT);
  else
    this->writeDigit(generateDigit(number) & AE7SEG_DIGIT_ALL);
}

void AE7SEGBase::clear() {
  this->writeDigit(AE7SEG_DIGITS_CLEAR);
}

void AE7SEGBase::clear(bool dot) {
  this->writeDigit(dot ? AE7SEG_DIGIT_DOT : AE7SEG_DIGITS_CLEAR);
}

AE7SEGSPI::AE7SEGSPI(uint8_t latchPin) : AE7SEGBase(latchPin) {
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
}

void AE7SEGSPI::writeDigit(uint8_t digit) {
  SPI.transfer(digit);
}

AE7SEGGPIO::AE7SEGGPIO(uint8_t latchPin, uint8_t sdiPin, uint8_t sckPin) : AE7SEGBase(latchPin) {
  this->sdiPin = sdiPin;
  this->sckPin = sckPin;
  pinMode(sdiPin, OUTPUT);
  pinMode(sckPin, OUTPUT);
  digitalWrite(sdiPin, LOW);
  digitalWrite(sckPin, HIGH);
}

void AE7SEGGPIO::writeDigit(uint8_t digit) {
  digitalWrite(this->sdiPin, digit & 0b00000001);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b00000010);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b00000100);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b00001000);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b00010000);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b00100000);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b01000000);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, digit & 0b10000000);
  digitalWrite(this->sckPin, HIGH);
  digitalWrite(this->sckPin, LOW);

  digitalWrite(this->sdiPin, LOW);
}
