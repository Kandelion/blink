#include "Arduino.h"

class Blink{
 public:
  Blink(int pin);
  void on(int time_ms);
  void off(int time_ms);
 private:
  int _pin;
};
