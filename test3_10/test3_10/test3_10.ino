const double pi = 2 * acos(0.0);
void setup()
{
  Serial.begin(9600);
  for(int number=0;number<361;number++){
    Serial.println(sin(number*(pi/180)) , 5); //5 decimal points
  }
}
void loop()
{
}
