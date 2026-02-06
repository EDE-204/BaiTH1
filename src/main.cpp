#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4   
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 Test");

  dht.begin();
}

void loop() {
  delay(2000); 

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); 

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Khong doc duoc du lieu tu DHT11!");
    return;
  }

  Serial.print("Do am: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
