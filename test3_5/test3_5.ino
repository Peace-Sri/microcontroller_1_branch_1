uint8_t x = 0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println(x , BIN);
  x++;
}
