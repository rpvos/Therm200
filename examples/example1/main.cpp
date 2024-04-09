#include <Arduino.h>
#include "therm200.hpp"
#include "therm200_helper.hpp"

// Red wire to 5v
// Black to ground
// White wire to pin set below
#ifdef CONFIG_IDF_TARGET_ESP32
#define temperatureSensorPin GPIO_NUM_36
#define bits 12
#else
#define temperatureSensorPin A0
#define bits 10
#endif

Therm200 therm200 = Therm200(temperatureSensorPin);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(temperatureSensorPin, INPUT);
}

void loop()
{

  // Calculation method from company
  // float temperatureInCelsius = voltage * 41.67 - 40;
  // float temperatureInFahrenheit = voltage * 75.006 - 40;

  uint16_t value = therm200.Measure();
  float temperature = Therm200Helper::CalculateTemperature(value, 5.0, bits);
  Serial.print("\t Temperature (C): ");
  Serial.println(temperature);
  delay(1000);
}
