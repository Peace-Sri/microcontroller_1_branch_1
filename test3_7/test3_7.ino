void setup()
{
  Serial.begin(9600);
  for(int number=0;number<10;number++){
    randomSeed(analogRead(0));
    Serial.println(random(100,201));  //Random from 100 to 200 //
  }
}
void loop()
{
}
