# LoRa/TTN connected gas sensor
Realised by Alvaro PASCUAL & Quentin SCHIEX for the **Microcontroller and Open-Source Hardware project** at INSA Toulouse/_5ISS_
## Description
We have created a LoRa connected gas sensor during the TPs done at Microcontrollers and open source hardware. For this, we have used an Arduino UNO and a RN2483 LoRa chip, as well as a gas sensor designed with the help of the AIME. Then we designed an electronic circuit to connect each element together using KiCAD. Finally, we developed the software to be flashed to the arduino UNO. It get the sensor value and send it using LoRa.

## arduino_connected_gas_sensor
In this directory is the code we have developed to monitor the gas sensor and use the chip LoRa to send a message when the sensor detects gas. It is only needed to start the program when everything is connected and it will work propertly (you will only need to change the LoRa authent fields).

## DemoShield
In this directory is the PCB we designed using KiCAD. We have used an Arduino UNO template to design a shield that can easily be connected to an arduino UNO. It is composed of the gas sensor, the RN2483 LoRa breakout and an amplification stage. Once that the PCB is printed, you will have to solder components to it and plug the RN2483 breakout using the corresponding pins.

## How to use
To use this project, you will need to
- Get an Arduino UNO, the AIME gas sensor, an LTC1050 amp, an RN2483 breakout, some resistors and capacitors as presented at  the third part of Jean-Louis NOULLET website http://sourcecode.fr/insa/ISS/Smart_Device_Analog_Part.html
- Print the PCB
- Solder everything as shown in KiCad schematics and Part 3 of http://sourcecode.fr/insa/ISS/Smart_Device_Analog_Part.html
- Modify the .ino file LoRa authent values according to your LoRa app
- Flash the arduino with the .ino file
- Connect the shield and the arduino together
