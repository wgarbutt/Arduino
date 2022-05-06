#include <EasyButton.h>
#include <EasyButtonTouch.h>
#include <FastLED.h>
#include "Melody.h"
#include <LedControl.h>

#define NUM_LEDS    14
#define COLOR_ORDER RBG
#define DATA_PIN 7
#define RED_PIN 2
#define GREEN_PIN 3
#define WHITE_PIN 4
#define BLACK_PIN 5
#define YELLOW_PIN 6
#define BLUE_PIN 8


int ledState = 0;
int ledOn = false;
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int i = 0;

const int rPin = 10;  //red LED
const int gPin = 11;  //green LED
const int bPin = 12;  //blue LED
const int DIN_PIN = 34;
const int CS_PIN = 35;
const int CLK_PIN = 36;
const uint64_t Bounce[] = {
  0x0000000000000303,
  0x0000000000060600,
  0x000000000c0c0000,
  0x0000001818000000,
  0x0000303000000000,
  0x0060600000000000,
  0xc0c0000000000000,
  0x00c0c00000000000,
  0x0000c0c000000000,
  0x000000c0c0000000,
  0x00000000c0c00000,
  0x0000000000c0c000,
  0x000000000000c0c0,
  0x0000000000606000,
  0x0000000030300000,
  0x0000001818000000,
  0x00000c0c00000000,
  0x0006060000000000,
  0x0303000000000000,
  0x0003030000000000,
  0x0000030300000000,
  0x0000000303000000,
  0x0000000003030000,
  0x0000000000030300
};
const int IMAGES_LEN = sizeof(Bounce)/8;


LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

CRGB leds[NUM_LEDS];
EasyButton Red(RED_PIN);
EasyButton Green(GREEN_PIN);
EasyButton White(WHITE_PIN);   
EasyButton Black(BLACK_PIN);
EasyButton Yellow(YELLOW_PIN);
EasyButton Blue(BLUE_PIN);


void onRedPressed() {
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
}

void onGreenPressed() {
  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
}

void onWhitePressed() {
  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
}

void onBlackPressed() {
  FastLED.clear();
  FastLED.show();
}


void onYellowPressed() {
  fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  FastLED.show();
}


void onBluePressed() {
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
}


void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}


void onDoorbellPressed(){
   //read the input pin

   for (int thisNote=0; thisNote <8; thisNote++){
     // blink the three LEDs in sequence
     if (thisNote%3==0){    
       digitalWrite(rPin, HIGH);
       digitalWrite(gPin, LOW);
       digitalWrite(bPin, LOW);
     }
     else if (thisNote%3==1){    
       digitalWrite(rPin, LOW);
       digitalWrite(gPin, HIGH);
       digitalWrite(bPin, LOW);
     }
     else if (thisNote%3==2){    
       digitalWrite(rPin, LOW);
       digitalWrite(gPin, LOW);
       digitalWrite(bPin, HIGH);
     }
     //to calculate the note duration, take one second. Divided by the note type
     int noteDuration = 1000 / noteDurations [thisNote];
     tone(9, melody [thisNote], noteDuration);
     //to distinguish the notes, set a minimum time between them
     //the note's duration +30% seems to work well
     int pauseBetweenNotes = noteDuration * 1.30;
     delay(pauseBetweenNotes);
     //stop the tone playing
     noTone(9);
       digitalWrite(rPin, HIGH );
       digitalWrite(gPin, HIGH);
       digitalWrite(bPin, HIGH); 
   }
 }

void setup() {
  Serial.begin(115200);
  Red.begin();
  Green.begin();
  White.begin();
  Black.begin();
  Yellow.begin();
  Blue.begin();

  
  Red.onPressed(onRedPressed);
  Green.onPressed(onGreenPressed);
  White.onPressed(onWhitePressed);
  Black.onPressed(onBlackPressed);
  Yellow.onPressed(onYellowPressed);
  Blue.onPressed(onBluePressed);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
}

void loop() {
    displayImage(Bounce[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(100);
  Red.read();
  Green.read();
  White.read();
  Black.read();
  Yellow.read();
  Blue.read();

}
