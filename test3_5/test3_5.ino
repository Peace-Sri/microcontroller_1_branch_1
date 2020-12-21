uint8_t x = 2;
void setup() {
  Serial.begin(9600);
 
}
void loop() {
  for(int flag=7 ; flag>=0;flag--){
    int value = bitRead(x,flag);
    Serial.print(value);
  }
  Serial.println();
  x++;
}
