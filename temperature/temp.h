#ifndef __TEMP__
#define __TEMP__

#include "Arduino.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <DallasTemperature.h>


class TEMP{
private:
  String apikey = "LP0XBCXZNI8NJ3OW";
  String getMsg(String temp);
  WiFiClient client;

public:
  TEMP();
  void Connect();
  void Send(String temp);
};

#endif
