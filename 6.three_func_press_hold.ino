String pattern1 = "1111";
String pattern2 = "0011";
String pattern3 = "1010";
int led_pin[4] = {10,11,12,13};
int index_led = 3;
int input_button_b0 = 2;
int input_button_b1 = 3;
int delay_bounce = 100;
void setup() {
  pinMode(input_button_b0 , INPUT);
  pinMode(input_button_b1 , INPUT);
  for(int number_led = 0 ; number_led < sizeof(led_pin)/sizeof(led_pin[0]) ; number_led++){
    pinMode(led_pin[number_led] , HIGH);
  }
}
void loop() {
  if (digitalRead(input_button_b0) == LOW && digitalRead(input_button_b1) == LOW){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      for (int number=0 ; number < 4 ; number ++){
        digitalWrite(led_pin[number] , pattern1[number]-48);
      }
    }
  }
  if (digitalRead(input_button_b0) == HIGH && digitalRead(input_button_b1) == LOW){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      for (int number=0 ; number < 4 ; number ++){
        digitalWrite(led_pin[number] , pattern2[number]-48);
      }
    }
  }
  if (digitalRead(input_button_b0) == LOW && digitalRead(input_button_b1) == HIGH){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      for (int number=0 ; number < 4 ; number ++){
        digitalWrite(led_pin[number] , pattern3[number]-48);
      }
    }
  }
}
boolean debounce(int pin){
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
