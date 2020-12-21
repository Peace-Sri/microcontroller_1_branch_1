void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0){
    String data = Serial.readString();
    Serial.println(((((int(data[0])-48)*10)+((int(data[1])-48)))*60)+((int(data[3])-48)*10)+((int(data[4])-48)));
  }
}
