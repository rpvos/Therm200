#include <Arduino.h>
#include <therm200.hpp>

// Red wire to 5v
// Black to ground
// White wire to pin set below
#define temperatureSensorPin A0

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

  Serial.print("\t Temperature (C): ");
  Serial.println(therm200.Measure());
  delay(1000);
}
