int led_pin[4] = {13,12,11,10};
int input_button_b0 = 2 ;
int input_button_b1 = 3 ;
int delay_debounce = 100;
int current_led = 3;
float k = 2000;
float k_delay_state1 = 0.01;
float k_delay_state2 = 0.01;
int state = 0;
int previous_state = 0;
static void setup() {
  pinMode(input_button_b0 , INPUT);
  pinMode(input_button_b1 , INPUT);
  for (int number_led = 0 ; number_led < sizeof(led_pin) / sizeof(led_pin[0]) ; number_led++){
    pinMode(led_pin[number_led] , OUTPUT);
  }
}
static void loop() {
  if(state != previous_state){
    previous_state = state;
    k = 2000;
    k_delay_state1 = 0.01;
    k_delay_state2 = 0.01;
  }
  if (digitalRead(input_button_b0) == LOW && digitalRead(input_button_b1) == LOW){
      if (k > 0 ){
        state = 0;
        current_led ++;
        if(current_led > 3){
          current_led = 0;
        }
        digitalWrite(led_pin[current_led] , HIGH);
        delay(k);
        digitalWrite(led_pin[current_led] , LOW);
        Serial.println(k);
        }
    }
  if (digitalRead(input_button_b0) == HIGH && digitalRead(input_button_b1) == LOW || state == 1){
    boolean value = debounce(input_button_b0);
    if (value = HIGH){
      if (k > 0 ){
        state = 1;
        current_led ++;
        if(current_led > 3){
          current_led = 0;
        }
        digitalWrite(led_pin[current_led] , HIGH);
        k = k - (10/ k_delay_state1);
        delay(k);
        k_delay_state1 +=0.04;
        digitalWrite(led_pin[current_led] , LOW);
        Serial.println(k);
        }
    }
  }
  if (digitalRead(input_button_b0) == LOW && digitalRead(input_button_b1) == HIGH || state==2 ){
    boolean value = debounce(input_button_b1);
    if (value = HIGH){
      if (k > 0 ){
        state = 2;
        current_led ++;
        if(current_led > 3){
          current_led = 0;
        }
        digitalWrite(led_pin[current_led] , HIGH);
        k = k + (10/ k_delay_state2);
        delay(k);
        k_delay_state2 +=0.04;
        digitalWrite(led_pin[current_led] , LOW);
        Serial.println(k);
        }
    }
  }
  }
static boolean debounce(int pin){
  boolean previous_state = digitalRead(pin);
  for(int count = 0 ; count < delay_debounce ; count ++){
    delay(1);
    int state = digitalRead(pin);
    if (state != previous_state){
      count = 0 ;
      previous_state = state;
    }
  }
  return previous_state;
}
