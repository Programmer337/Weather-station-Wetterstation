#pragma once
#include <ESPAsyncWebServer.h>

String processor(const String& var);
void onConfig(AsyncWebServerRequest *request);
void initServer();