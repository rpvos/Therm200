#include "therm200.hpp"

const int kOperationalTemperatureLowest = -40;
const int kOperationalTemperatureHighest = 85;
const int kOperationalVoltageHighest = 3;
const int kOperationalVoltageLowest = 0;

constexpr int get_adc_range(int adc_bits)
{
    return (1 << adc_bits) - 1;
}

constexpr float GetTemperaturePerVoltage()
{
    return (kOperationalTemperatureHighest - kOperationalTemperatureLowest) / (kOperationalVoltageHighest - kOperationalVoltageLowest);
}

Therm200::Therm200(uint8_t adc_pin, float operating_voltage, int adc_bits)
{
    this->adc_bits = adc_bits;
    this->adc_pin = adc_pin;
    this->operating_voltage = operating_voltage;
}

Therm200::~Therm200()
{
}

float Therm200::Measure()
{
    // Read the analog pin
    int value = analogRead(this->adc_pin);

    // Calculate the voltage of the pin
    float voltage = value * operating_voltage / get_adc_range(this->adc_bits);

    // Calculate the temperature based on the calculated voltage
    float temperatureInCelsius = (voltage * GetTemperaturePerVoltage()) + kOperationalTemperatureLowest;

    return temperatureInCelsius;
}
