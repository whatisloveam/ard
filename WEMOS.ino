#include <ESP8266WiFi.h>
const char WiFiPassword[] = "PAROL_DLYA_WEMOSA";
const char AP_NameChar[] = "LOGIN_DLYA_WEMOSA" ;
 
WiFiServer server(80);
 
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><title>LED Control</title></head><body><div id='main'><h2>LED Control</h2>";
String html_2 = "<form id='F1' action='LEDON'><input class='button' type='submit' value='LED ON' ></form><br>";
String html_3 = "<form id='F2' action='LEDOFF'><input class='button' type='submit' value='LED OFF' ></form><br>";
String html_4 = "</div></body></html>";
 
String request = "";
int LED_Pin = D1; // тут можно и LED BUILTIN
 
void setup() 
{
    pinMode(LED_Pin, OUTPUT); 
    boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
    server.begin();
}
 
void loop() 
{
    WiFiClient client = server.available();
    if (!client) return; //проверка клиентов

    request = client.readStringUntil('\r');
 
    if       ( request.indexOf("LEDON") > 0 )  digitalWrite(LED_Pin, HIGH);
    else if  ( request.indexOf("LEDOFF") > 0 ) digitalWrite(LED_Pin, LOW);
 
    client.flush();
 
    client.print( header );
    client.print( html_1 );
    client.print( html_2 );
    client.print( html_3 );
    client.print( html_4);
 
    delay(5); 
}
