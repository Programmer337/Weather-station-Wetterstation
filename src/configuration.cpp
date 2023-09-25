#include "configuration.h"
#include <Preferences.h>

Preferences prefs;

void getWiFiConfig(String* ssid, String* password){
    prefs.begin("WiFiConfig", true);
    *ssid = prefs.getString("ssid",String());
    *password = prefs.getString("password",String());
    prefs.end();
}

void setWiFiSsid(String ssid){
    prefs.begin("WiFiConfig", false);
    prefs.putString("ssid", ssid);
    prefs.end();
}
void setWiFiPassword(String password){
    prefs.begin("WiFiConfig", false);
    prefs.putString("password", password);
    prefs.end();
}

void setLanguage(String lang){
    prefs.begin("general", false);
    prefs.putString("lang", lang);
    prefs.end();
}
String getLanguage(){
    prefs.begin("general", true);
    String lang = prefs.getString("lang", "en");
    prefs.end();
    if(lang != NULL)
        return lang;
    else
        return "en";
}

String getDeviceName(){
    prefs.begin("general", true);
    String deviceName = prefs.getString("device-name", "Weather station");
    prefs.end();
    if (deviceName != NULL)
        return deviceName;
    else
        return "Weather station";
}

void setDeviceName(String deviceName){
    prefs.begin("general", false);
    prefs.putString("device-name", deviceName);
    prefs.end();
}