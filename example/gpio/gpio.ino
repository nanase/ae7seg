#include "ae7seg.h"

#define PIN_SDI 5
#define PIN_SCK 4
#define PIN_LATCH 9
#define INTERVAL 1000

AE7SEGGPIO ae7seg(PIN_LATCH, PIN_SDI, PIN_SCK);

void setup() {}

void loop() {
  static uint16_t count = 0;

  ae7seg.beginWrite();
  ae7seg.writeNumber(count % 10);
  ae7seg.endWrite();
  delay(INTERVAL);

  count++;
}
