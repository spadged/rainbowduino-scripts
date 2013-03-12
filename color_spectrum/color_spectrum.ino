/*
	code by Marc Palmer: http://www.anyware.co.uk/
	
	taken from this article: http://www.anyware.co.uk/2005/2012/01/17/getting-started-with-arduino-rainbowduino/
	
	gist: https://gist.github.com/marcpalmer/1626042
*/

#include <Rainbowduino.h>

byte display[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

char vel[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char RED[64] = {
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,238,221,204,188,171,154,137,119,102,85,
	68,51,34,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,35,52
};

unsigned char GREEN[64] = {
	0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,238,221,204,188,170,154,136,120,102,86,68,52,34,18,0,0,0,0
};

unsigned char BLUE[64] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,34,52,68,86,102,120,136,154,170,188,
	204,221,238,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
};

void setup()
{
	Rb.init();

	for (unsigned char c = 0; c < 64; c++)
	{
		display[c] = (c % 8) + (c / 8) & B01111111;
		vel[c] = 1;
	}
}

void loop()
{
	for (unsigned char x = 0; x < 8; x++)
	{
		for (unsigned char y = 0; y < 8; y++)
		{
			unsigned char ofs = (y << 3) + x;
			
			unsigned char hue = display[ofs];
			
			uint32_t colour = ((uint32_t)RED[hue] << 16) | ((uint32_t)GREEN[hue] << 8) | BLUE[hue];
			
			Rb.setPixelXY(x, y, colour);
			
			hue = hue+vel[ofs];
			
			if (hue < 0 || hue > 63)
			{
				vel[ofs] = -vel[ofs];
				hue += vel[ofs];
			}
			display[ofs] = hue;
		}
	}
	
	delay(25);
}