String leituraSensor(){
  int LED = 32;
  int LEDG = 26;
  float max_ = 26.00;
  float min_ = 20.00;

  OneWire oneWire(dados);  /*Protocolo OneWire*/
  /********************************************************************/
  DallasTemperature sensors(&oneWire); /*encaminha referências OneWire para o sensor*/
  sensors.begin(); /*inicia biblioteca*/
  sensors.requestTemperatures(); /* Envia o comando para leitura da temperatura */
  Serial.println(sensors.getTempCByIndex(0)); /* Endereço do sensor */

  float temp = sensors.getTempCByIndex(0);
 
  if(temp > max_ || temp < min_){
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

  return "'Celsius': "+ String(temp)+", 'TemperaturaMaxima': "+ String(max_)+", 'TemperaturaMinima': "+String(min_);
 }
