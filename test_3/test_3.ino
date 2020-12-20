String first_name = "RATCHAKORNSRIHERA";
void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int number = 0 ; number < 17 ; number++){
    Serial.println(first_name[number]);
    delay(200);
  }
}
