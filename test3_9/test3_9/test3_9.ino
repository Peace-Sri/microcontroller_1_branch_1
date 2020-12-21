void setup()
{
  Serial.begin(9600);
  for(int i=2;i<13;i++){
    for(int j=1;j<13;j++){
      Serial.println(String(i)+"x"+String(j)+"="+String(i*j));
    }
  }
}
void loop()
{
}
