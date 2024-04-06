#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

Max72xxPanel matrix = Max72xxPanel(9, 1, 1);

const uint8_t IMAGES[][8] = {
{
  0b11111111,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
  0b01000000,
  0b11111111
}};
const int IMAGES_LEN = sizeof(IMAGES)/8;

void setup() 
{
    matrix.setIntensity(7);

    matrix.fillScreen(LOW); // очистка матрицы
    for ( int y = 0; y < 8; y++ ) 
    {
        for ( int x = 0; x < 8; x++ ) 
        {
            matrix.drawPixel(x, y, data[y] & (1<<x)); // масочная операция для вывода конкретного бита из байта
        }
    }
    matrix.write(); // вывод всех пикселей на матрицу
}

void loop() {
}
