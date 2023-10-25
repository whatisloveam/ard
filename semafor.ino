int x = 0;
int y = 128;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  x++;
  y++;
  analogWrite(3, x);
  delay(3);
}
