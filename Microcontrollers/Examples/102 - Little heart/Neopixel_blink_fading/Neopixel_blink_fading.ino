// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
// Check if the arduino is the AVR architect
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Set constant
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        13 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1// Popular NeoPixel ring size

#define LOOPNUM 3

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 20 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() 
{
  
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.

  for(int j=0; j<LOOPNUM; j++)
  {
    for(int i=0; i<255; i++) 
    {
  
      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
    
        pixels.setPixelColor(0, pixels.Color(i, 0, 0));
        pixels.show();
        delay(DELAYVAL); 

    }
    
  }

  // How to stop after blinking the color?
  while (1)
  {
    //pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.show();
  }
  
}
