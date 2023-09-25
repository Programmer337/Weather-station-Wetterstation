#include "SPIFFS.h"
#include <BME280.h>
#include "server.h"
#include "configuration.h"

AsyncWebServer server(80);
String lang;

String processor(const String& var){
  float temp = 0;
  float hum = 0;
  float pressure = 0;
  getSensorReadings(&temp,&hum,&pressure);
  if (var == "TEMP"){
    return String(temp);
  }
  if (var=="HUM"){
    return String(hum);
  }
  if (var == "PRESSURE"){
    return String(pressure);
  }
  return String();
}

void onConfig(AsyncWebServerRequest *request){
  request->send(SPIFFS, "/"+lang+"/config.html", String());
  byte paramsNr = request->params();
  if (paramsNr <= 0)
    return;
  
  for(byte i=0;i<paramsNr;i++){
    AsyncWebParameter* p = request->getParam(i);
    if(p->name() == "ssid")
      setWiFiSsid(p->value());
    if(p->name() == "password")
      setWiFiPassword(p->value());
    if(p->name() == "lang")
      setLanguage(p->value());
    if(p->name() == "device-name")
      setDeviceName(p->value());
  }
  ESP.restart();
}

void initServer(){
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  lang = getLanguage();

  server.on("/",HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/"+lang+"/index.html", String(), false, processor);
  });
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });
  server.on("/config.html", HTTP_GET, onConfig);
  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404,"text/plain", "Nicht gefunden");
  });
  server.begin();
}