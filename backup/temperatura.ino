String leituraSensor(){

  int thermoDO = 19;
  int thermoCS = 23;
  int thermoCLK = 5;
  const int LED = 32;
  const int LEDG = 26;

  pinMode(LED,OUTPUT);
  pinMode(LEDG,OUTPUT);
  MAX6675 sensor(thermoCLK,thermoCS,thermoDO); 
  
  float temp = sensor.readCelsius();
  Serial.print("Celsius = ");
  Serial.println(temp);
  if(temp > 26.00){
    digitalWrite(LEDG,LOW);
    digitalWrite(LED,HIGH);
    
    
    }
  else{
    digitalWrite(LED,LOW);
    digitalWrite(LEDG,HIGH);
  }
  //Serial.print("fahrenheit = ");
  //Serial.println(sensor.readFahrenheit());
  //Serial.print("Kelvin = ");
  //Serial.println(sensor.readCelsius() + 273);
  //  delay(1000);

  return "'Celsius': '"+ String(temp)+"'";
 }
