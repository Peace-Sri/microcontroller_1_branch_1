int led_pin[4] = {10,11,12,13}; //MSD --> LSD
int num = 0; //Create number from 0 - 15
static void setup() {
  for(int led=2 ; led<6 ; led++){ // Initial definetion of any port
    pinMode(led_pin[led] , OUTPUT);
  }
}
static void loop() {
  if(num <= 15){
  convert_to_bin(num);
  off_led();
  }
  num ++;
}
static int convert_to_bin(int num){
  for(int count = 3 ; num > 0 ; count--){
    if(num%2 == 1){
      digitalWrite(led_pin[count] , HIGH);
    }
    if(num%2 == 0){
      digitalWrite(led_pin[count] , LOW);
    }
    num = num / 2;
  }
  delay(500);
}
static void off_led(){
  for(int i = 0 ; i<4 ; i++){
    digitalWrite(led_pin[i] , LOW);
  }
}
