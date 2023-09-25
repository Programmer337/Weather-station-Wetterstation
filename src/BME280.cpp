#include <BME280.h>

BlueDot_BME280 bme = BlueDot_BME280();

void initBME280(){
    bme.parameter.communication = 0;
    bme.parameter.I2CAddress = 0x77;
    bme.parameter.sensorMode = 0b11;
    bme.parameter.IIRfilter = 0b100;
    bme.parameter.humidOversampling = 0b101;
    bme.parameter.tempOversampling = 0b101;
    bme.parameter.pressOversampling = 0b101;
    bme.init();
}
void getSensorReadings(float *temp,float *hum, float *pressure){
    *temp = bme.readTempC();
    *hum = bme.readHumidity();
    *pressure = bme.readPressure();
}