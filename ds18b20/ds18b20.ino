#include "temp.h"
 
#define ONE_WIRE_BUS D4
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
 
const char* ssid = "WIN1Q";
const char* pass = "dkaghrkanjfRk!";
 
char temperatureString[6];
TEMP temperature_;
 
void setup(void){
  Serial.begin(115200);
  Serial.println("");
  
  WiFi.begin(ssid, pass);
 
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
  DS18B20.begin();
}
 
float getTemperature() {
  float temp;
  do {
    DS18B20.requestTemperatures(); 
    temp = DS18B20.getTempCByIndex(0);
    delay(100);
  } while (temp == 85.0 || temp == (-127.0));
  return temp;
}
 
 
void loop() {
  float temperature = getTemperature();
 
  dtostrf(temperature, 2, 2, temperatureString);
  // send temperature to the serial console
  Serial.println(temperatureString);

  temperature_.Connect();
  temperature_.Send(temperatureString);

  delay(5000);
}

