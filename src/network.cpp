#include "network.h"
#include "configuration.h"
#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>

void initWiFi(){
  String ssid;
  String password;
  getWiFiConfig(&ssid, &password);
  WiFi.begin(ssid, password);
  for (byte i = 0; i < 40; i++){
    if (WiFi.status() == WL_CONNECTED){
      Serial.println(WiFi.localIP());
      return;
    }
    delay(500);
    Serial.print(".");
  }
  WiFi.disconnect();
  String deviceName = getDeviceName();
  WiFi.softAP(deviceName);
}

void initMDNS(){
  String deviceName = getDeviceName();
  if (!MDNS.begin(deviceName)){
    Serial.println("Error starting mDNS");
    return;
  }
}