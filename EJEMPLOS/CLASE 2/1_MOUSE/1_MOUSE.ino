/* Interfaz "caótica" de dibujo
  El interruptor define si tomamos control o no del mouse del computador.
  Si movemos el interruptor y la luz del botón está encendida, estamos en control del mouse
  Si movemos el interruptor y la luz está apagada, ya no estamos en control del mouse
  Usar esta última opción si nuestro ejercicio se "descontrola"
  Al mover el potenciómetro sólo, dibujaremos principalmente en la línea vertical (con algunos desvíos para que sea más divertido)
  Al mover el potenciómetro presionando el botón a la vez,
  dibujaremos principalmente en la línea Horizontal (con algunos desvíos para que sea más divertido)
  La herramienta online de dibujo que usaremos será:
  https://www.mandalagaba.com/
*/
#include "Mouse.h"

const int switchPin = 10;
const int mouseButton = 6;
const int xAxis = A0;
const int yAxis = A1;
const int ledPin = 8;


int range = 12;
int responseDelay = 5;
int threshold = range / 4;
int center = range / 2;
int distance = 0;
bool mouseIsActive = false;

int ultimoEstadoX = 0;
int ultimoEstadoY = 0;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(mouseButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Mouse.begin();
}

void loop() {
  int switchState = digitalRead(switchPin);
  if (switchState == LOW) {
    mouseIsActive = HIGH;
    digitalWrite(ledPin, mouseIsActive);
  }
  else {
    mouseIsActive = LOW;
    digitalWrite(ledPin, mouseIsActive);
    Mouse.release(MOUSE_LEFT);
  }
  int xReading = analogRead(A0);
  xReading = map(xReading, 0, 1023, 0, 8);
  int yReading = xReading;

  if (mouseIsActive) {
    if (digitalRead(mouseButton) == LOW) {
      Mouse.move(xReading, 0, 0);
      Mouse.press(MOUSE_LEFT);
    }
    else {
      Mouse.move(0, yReading, 0);
      Mouse.press(MOUSE_LEFT);
    }
  }
  delay(responseDelay);
}
