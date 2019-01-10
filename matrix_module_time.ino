#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include "Utils.h"
int pinCS = 9;
int numberOfHorizontalDisplays = 1; // теперь у нас по-горизонтали 6 матриц
int numberOfVerticalDisplays = 4; // а по-вертикали, по-прежнему, одна

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

Utils utils = Utils();

String tape = ""; // текст, который будет плыть
int wait = 80; // время между крайними перемещениями букв

int spacer = 1; // расстояние между буквами
int width = 5 + spacer; // размер шрифта

void setup() {
    tape = utils.utf8rus("Привет Нил!");
    matrix.setIntensity(1); // яркость
    matrix.setRotation(matrix.getRotation() + 1);
}

void loop() {
    for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ ) {
        matrix.fillScreen(LOW);

        int letter = i / width;
        int x = (matrix.width() - 1) - i % width;
        int y = (matrix.height() - 8) / 2; // center the text vertically

        while ( x + width - spacer >= 0 && letter >= 0 ) {
            if ( letter < tape.length() ) {
                matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
            }
            letter--;
            x -= width;
        }

        matrix.write();
        delay(wait);
    }
}
