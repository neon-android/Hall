/*
 * Cuadros_5_hall_V1.1
 * Utiliza la shield diseñada para arduino Proyactil MX 2021
 * 
 * Misael Reyes 
 * 17/08/2021
 * 
 */
#include <Adafruit_NeoPixel.h>
#define RELE      A0
#define HALL1     A1//A0
#define HALL2     A2//A1
#define HALL3     A3//A2 
#define HALL4     A4//A3
//#define HALL5     A3//A3
#define PIN       5 
#define NUMPIXELS 4
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensors = 0;
boolean hall_state = LOW;
void setup() {
  pinMode(RELE, OUTPUT);
  pinMode(HALL1, INPUT_PULLUP);
  pinMode(HALL2, INPUT_PULLUP);
  pinMode(HALL3, INPUT_PULLUP);
  pinMode(HALL4, INPUT_PULLUP);
  //pinMode(HALL5, INPUT);
  pixels.begin();
   for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));


    pixels.show();
    delay(250); 
    

             }
    pixels.clear();
    pixels.show();
}

void loop() {
  
  if(digitalRead(HALL1) == hall_state) {
    bitSet(sensors, 0);    // Pone la el bit 0 de la variable sensors en 1
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.show();
  }
  else 
  {
    bitClear(sensors, 0);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
  } 
    if(digitalRead(HALL2) == hall_state) {
    bitSet(sensors, 1);    // Pone la el bit 0 de la variable sensors en 1
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.show();
  }
  else 
  {
    bitClear(sensors, 1);
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.show();
  }   
    if(digitalRead(HALL3) == hall_state) {
    bitSet(sensors, 2);    // Pone la el bit 0 de la variable sensors en 1
    pixels.setPixelColor(2, pixels.Color(0, 150, 0));
    pixels.show();
  }
  else 
  {
    bitClear(sensors, 2);
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.show();
  } 
    if(digitalRead(HALL4) == hall_state) {
    bitSet(sensors, 3);    // Pone la el bit 0 de la variable sensors en 1
    pixels.setPixelColor(3, pixels.Color(0, 150, 0));
    pixels.show();
  }
  else 
  {
    bitClear(sensors, 3);
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.show();
  }                                      
  
  
  if(sensors == 15) digitalWrite(RELE, HIGH);           // Si los bits 0 a 4 de la variable sensors son 1...
  else digitalWrite(RELE, LOW);                         // Si uno solo bit es 0...

  
}
