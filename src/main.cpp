//2.OTA
//3.Data saving
//4.Updating data on webpage (server sent events)b

#include <Arduino.h>
#include "BME280.h"
#include "server.h"
#include "network.h"

void setup(){
  Serial.begin(115200);
  initBME280();
  initWiFi();
  initServer();
  initMDNS();
  Serial.println("Setup done");
}

void loop(){
}