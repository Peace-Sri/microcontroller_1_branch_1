int ACC = 0;
int index_of_buffer = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    int data = Serial.parseInt();
    ACC = ACC + data;
    Serial.println(ACC);
  }
}