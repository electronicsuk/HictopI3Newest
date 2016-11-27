 
#include "Max31850.h"

void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) MYSERIAL.print("0");
    MYSERIAL.print(deviceAddress[i], HEX);
  }
}
 void SetupMax31850(){
  sensors.begin();
  MYSERIAL.print("Found ");
  MYSERIAL.print(sensors.getDeviceCount(), DEC);
  MYSERIAL.println(" devices.");

  // report parasite power requirements
  MYSERIAL.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) MYSERIAL.println("ON");
  else MYSERIAL.println("OFF");
  
  // assign address manually.  the addresses below will beed to be changed
  // to valid device addresses on your bus.  device address can be retrieved
  // by using either oneWire.search(deviceAddress) or individually via
  // sensors.getAddress(deviceAddress, index)
  //hotend0Thermometer = { 0x28, 0x1D, 0x39, 0x31, 0x2, 0x0, 0x0, 0xF0 };

  // Method 1:
  // search for devices on the bus and assign based on an index.  ideally,
  // you would do this to initially discover addresses on the bus and then 
  // use those addresses and manually assign them (see above) once you know 
  // the devices on your bus (and assuming they don't change).
  if (!sensors.getAddress(hotend0Thermometer, 0)) MYSERIAL.println("Unable to find address for Device 0"); 
  
  // method 2: search()
  // search() looks for the next device. Returns 1 if a new address has been
  // returned. A zero might mean that the bus is shorted, there are no devices, 
  // or you have already retrieved all of them.  It might be a good idea to 
  // check the CRC to make sure you didn't get garbage.  The order is 
  // deterministic. You will always get the same devices in the same order
  //
  // Must be called before search()
  //oneWire.reset_search();
  // assigns the first address found to hotend0Thermometer
  //if (!oneWire.search(hotend0Thermometer)) Serial.println("Unable to find address for hotend0Thermometer");

  // show the addresses we found on the bus
  MYSERIAL.print("Device 0 Address: ");
  printAddress(hotend0Thermometer);
  MYSERIAL.println();

  // set the resolution to 9 bit (Each Dallas/Maxim device is capable of several different resolutions)
  sensors.setResolution(hotend0Thermometer, 9);
 
  MYSERIAL.print("Device 0 Resolution: ");
  MYSERIAL.print(sensors.getResolution(hotend0Thermometer), DEC); 
  MYSERIAL.println();
  sensors.requestTemperatures();
MYSERIAL.println("Current Temp");
  MYSERIAL.print(GetTemperature());
  
}


float GetTemperature()
{
  return sensors.getTempC(hotend0Thermometer);  
}


