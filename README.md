# SC_CONTROL
 This code is the IO Expansion demo for NodeMCU, ESP-12E with ESP8266 Wi-Fi module with baseboard EBS-D1 by Senzotic.
 The application uses test circuit with 8 LEDs and one POT. The test circuit is easy to build onto the prototype board PRT-C0.
 The software libraries for the two circuits on EBS-D1 are implemented as two classes - MCP23S08 for the IO chip and MCP3004 for the ADC chip.
 The classes are not written to include all possible features of the two integrated circuits. 
 The purpose of the code is only to serve as the bases for new application development where the required level of implementation can be achieved.
 
 This is how the demo application should work if you run it on EBS-D1 with the LEDs circuit prototyped on PRT-C0:
 
 Each of the 8 IO pins of the IO expander (MCP23S08) drives one LED with 3.3V from the NodeMCU module.
 The LEDs are run continuously, one at time and in each direction (left and right) with adjustable speed. 
 One POT with its center tap connected to channel 3 of the ADC (MCP3004) is used to adjust the speed of the bouncing LEDs. 
 The POT's center tap voltage can be varied from 0 to 3.3V which controls the speed of the LEDs from the maximum to the minimum level.

 We hope you will enjoy the demo and find it useful for your NodeMCU application.
 Happy coding!
