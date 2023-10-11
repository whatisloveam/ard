void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}
int x = 0;
void loop()
{
    if(!digitalRead(2) == 1)
    {
        x = (x+1) % 90;
        Serial.println(x);
        delay(10);
    }
    if(!digitalRead(3) == 1)
    {
        x--;
        if(x < 0) x = 90;
        Serial.println(x);
        delay(10);
    }
    for(int i = 0; i < x; i++)
        Serial.print(" ");
    Serial.print("x");
}
