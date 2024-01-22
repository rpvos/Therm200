#if !defined(THERM200_HPP_)
#define THERM200_HPP_

#include <Arduino.h>

class Therm200
{
private:
    float voltsPerUnit;
    float temperaturePerVoltage;

    uint8_t adc_pin;

public:
    Therm200(uint8_t adc_pin, float operating_voltage = 5.0f, int adc_bits = 10);
    ~Therm200();

    float Measure();
};

#endif // THERM200_HPP_
