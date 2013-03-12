#include <Rainbowduino.h>

void setup()
{
	Rb.init();
}

unsigned char x,y,z=10;

void loop()
{
	/*
		draw I
	*/
	Rb.drawVerticalLine(1, 2, 4, 0x78ff00);
	Rb.drawVerticalLine(2, 3, 2, 0x78ff00);
	Rb.drawVerticalLine(3, 3, 2, 0x78ff00);
	Rb.drawVerticalLine(4, 3, 2, 0x78ff00);
	Rb.drawVerticalLine(5, 3, 2, 0x78ff00);
	Rb.drawVerticalLine(6, 2, 4, 0x78ff00);

	delay(1000);
	Rb.blankDisplay();
	
	/*
		draw a heart
	*/
	Rb.drawHorizontalLine(2, 1, 3, 0xFF0000);
	delay(100);
	Rb.drawHorizontalLine(1, 2, 5, 0xFF0000);
	delay(100);
	Rb.drawHorizontalLine(2, 3, 5, 0xFF0000);
	delay(100);
	Rb.drawHorizontalLine(2, 4, 5, 0xFF0000);
	delay(100);
	Rb.drawHorizontalLine(1, 5, 5, 0xFF0000);
	delay(100);
	Rb.drawHorizontalLine(2, 6, 3, 0xFF0000);
	delay(1000);
	Rb.blankDisplay();
	
	/*
		draw U
	*/
	Rb.drawHorizontalLine(1, 1, 6, 0x666666);
	Rb.drawHorizontalLine(1, 2, 6, 0x666666);
	Rb.drawHorizontalLine(5, 3, 2, 0x666666);
	Rb.drawHorizontalLine(5, 4, 2, 0x666666);
	Rb.drawHorizontalLine(1, 5, 6, 0x666666);
	Rb.drawHorizontalLine(1, 6, 6, 0x666666);
	delay(3000);
	Rb.blankDisplay();
}
