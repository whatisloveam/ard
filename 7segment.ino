void setup()
{
    for(int i = 2; i <= 8; i++)
        pinMode(i, OUTPUT);
}
int num = 2;
void loop()
{
    if(num == 0) set7(1, 1, 1, 1, 1, 1, 0);//0
    if(num == 1) set7(0, 1, 1, 0, 0, 0, 0);//1
    if(num == 2) set7(1, 1, 0, 1, 1, 0, 1);//2
    if(num == 3) set7(1, 1, 1, 1, 0, 0, 1);//3
    if(num == 4) set7(0, 1, 1, 0, 0, 1, 1);//4
    if(num == 5) set7(1, 0, 1, 1, 0, 1, 1);//5
    if(num == 6) set7(1, 0, 1, 1, 1, 1, 1);//6
    if(num == 7) set7(1, 1, 1, 0, 0, 0, 0);//7
    if(num == 8) set7(1, 1, 1, 1, 1, 1, 1);//8
    if(num == 9) set7(1, 1, 1, 1, 0, 1, 1);//9
    num++;
    if(num >= 10) num = 0;
    delay(500);
}
void set7(bool a, bool b, bool c, bool d, bool e, bool f, bool g)
{
    digitalWrite(2, a);
    digitalWrite(3, b);
    digitalWrite(4, c);
    digitalWrite(5, d);
    digitalWrite(6, e);
    digitalWrite(7, f);
    digitalWrite(8, g);
}
