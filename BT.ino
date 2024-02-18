SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() 
{
  BTSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("ARDUINO READY");
}

void loop() 
{
  if (BTSerial.available())  //пришло сообщение с блютуза
  {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) //пришло сообщение с компа
  {
    BTSerial.write(Serial.read());
  }
}
