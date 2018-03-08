#include "Blink.h"

/* 내장된 LED가 Pull Up 상태로 HIGH 대신 LOW에서 점등, LOW 대신 HIGH에서 소등됨 */

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
