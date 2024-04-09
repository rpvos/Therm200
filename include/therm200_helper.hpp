#if !defined(THERM200_HELPER_HPP_)
#define THERM200_HELPER_HPP_

#include <stdint.h>

class Therm200Helper
{
public:
    static float CalculateTemperature(const uint16_t &value, const float &operating_voltage = 5.0f, const int &adc_bits = 10);
};

#endif // THERM200_HELPER_HPP_
