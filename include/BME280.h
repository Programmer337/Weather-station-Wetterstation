#pragma once

#include <BlueDot_BME280.h>


void initBME280();
void getSensorReadings(float *temp,float *hum, float *pressure);