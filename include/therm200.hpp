#if !defined(THERM200_HPP_)
#define THERM200_HPP_

#include <Arduino.h>

class Therm200
{
private:
    uint8_t adc_pin;

public:
    Therm200(uint8_t adc_pin);
    ~Therm200();

    uint16_t Measure();
};

#endif // THERM200_HPP_
