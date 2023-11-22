int tt = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT_PULLUP);
    tt = random(10, 40);
}

int getCM()
{
    int t;
    digitalWrite(2, 0);
    delayMicroseconds(2);
    digitalWrite(2, 1);
    delayMicroseconds(10);
    digitalWrite(2, 0);
    t = pulseIn(3, 1, 2900);
    return t / 58;
}

void loop()
{
    if(digitalRead(4) == 0)
    {
        int cm = getCM();
        Serial.println(cm - tt);
        tt = random(10, 40);
        Serial.println(tt);
        delay(300);
    }
    
}
