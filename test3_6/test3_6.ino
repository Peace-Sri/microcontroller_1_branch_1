uint8_t x = 0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  x--;
  if(x>=16){
    Serial.println(x , HEX);
  }
  if(x<16){
    Serial.print(0);
    Serial.print(x,HEX);
    Serial.println();
  }
}
