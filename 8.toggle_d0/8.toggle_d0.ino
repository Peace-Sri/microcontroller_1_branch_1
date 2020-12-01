#include <stdio.h>
int led_pin = 10; //D0
int input_button_b0 = 2; //input button0
int input_button_b1 = 3; //input button1
int debounce_delay = 100; //delay_time
int state = 0; //off-led state
static void setup() {
  pinMode(input_button_b0 , INPUT);
  pinMode(input_button_b1 , INPUT);
  pinMode(led_pin , OUTPUT);
}
static void loop() {
  if (digitalRead(input_button_b0) == HIGH && digitalRead(input_button_b1) == HIGH){
  boolean value = debounce(input_button_b0 , input_button_b1);
  if (value == 1){
    if (state == 0){
      digitalWrite(led_pin , HIGH);
      state = 1; //update state to on-led
      delay(100);
    }
    else{
      digitalWrite(led_pin , LOW);
      state = 0; //update state to off-led
      delay(100);
    }
  }
  }
}
static boolean debounce(int pin1 , int pin2){
  int previous_state1 = digitalRead(pin1);
  int previous_state2 = digitalRead(pin2);
  for(int count=0 ; count < debounce_delay ; count ++ ){
    delay(1);
    int state1 = digitalRead(pin1);
    int state2 = digitalRead(pin2);
    if(state1 != previous_state1 || state2 != previous_state2){
      count = 0;
      previous_state1 = state1;
      previous_state2 = state2;
    }
  }
  if (previous_state1 == HIGH && previous_state2 == HIGH){
  return 1;
  }
  else {
    return 0;
  }
}
