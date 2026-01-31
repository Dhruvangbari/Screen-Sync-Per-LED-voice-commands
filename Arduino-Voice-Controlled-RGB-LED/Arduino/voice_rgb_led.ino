#include <FastLED.h>

#define LED_PIN 6
#define NUM_LEDS 34
#define BRIGHTNESS 200

CRGB leds[NUM_LEDS];
String command = "";

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "E0") off();
    else if (command == "E1") solid(CRGB::Red);
    else if (command == "E2") solid(CRGB::Green);
    else if (command == "E3") solid(CRGB::Blue);
    else if (command == "E4") rainbow();
    else if (command == "E5") pulse();
    else if (command == "E6") party();
  }
}

void off(){ FastLED.clear(); FastLED.show(); }

void solid(CRGB c){ fill_solid(leds, NUM_LEDS, c); FastLED.show(); }

void rainbow(){
  static uint8_t h=0;
  for(int i=0;i<NUM_LEDS;i++) leds[i]=CHSV(h+i*5,255,255);
  h++; FastLED.show(); delay(30);
}

void pulse(){
  for(int b=0;b<255;b+=5){
    fill_solid(leds,NUM_LEDS,CHSV(160,255,b));
    FastLED.show(); delay(10);
  }
}

void party(){
  for(int i=0;i<NUM_LEDS;i++) leds[i]=CHSV(random(255),255,255);
  FastLED.show(); delay(120);
}
