SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() 
{
  pinMode(13, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("ARDUINO READY");
}

void loop() 
{
  if (BTSerial.available())  //пришло сообщение с блютуза
  {
    char c = BTSerial.read();
    if(c == '0') 
    {
      digitalWrite(13, 0);
      Serial.println("LED OFF");
    }
    if(c == '1') 
    {
      digitalWrite(13, 1);
      Serial.println("LED ON");
    }
    Serial.write(c);
  }
  if (Serial.available()) //пришло сообщение с компа
  {
    BTSerial.write(Serial.read());
  }
}
