#if !defined(THERM200_HELPER_HPP_)
#define THERM200_HELPER_HPP_

#include <stdint.h>

class Therm200Helper
{
public:
    static constexpr float CalculateTemperature(uint16_t value, float operating_voltage = 5.0f, int adc_bits = 10);
};

#endif // THERM200_HELPER_HPP_
