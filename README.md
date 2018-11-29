# PASCUAL_SCHIEX_gas_sensor
PASCUAL & SCHIEX has sensor project  _5 ISS_
## Description
We have created a gas sensor during the TPs done at Microcontrollers and open source hardware. For this, we have used an Arduino UNO and a chip LoRa, as well as a gas sensor designed by us and implemented with KiCAD.
## arduino_connected_gas_sensor
In this file is the code we have developed to monitor the gas sensor and use the chip LoRa to send a message when the sensor detects gas. It is only needed to start the program when everything is connected and it will work propertly.

## DemoShield
In this file we can found the KiCAD project we have done. We have used an Arduino UNO template to design inside the gas sensor developed. As it has the same dimensions as the Arduino UNO card, the gas sensor is already wired when inserted it in the Arduino card. To finish the setup we will need to wire the pins from the LoRa chip to the Arduino. This is done at followa:

```
Reception pin -> 10
Transmission pin -> 11
Reset pin -> 12
3.3V -> 3.3V
Ground -> Ground
```
