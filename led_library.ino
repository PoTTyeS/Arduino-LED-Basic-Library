/* 
 *  
  Filip Zemánek
  Basic Library for LEDs (Main for Arduino R3 Unp)
  Created for home decoration
  Copyright 2020
  Free For Commercial Use
 *
*/

// delay time
#define DELAY_TIME TIME_WHAT_YOU_MUST_DEFINE
#define defined_time TIME_WHAT_YOU_MUST_DEFINE

// pin of leds
#define police_pin_1 NUMBER_OF_PIN_WHAT_YOU_WANT_USE
#define police_pin_2 NUMBER_OF_PIN_WHAT_YOU_WANT_USE

// pin for traffic lights
#define traffic_pin_1 NUMBER_OF_PIN_WHAT_YOU_WANT_USE
#define traffic_pin_2 NUMBER_OF_PIN_WHAT_YOU_WANT_USE
#define traffic_pin_3 NUMBER_OF_PIN_WHAT_YOU_WANT_USE

void setup() {
  // Initialize leds
  for(int cislo = 0; cislo <14; cislo++){
    pinMode(cislo, OUTPUT);
  }
}

// Main loop 
void loop() {
  
  // more than 1 led blinking in defined time
  blinking_leds(DELAY_TIME, NUMBER_OF_LEDS);
  
  // Normal light led
  light_led(led);

  // Police light RED/BLUE in defined time changing colours
  police_light(police_pin_1, police_pin_2, defined_time);

  // RED/YELLOW/GREEN classic traffic lights
  traffic_lights(traffic_pin_1, traffic_pin_2, traffic_pin_3, defined_time);
}


// Blinking
void blinking_leds(int delay_time, int number_of_leds){
  for(int number = 0; number < number_of_leds; number++){
    digitalWrite(number, 1); // Light on
    delay(delay_time);
    digitalWrite(number, 0); // Light off
    delay(delay_time);
  }
}

// Light
void light_leds(){
  for(int number = 0; number < 14; number++){
    digitalWrite(number, 1); // Light on
  }
}

// One led
void light_led(int pin){
  digitalWrite(pin, 1);
 /* delay(1000);
  digitalWrite(pin, 0);
  delay(1000);*/
}

// Police RED/BLUE LEDS BLINKING
void police_light(int led_red, int led_blue, double defined_time){
  digitalWrite(led_blue, 0);
  digitalWrite(led_red, 1);
  delay(defined_time);
  digitalWrite(led_red, 0);
  digitalWrite(led_blue, 1);
  delay(defined_time);
}

// RED/YELLOW/GREEN classic traffic lights
void traffic_lights(int led_red, int led_yellow, int led_green, double defined_time){
  digitalWrite(led_green, 0); // Light on
  digitalWrite(led_red, 1); // Light on
  delay(defined_time);
  digitalWrite(led_red, 0); // Light off
  digitalWrite(led_yellow, 1); // Light on
  delay(defined_time);
  digitalWrite(led_yellow, 0); // Light off
  digitalWrite(led_green, 1); // Light on
  delay(defined_time);
}
