#include "temp.h"

//#define THINGSPEAK

SoftwareSerial esp8266(2,3); // TX/RX 설정, esp8266 객체생성

TEMP::TEMP(){
  esp8266.begin(115200);
}

String TEMP::getMsg(String temp){
  #ifdef THINGSPEAK
  String result = "GET https://api.thingspeak.com/update?api_key=";
  result += apikey;
  result +="&field1=";
  result += temp;
  result += "\r\n\r\n";

  return result;
  #endif
  
  #ifndef THINGSPEAK
  String result = "GET https://maker.ifttt.com/trigger/temp_get/with/key/fiYwPb9N1uC9fFHfFXAOtx0tSQLuA8vtbGKFUvGQYfl?value1=" + temp + "\r\n\r\n";
  
  return result;
  #endif
}

void TEMP::Connect(){
  const int httpPort = 80;
  #ifndef THINGSPEAK
  if (!client.connect("maker.ifttt.com", httpPort)) {
  #endif
  #ifdef THINGSPEAK
  if (!client.connect("api.thingspeak.com", httpPort)) {
  #endif
    Serial.println("connection failed");
    return;
  }
  Serial.println("connection successed");
}

void TEMP::Send(String temp){
  String getStr = getMsg(temp);
  //String data = "{\"value1\" : \"" + temp + "\" }";
  
  client.print(getStr);

  int timeout = millis() + 3000;
  while (client.available() == 0) {
    if (timeout < millis()) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println(getStr);
}

