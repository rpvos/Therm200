#include "therm200_helper.hpp"

static const int kOperationalTemperatureLowest = -40;
static const int kOperationalTemperatureHighest = 85;
static const int kOperationalVoltageHighest = 3;
static const int kOperationalVoltageLowest = 0;

constexpr int get_adc_range(int adc_bits)
{
    return (1 << adc_bits) - 1;
}

constexpr float GetTemperaturePerVoltage()
{
    return (float)(kOperationalTemperatureHighest - kOperationalTemperatureLowest) / (kOperationalVoltageHighest - kOperationalVoltageLowest);
}

float Therm200Helper::CalculateTemperature(uint16_t value, float operating_voltage, int adc_bits)
{
    // Calculate the voltage of the pin
    float voltage = value * operating_voltage / get_adc_range(adc_bits);

    // Calculate the temperature based on the calculated voltage
    float temperature_in_celsius = (voltage * GetTemperaturePerVoltage()) + kOperationalTemperatureLowest;

    return temperature_in_celsius;
}