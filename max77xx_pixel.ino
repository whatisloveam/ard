#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

Max72xxPanel matrix = Max72xxPanel(9, 1, 1);

void setup() {
    matrix.setIntensity(4); // яркость от 0 до 15
}

void loop() {
    matrix.drawPixel(3, 4, HIGH); // зажигаем пиксель с координатами {3,4}
    matrix.write(); // вывод всех пикселей на матрицу
    delay(300);
    matrix.drawPixel(3, 4, LOW);
    matrix.write();
    delay(300);
}
