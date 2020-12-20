void setup() {
  Serial.begin(9600);
}
void loop() {
  for(uint32_t count = 60000 ; count>=0 ; count=count-5){
    Serial.println(count);
    delay(300);
  }
}
