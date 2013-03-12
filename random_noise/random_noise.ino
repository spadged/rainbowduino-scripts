/*
	randomly sets pixel values every millisecond for the matrix
*/

#include <Rainbowduino.h>

void setup()
{
	Rb.init();
}

unsigned char x,y,z;

void loop()
{
	for(x=0;x<8;x++)
	{
		for(y=0;y<8;y++)
		{
			/*
				parameters in this function are:
				x position of the pixel;
				y position of the pixel;
				r amount of red in the pixel colour;
				g amount of green in the pixel colour;
				b amount of blue in the pixel colour;
			*/
			
			Rb.setPixelXY(random(8),random(8),random(0x10),random(0x10),random(0x10));
		}
	}
  
	delay(25);
	
	/*
		Uncomment this if you want to only show one pixel at a time
	*/
	
	//Rb.blankDisplay();
}