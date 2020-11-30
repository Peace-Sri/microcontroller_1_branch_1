int led_pins[4] = {10,11,12,13};
static void setup() {
  for(int num = 0 ; num<4 ; num++){
    pinMode(led_pins[num] , OUTPUT);
  }
}
static void loop() {
  digitalWrite(led_pins[0] , HIGH);
  digitalWrite(led_pins[1] , HIGH);
  digitalWrite(led_pins[2] , HIGH);
  digitalWrite(led_pins[3] , HIGH);
  delay(250);
  digitalWrite(led_pins[0] , HIGH);
  digitalWrite(led_pins[1] , HIGH);
  digitalWrite(led_pins[2] , LOW);
  digitalWrite(led_pins[3] , LOW);
  delay(250);
  digitalWrite(led_pins[0] , LOW);
  digitalWrite(led_pins[1] , LOW);
  digitalWrite(led_pins[2] , HIGH);
  digitalWrite(led_pins[3] , HIGH);
  delay(250);
  digitalWrite(led_pins[0] , LOW);
  digitalWrite(led_pins[1] , LOW);
  digitalWrite(led_pins[2] , LOW);
  digitalWrite(led_pins[3] , LOW);
  delay(250);
}
