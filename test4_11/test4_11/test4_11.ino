void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
  String value = Serial.readString();
  Serial.println(String(value[0])+String(value[1])+String(value[2]));
  }

}
