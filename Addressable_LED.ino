#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    14

int strobo_1 = 30;
int strobo_2 = 80;
int strobo_3 = 50;
int strobo_4 = 100;

int freq_1 = 10;
int freq_2 = 30;
int freq_3 = 100;

int freq_pattern_1 = 40;


CRGB leds[NUM_LEDS];




void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}


void rosso() {
  
  for (int i = 0; i <= 3; i++) {
       
  leds[0]=CRGB (255,0,0);
  leds[1]=CRGB (255,0,0);
  leds[2]=CRGB (255,0,0);
  leds[3]=CRGB (255,0,0);
  leds[4]=CRGB (255,0,0);
  leds[5]=CRGB (255,0,0);
  leds[6]=CRGB (255,0,0);

  FastLED.show();
  delay(strobo_1);
  
  FastLED.clear ();
  delay(strobo_1);
  
  FastLED.show();
  delay(strobo_1);
  }
}





void blu()  {

for (int i = 0; i <= 3; i++) {
 

  leds[7]=CRGB (0,0,255);
  leds[8]=CRGB (0,0,255);
  leds[9]=CRGB (0,0,255);
  leds[10]=CRGB (0,0,255);
  leds[11]=CRGB (0,0,255);
  leds[12]=CRGB (0,0,255);
  leds[13]=CRGB (0,0,255);
  leds[14]=CRGB (0,0,255);

  FastLED.show();
  delay(strobo_1);
  
  FastLED.clear ();
  delay(strobo_1);
  
  FastLED.show();
  delay(strobo_1);
  
  }
}




void mix_rb()  {

for (int i = 0; i <= 3; i++) {
  leds[0]=CRGB (255,0,0);
  leds[1]=CRGB (255,0,0);
  leds[2]=CRGB (255,0,0);
  leds[3]=CRGB (255,0,0);


  FastLED.show();
  delay(strobo_1);
  FastLED.clear ();
  delay(strobo_1);

  FastLED.show();
  delay(strobo_1);
  FastLED.clear ();
  delay(strobo_1);

}

for (int i = 0; i <= 3; i++) {
  
  leds[19]=CRGB (0,0,255);
  leds[20]=CRGB (0,0,255);
  leds[21]=CRGB (0,0,255);
  leds[22]=CRGB (0,0,255);
  leds[23]=CRGB (0,0,255);
  leds[24]=CRGB (0,0,255);
  leds[25]=CRGB (0,0,255);
  leds[26]=CRGB (0,0,255);
  leds[27]=CRGB (0,0,255);
  leds[28]=CRGB (0,0,255);
  leds[29]=CRGB (0,0,255);

  
  
  FastLED.show();
  delay(strobo_1);
  FastLED.clear ();
  delay(strobo_1);

  FastLED.show();
  delay(strobo_1);
  FastLED.clear ();
  delay(strobo_1);
  
  }
 
}










//*********************************************************************

void rosso_static() {  
       
  leds[0]=CRGB (255,0,0);
  leds[1]=CRGB (255,0,0);
  leds[2]=CRGB (255,0,0);
  leds[3]=CRGB (255,0,0);
  leds[4]=CRGB (255,0,0);
  leds[5]=CRGB (255,0,0);
  leds[6]=CRGB (255,0,0);
  leds[7]=CRGB (255,0,0);
  leds[8]=CRGB (255,0,0);
  leds[9]=CRGB (255,0,0);

  FastLED.show();
  delay(strobo_3);
  
  FastLED.clear();
  delay(strobo_3);

}


void bianco_static()  {
 
  leds[10]=CRGB (255,255,255);
  leds[11]=CRGB (255,255,255);
  leds[12]=CRGB (255,255,255);
  leds[13]=CRGB (255,255,255);
  leds[14]=CRGB (255,255,255);
  leds[15]=CRGB (255,255,255);
  leds[16]=CRGB (255,255,255);
  leds[17]=CRGB (255,255,255);
  leds[18]=CRGB (255,255,255);

  FastLED.show();
  delay(strobo_3);
  
  FastLED.clear();
  delay(strobo_3);
    
}


void blu_static()  {

  leds[19]=CRGB (0,0,255);
  leds[20]=CRGB (0,0,255);
  leds[21]=CRGB (0,0,255);
  leds[22]=CRGB (0,0,255);
  leds[23]=CRGB (0,0,255);
  leds[24]=CRGB (0,0,255);
  leds[25]=CRGB (0,0,255);
  leds[26]=CRGB (0,0,255);
  leds[27]=CRGB (0,0,255);
  leds[28]=CRGB (0,0,255);
  leds[29]=CRGB (0,0,255);

  FastLED.show();
  delay(strobo_3);
  
  FastLED.clear();
  delay(strobo_3);
  
}











void loop() {




rosso();
delay (strobo_2);

blu();
delay(strobo_2);

rosso();
delay (strobo_2);

blu();
delay(strobo_2);





              


}
