#include "Blink.h"

/* 내장된 LED의 Pull up/down 상태로 인해 HIGH 대신 LOW에서 점등, LOW 대신 HIGH에서 소등됨 *
 * 이는 state의 변경에 따라 얼마든지 바뀔 수 있을 것으로 보이나 현재는 방법을 모르기 때문 *
 * 차후에 이러한 state의 변경을 이해하면 수정이 가능할 것으로 생각됨                      */

Blink::Blink(int pin){
  _pin = pin;
  pinMode(pin, OUTPUT);
}

void Blink::on(int time_ms){
  digitalWrite(_pin, LOW);
  Serial.println( "LED ON" );
  delay(time_ms);
}

void Blink::off(int time_ms){
  digitalWrite(_pin, HIGH);
  Serial.println( "LED OFF" );
  delay(time_ms);
}
