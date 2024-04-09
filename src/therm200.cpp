#include "therm200.hpp"

Therm200::Therm200(uint8_t adc_pin)
{
    this->adc_pin = adc_pin;
}

Therm200::~Therm200()
{
}

uint16_t Therm200::Measure()
{
    // Read the analog pin
    return analogRead(this->adc_pin);
}
