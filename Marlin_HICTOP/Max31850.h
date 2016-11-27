#ifndef MARLIN_Max31850_H 
#define MARLIN_Max31850_H
 #include <OneWire.h>
 #include <DallasTemperature.h>
	
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 11

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
static OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
static DallasTemperature sensors(&oneWire);

// arrays to hold device address
static DeviceAddress hotend0Thermometer;

#include "Marlin.h"

void printAddress(DeviceAddress deviceAddress);

void SetupMax31850();
float GetTemperature();

#endif // MARLIN_Max31850_H
