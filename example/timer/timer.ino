#include "ae7seg.h"

#define PIN_LATCH 9
#define INTERVAL 1000

AE7SEGSPI ae7seg(PIN_LATCH);

void setup() {}

void loop() {
  static uint16_t count = 0;

  ae7seg.beginWrite();
  {
    if (count >= 1000)
      ae7seg.writeNumber((count / 1000) % 10);
    else
      ae7seg.clear();

    ae7seg.writeNumber((count / 100) % 10, true);
    ae7seg.writeNumber((count / 10) % 10);
    ae7seg.writeNumber(count % 10);
  }
  ae7seg.endWrite();
  delay(INTERVAL);

  count++;

  if (count >= 10000)
    count = 0;
}
