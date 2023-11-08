void setup()
{
    pinMode(2, INPUT);
    pinMode(4, INPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    Serial.begin(9600);
}

int score1 = 0;
int score2 = 0;

void loop()
{
    digitalWrite(3, 1);
    while(true)
    {
        if (digitalRead(2))
        {
            Serial.println("p1 pressed");
            score1++;
            Serial.print(score1);
            Serial.print(":");
            Serial.println(score2);
            break;
        }
        if (digitalRead(4))
        {
            Serial.println("p2 pressed");
            score2++;
            Serial.print(score1);
            Serial.print(":");
            Serial.println(score2);
            break;
        }
    }
    digitalWrite(3, 0);
    if(score1 == 10) 
    {
        digitalWrite(5, 1);
        Serial.println("P1 WON. PROJECT MADE BY SOMENAME IN EKATERINGBURG");
        for(;;);
    }
    if(score2 == 10)
    {
       digitalWrite(6, 1);
       Serial.println("P2 WON. PROJECT MADE BY SOMENAME IN EKATERINGBURG");
       for(;;); 
    } 
    delay(random(3000, 7000));
}
