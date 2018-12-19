

#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN  14

DHT dht(DHTPIN, DHTTYPE, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();

}

long lastMsg = 0;

void loop() {
  // put your main code here, to run repeatedly:

  long now = millis();
  if (now - lastMsg > 30000) {
    lastMsg = now;
    
    float newTemp = dht.readTemperature();
    float newHum = dht.readHumidity();
  
    Serial.print("New temperature:");
    Serial.println(String(newTemp).c_str());
    
    Serial.print("New humidity:");
    Serial.println(String(newHum).c_str());
  }

  
}
