#include "therm200.hpp"

const int kOperationalTemperatureLowest = -40;
const int kOperationalTemperatureHighest = 85;
const int kOperationalVoltageHighest = 3;
const int kOperationalVoltageLowest = 0;

Therm200::Therm200(uint8_t adc_pin, float operating_voltage, int adc_bits)
{
    this->adc_pin = adc_pin;

    int adcRange = (1 << adc_bits) - 1;          // Calculate max value
    voltsPerUnit = operating_voltage / adcRange; // Calculate the amount of volt 1 unit is

    float temperatureRange = kOperationalTemperatureHighest - kOperationalTemperatureLowest;
    float voltageRange = kOperationalVoltageHighest - kOperationalVoltageLowest;

    temperaturePerVoltage = temperatureRange / voltageRange;
}

Therm200::~Therm200()
{
}

float Therm200::Measure()
{
    // Read the analog pin
    int value = analogRead(this->adc_pin);

    // Calculate the voltage of the pin
    float voltage = value * voltsPerUnit;
    // Calculate the temperature based on the calculated voltage
    float temperatureInCelsius = (voltage * temperaturePerVoltage) + kOperationalTemperatureLowest;

    return temperatureInCelsius;
}
