void setup()
{
  Serial.begin(9600);
  for(int number=0;number<101;number++){
  Serial.println(sqrt(number));
  }
}
void loop()
{
}
