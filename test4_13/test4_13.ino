int button_pin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(button_pin , INPUT);
  randomSeed(analogRead(0));
}
void loop() {
  if(digitalRead(button_pin) == 1){
    boolean val = check_debounce(button_pin);
    if(val == 1){
      Serial.println(random(0,101));
    }
  }
}
boolean check_debounce(int button_pin){
  boolean previous_state = digitalRead(button_pin);
  for(int count=0;count<=100;count++){
    delay(1);
    boolean state = digitalRead(button_pin);
    if(previous_state != state){
      count = 0;
      previous_state = state;
    }
  }
  return previous_state;
}
