#include <stdio.h>
int led_pin = 10;
int input_button_b0 = 2;
int state = 0;
int delay_debounce = 100;
static void setup() {
  pinMode(led_pin , OUTPUT);
  pinMode(input_button_b0 , INPUT);
}
static void loop() {
  if (state == 3){
    for (int _loop =0 ; _loop <3 ; _loop++){
      digitalWrite(led_pin , HIGH);
      delay(1000);
      digitalWrite(led_pin , LOW);
      delay(1000);
    }
    state = 0;
  }
  if(digitalRead(input_button_b0) == HIGH){
    boolean value = debounce(input_button_b0);
    if (value == HIGH){
      state ++;
    }
  }
}
static boolean debounce(int pin){
  boolean previous_state = digitalRead(pin);
  for (int count = 0 ; count < delay_debounce ; count++){
    delay(1);
    int state = digitalRead(pin);
    if (state != previous_state){
      count = 0;
      previous_state = state;
    }
  }
  return previous_state;
}
