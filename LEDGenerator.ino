
#include <TimerOne.h>
#include <SPI.h>
#include "Neophob_LPD6803.h"

/*
Unlike software SPI which is configurable, hardware SPI works only on very specific pins. 

On the Arduino Uno, Duemilanove, etc., clock = pin 13 and data = pin 11. 
For the Arduino Mega, clock = pin 52, data = pin 51. 
For the ATmega32u4 Breakout Board and Teensy, clock = pin B1, data = B2. 

Alternately, on most boards you can use the 6-pin programming 
header for SPI output as well, in which case clock = pin 3 and data = pin 4.

src: http://forums.adafruit.com/viewtopic.php?f=47&t=24256 
thanks phil!
*/

#define LED_MODULES 13

const int pin5 = 5;
const int pin6 = 6;
const int pin7 = 7;

Neophob_LPD6803 strip = Neophob_LPD6803(LED_MODULES);

void setup() {
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, INPUT);
  
  //Serial.begin(9600);
  
  //just play with those values!
  strip.setCPUmax(50);
  strip.begin(SPI_CLOCK_DIV16);
  strip.show();
}

int getMode(int d5, int d6, int d7) {
  int rtn = 0;
  
  //000
  if (d7 == 0 && d6 == 0 && d5 == 0) {
    rtn = 0;
  }
  
  //001
  if (d7 == 0 && d6 == 0 && d5 == 1) {
    rtn = 1;
  }
  
  //010
  if (d7 == 0 && d6 == 1 && d5 == 0) {
    rtn = 2;
  }
  
  //011
  if (d7 == 0 && d6 == 1 && d5 == 1) {
    rtn = 3;
  }
  
  //100
  if (d7 == 1 && d6 == 0 && d5 == 0) {
    rtn = 4;
  }
  
  //101
  if (d7 == 1 && d6 ==0 && d5 == 1) {
    rtn = 5;
  }
  
  //110
  if (d7 == 1 && d6 == 1 && d5 == 0) {
    rtn = 6;
  }
  
  //111
  if (d7 == 1 && d6 == 1 && d5 == 1) {
    rtn = 7;
  }
  
  return rtn;
}

void loop() {
  
  int d5 = digitalRead(pin5);
  int d6 = digitalRead(pin6);
  int d7 = digitalRead(pin7);
  
  //Serial.println(d5);  
  int mode = getMode(d5, d6, d7);
  
  switch (mode)
  {
    case 0:
      solidBlue();
      break;
    case 1:
      solidRed();
      break;
    case 2:
      colorChase_BF_Blue();
      break;
    case 3:
      colorChase_BF_Red();
      break;
    case 4:
      rainbowCycle(5);
      break;
    case 5:
      sevenColorComet();
      break;
    case 6:
      patrioticSweep();
      break;
    case 7:
      off();
      break;
    default:
      off();
      break;
  }
  
  /*
 int x;
 // colorWipe(Color(31, 0, 0), 30);
for(x=0; x <= 10; x++)
  colorWipe3(Color(0, 31, 0), 30);
  
for(x=0; x <= 10; x++)
  colorWipe3(Color(0, 0, 31), 30);  
 // colorWipe(Color(0, 0, 31), 10);
//  colorWipe3(Color(0,0,0),30);
for(x=0; x < 3; x++)
  rainbowCycle(30);
  // colorWipeInv(Color(0, 31, 0), 15);
 // colorWipe(Color(0, 0, 31), 10);
  //colorWipeInv(Color(0,0,0),20);
for(x=0; x < 3; x++)  
  rainbow(5);*/
  
  
}

void off() {
  colorWipe(Color(0, 0, 0), 10);
}

void patrioticSweep()
{
  colorWipe(Color(0, 0, 31), 30);
  colorWipe(Color(31, 31, 31), 30);
  colorWipe(Color(0, 31, 0), 30);
}

