void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() >0){
    char input_data = Serial.read();
    String type_dat = check_data_type(input_data);
//    Serial.print(input_data);
    Serial.println(type_dat);
  }

}

String check_data_type(char input_data){
  if(97 <= input_data && input_data <= 122){
    return("a small letter");
  }
  else if( 48 <= input_data && input_data <= 57){
    return("number");
  }
  
  else if(65 <= input_data && input_data <= 90){
    return("a capital letter");
  }
  else{
    return("a symbol");
  }
}
