#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

Max72xxPanel matrix = Max72xxPanel(9, 1, 1);

const uint8_t IMAGES[][8] = {
{
  0b00010000,
  0b00110000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00111000
},{
  0b00111000,
  0b01000100,
  0b00000100,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
  0b01111100
},{
  0b00111000,
  0b01000100,
  0b00000100,
  0b00011000,
  0b00000100,
  0b00000100,
  0b01000100,
  0b00111000
}};
const int IMAGES_LEN = sizeof(IMAGES)/8;

void setup() 
{
    matrix.setIntensity(7);

    matrix.fillScreen(LOW); // очистка матрицы
    for(int slide = 0; slide < IMAGES_LEN; slide++)
    {
      for ( int y = 0; y < 8; y++ ) 
      {
          for ( int x = 0; x < 8; x++ ) 
          {
              matrix.drawPixel(x, y, data[slide][y] & (1<<x)); // масочная операция для вывода конкретного бита из байта
          }
      }
      matrix.write(); // вывод всех пикселей на матрицу
      delay(500);
    }
}

void loop() {
}
