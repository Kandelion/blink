#include "temp.h"

SoftwareSerial esp8266(2,3); // TX/RX 설정, esp8266 객체생성

TEMP::TEMP(){
  esp8266.begin(115200);
}

String TEMP::getMsg(String temp){
  String result = "GET https://api.thingspeak.com/update?api_key=";
  result += apikey;
  result +="&field1=";
  result += temp;
  result += "\r\n\r\n";

  return result;
}

void TEMP::Connect(){
  const int httpPort = 80;
  if (!client.connect("api.thingspeak.com", httpPort)) {
    Serial.println("connection failed");
    return;
  }
  Serial.println("connection successed");
}

void TEMP::Send(String temp){
  String getStr = getMsg(temp);
  
  client.print(getStr);

  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println(getStr);
}

