#pragma once
#include <Arduino.h>

void getWiFiConfig(String* ssid, String* password);
void setWiFiSsid(String ssid);
void setWiFiPassword(String password);
void setLanguage(String lang);
String getLanguage();
String getDeviceName();
void setDeviceName(String deviceName);