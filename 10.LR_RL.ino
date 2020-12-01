int state = 0; // 0 = left-right ; 1 = right-left
int *ptr_state = &state;
int led_pin[4] ={10,11,12,13};
int input_button = 2;
int delay_debounce = 100;
int current_led = 3;
void setup() {
  Serial.begin(9600);
  pinMode(input_button , INPUT);
  for (int number_led = 0 ; number_led < 4 ; number_led ++){
    pinMode(led_pin[number_led] , OUTPUT);
  }
}
static void loop() {
  Serial.print(digitalRead(*ptr_state));
  if(digitalRead(input_button) == LOW){
    boolean val = debounce(input_button);
    if(val == LOW){
      if(*ptr_state == 0){
        *ptr_state = 1;
      }
      else if(*ptr_state == 1){
        *ptr_state =0;
      }
    }
  }
  loop_led(*ptr_state);
}
boolean debounce(int pin){
  boolean previous_state = digitalRead(pin);
  for(int count = 0 ;  count <= delay_debounce ; count++){
    delay(1);
    int state = digitalRead(pin);
    if(state != previous_state){
      count = 0;
      previous_state = state; 
    }
  }
  return previous_state;
}
void loop_led(int state ){
  if(state == 0){ //left_right
      current_led ++;
      if(current_led > 3){
        current_led = 0;
      }
    digitalWrite(led_pin[current_led] , HIGH);
    delay(100);
    digitalWrite(led_pin[current_led] , LOW);
    
  }
  if(state == 1){
    current_led --;
    if(current_led <0){
      current_led = 3;
    }
    digitalWrite(led_pin[current_led] , HIGH);
    delay(100);
    digitalWrite(led_pin[current_led] , LOW);
  }
}
