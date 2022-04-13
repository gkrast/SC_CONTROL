/*
    Name:       SC_CONTROL.ino
    Created:	4/9/2022 7:25:10 AM
    Author:     GK
	This code demonstrates the IO and AD extender for nodeMCU with ESP8260 Wi-Fi module
	----------------------------------------------------------------------------------------------------------
	Circuit description:
	----------------------------------------------------------------------------------------------------------
	Each of the 8 IO pins of the IO extender (MCP23S08) drives one LED with 3.3V
	The LEDs are run continuously, one at time and in each direction (left and right) with adjustable speed 
	One POT with its center tap connected to channel 3 of the ADC (MCP3004) is used to adjust the speed of the running LEDs
	The POT's center tap voltage can be varied from 0 to 3.3V which controls the speed of the LEDs from the maximum and the minimum level

*/

#include <SPI.h>
#include "app.h"

//Local variables
uint8_t ioPins = 1;
uint8_t dir = 1;
uint8_t wait = 10;
uint8_t inc = 1;
SPISettings mySettings;
float ADC;

/////////////////////////////////////////////////////////////////////
//                  APPLICATION INITIALIZATION                     //
/////////////////////////////////////////////////////////////////////
void setup()
{
	// Open serial port connection
	Serial.begin(9600);
	cout << "Initilizing..." << endl << endl;

	// Setup the SPI shared by IO and ADC
	SPI.begin();
	mySettings._clock = 50000;
	mySettings._bitOrder = MSBFIRST;
	mySettings._dataMode = SPI_MODE0;
	SPI.beginTransaction(mySettings);

	// Setup IO chip
	MCP23S08.begin(&SPI);
	for (int k = 0; k < 8; k++) {
		MCP23S08.ioMode(k, OUTPUT);
		MCP23S08.ioPullUp(k, RESET);
	}
	
	// Setup the ADC chip
	MCP3004.begin(&SPI);

	cout << "Running..." << endl << endl;

}

void loop()
{
	ADC = MCP3004.readADC(3);
	cout << "ADC: " << ADC << endl;
	wait = (uint8_t)(100 * (ADC / 3.3));
		
	MCP23S08.write(ioPins);
	if (dir) {
		ioPins = ioPins << 1;
		if (ioPins == 0) {
			ioPins = 0b10000000;
			dir = 0;
		}
	}
	else {
		ioPins = ioPins >> 1;
		if (ioPins == 0) {
			ioPins = 1;
			dir = 1;
		}		
	}
	delay(wait);
}