void sevenColorComet()
{
  int a;
  int i;
  int j;
  uint32_t c1;
  uint32_t c2;
  uint32_t c3;
  uint32_t c4;
  uint32_t c5;
  int numOfColors = 7;
  
  for (a = 0; a < numOfColors; a++) {
    //if (a == numOfColors)
      //a = 0;
      
    if (a == 0)
    {
      c1 = Color(31,0,0);
      c2 = Color(25,0,0);
      c3 = Color(18,0,0);
      c4 = Color(10,0,0);
      c5 = Color(31,0,0);
    }
    if (a == 1)
    {
      c1 = Color(31,31,0);
      c2 = Color(25,25,0);
      c3 = Color(18,18,0);
      c4 = Color(10,10,0);
      c5 = Color(1,1,0);
    }
    if (a == 2)
    {
      c1 = Color(0,31,0);
      c2 = Color(0,25,0);
      c3 = Color(0,18,0);
      c4 = Color(0,10,0);
      c5 = Color(0,1,0);
    }
    if (a == 3)
    {
      c1 = Color(0,31,31);
      c2 = Color(0,25,25);
      c3 = Color(0,18,18);
      c4 = Color(0,10,10);
      c5 = Color(0,1,1);
    }
    if (a == 4)
    {
      c1 = Color(0,0,31);
      c2 = Color(0,0,25);
      c3 = Color(0,0,18);
      c4 = Color(0,0,10);
      c5 = Color(0,0,1);
    }
    if (a == 5)
    {
      c1 = Color(31,0,31);
      c2 = Color(25,0,25);
      c3 = Color(18,0,18);
      c4 = Color(10,0,10);
      c5 = Color(1,0,1);
    }
    if (a == 6)
    {
      c1 = Color(31,31,31);
      c2 = Color(25,25,25);
      c3 = Color(18,18,18);
      c4 = Color(10,10,10);
      c5 = Color(1,1,1);
    }
    
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c1);
      strip.setPixelColor(i-1, c2);
      strip.setPixelColor(i-2, c3);
      strip.setPixelColor(i-3, c4);
      strip.setPixelColor(i-4, c5);
      
      for (j=0; j < strip.numPixels(); j++) {
        if (j > i || j < i-4)
        {
          strip.setPixelColor(j, 0);
        }
      }
      
      strip.show();
      delay(40);
    }
    
  }
} 

void solidRed() {
  colorWipe(Color(0, 0, 31), 30);
}

void solidBlue() {
  colorWipe(Color(0, 31, 0), 30);  
}

void colorChase_BF_Blue() {
  colorWipeInv(Color(0, 31, 0), 30); 
  colorWipe(Color(0, 0, 0), 30); 
}

void colorChase_BF_Red() {
  colorWipeInv(Color(0, 0, 31), 30); 
  colorWipe(Color(0, 0, 0), 30); 
}


// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 96 * 5; j++) {     // 5 cycles of all 96 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 96 / strip.numPixels()) + j) % 96) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}


// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

//even # of modules now, not sure if this will work as planned
void colorChase_BackAndForthPaint(uint32_t c, uint8_t wait) {
   int i;
  
  for (i=0; i <= strip.numPixels()/2; i++) {
      strip.setPixelColor(i, c);
      strip.setPixelColor(strip.numPixels() -i, c);
      strip.show();
      delay(wait);
  }
}

//even # of modules now, not sure if this will work as planned
void colorChase_BackAndForthClear(uint32_t c, uint8_t wait) {
   int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.setPixelColor(i - 1, 0);
      strip.setPixelColor(strip.numPixels() -i, c);
      strip.setPixelColor(strip.numPixels() - i + 1, 0);
      strip.show();
      delay(wait);
  }
}

void colorWipeInv(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=strip.numPixels(); i>= 0; i--) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}


void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 96 * 3; j++) {     // 3 cycles of all 96 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 96));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// Create a 15 bit color value from R,G,B
unsigned int Color(byte r, byte g, byte b)
{
  //Take the lowest 5 bits of each value and append them end to end
  return( ((unsigned int)g & 0x1F )<<10 | ((unsigned int)b & 0x1F)<<5 | (unsigned int)r & 0x1F);
}


//Input a value 0 to 127 to get a color value.
//The colours are a transition r - g -b - back to r
unsigned int Wheel(byte WheelPos)
{
  byte r,g,b;
  switch(WheelPos >> 5)
  {
    case 0:
      r=31- WheelPos % 32;   //Red down
      g=WheelPos % 32;      // Green up
      b=0;                  //blue off
      break; 
    case 1:
      g=31- WheelPos % 32;  //green down
      b=WheelPos % 32;      //blue up
      r=0;                  //red off
      break; 
    case 2:
      b=31- WheelPos % 32;  //blue down 
      r=WheelPos % 32;      //red up
      g=0;                  //green off
      break; 
  }
  return(Color(r,g,b));
}

