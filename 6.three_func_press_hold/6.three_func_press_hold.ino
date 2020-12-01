#include <stdio.h>
String pattern = "111100111010";
int led_pin[4] = {10,11,12,13};
int index_led = 3;
int input_button_b0 = 2;
int input_button_b1 = 3;
int delay_bounce = 100;
static void setup() {
  pinMode(input_button_b0 , INPUT);
  pinMode(input_button_b1 , INPUT);
  for(int number_led = 0 ; number_led < sizeof(led_pin)/sizeof(led_pin[0]) ; number_led++){
    pinMode(led_pin[number_led] , HIGH);
  }
}
static void loop() {
  if (digitalRead(input_button_b0) == LOW && digitalRead(input_button_b1) == LOW){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      for (int number=0 ; number < 4 ; number ++){
        digitalWrite(led_pin[number] , pattern[number]-48);
      }
    }
  }
  if (digitalRead(input_button_b0) == HIGH && digitalRead(input_button_b1) == LOW){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      for (int number=4 ; number < 8 ; number ++){
        digitalWrite(led_pin[number] , pattern[number]-48);
      }
    }
  }
  if (digitalRead(input_button_b0) == LOW && digitalRead(input_button_b1) == HIGH){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      for (int number=8 ; number < 12 ; number ++){
        digitalWrite(led_pin[number] , pattern[number]-48);
      }
    }
  }
}
static boolean debounce(int pin){
  boolean previous_state = digitalRead(pin);
  for(int count = 0 ; count < delay_bounce ; count ++){
    boolean state = digitalRead(pin);
    delay(1);
    if (state != previous_state){
      count = 0 ;
      previous_state = state;
    }
  }
  return previous_state;
}
