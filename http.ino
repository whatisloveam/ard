#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

char ssid[] = "RC_S";
char pass[] = "753753method";

void setup()
{
    Serial.begin(9600);
    WiFi.begin(ssid, pass);
    while(WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected");
    Serial.println(WiFi.localIP());
    delay(10000);
}

void loop()
{
    WiFiClient client;
    HTTPClient http;
    if(http.begin(client, "http://api.openweathermap.org/data/2.5/weather?q=Saratov&appid=fce1264e1264433ff300ccb3d0a32413"))
    {
        Serial.println(http.GET());
        String payload = http.getString();
        String temperature = payload.substring(payload.indexOf("temp"),
                                               payload.indexOf("feels"));
        Serial.println(temperature);
        http.end();
    }
    delay(10000);
}
