// Importamos la libreria a utilizar

#include <HID-Project.h>
#include <HID-Settings.h>

// Definición de variables que almacenarán el modo a indicar 
// por la cantidad de leds encendidos
int modo = 0;
int modo_old = 999;

// Definicion de constantes que indican los pines para cada led
const int led0 = 6;
const int led1 = 7;
const int led2 = 8;
const int led3 = 9;

int Botones[] = {2, 3, 4, 5};  // Variable de tipo Array con los pines donde están nuestros botones
const int C_b = 4;             // Variable que define cuantos botones tenemos
int buttonState[] = {1, 1, 1, 1};  // Variable de tipo Array donde guardamos el estado actual de nuestros botones
int previousButtonState[] = {1, 1, 1, 1};  // Variable de tipo Array donde guardo el estado anterior de nuestro botones

int pausa = 100; // Pausa para simular interfaz humana

void setup() {
  // Iniciamos comunicacion serial
  Serial.begin(9600);

  Consumer.begin();
  delay(1000);

  // Inicializamos los pines asociados a cada led
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Para cada pin que utilizamos como boton
  for (int i = 0; i < C_b; i++) {
    pinMode(Botones[i], INPUT_PULLUP); // Definimos el modo de operacion como INPUT_PULLUP
  }
}

void loop() {
  // Leemos el valor del potenciometro
  modo = analogRead(A0);
  // y lo asociamos a un modo de operaicion (0-6)
  modo = map(modo, 10, 1000, 0, 6);

  // lo mostramos en consola para verificar 
  Serial.println(modo);

  // Si el modo de operacion cambia
  // Actualizamos las luces led
  if (modo != modo_old) {
    modo_old = modo;
    leds(modo);
  }
  
  // Utilizamos la función switch para cambiar el comportamiento del teclado segun el potenciometro
  switch (modo) {
    // en el primer caso (modo 0)
    case 0:
      // Para Cada Boton en nuestra lista de botones
      for (int i = 0; i < C_b; i++) {
        buttonState[i] = digitalRead(Botones[i]); //leemos y guardamos el valor que devuelven los botones
        if ((buttonState[i] != previousButtonState[i]) // si el estado de alguno cambio
            && (buttonState[i] == LOW)) { // Y actualmente está siendo presionado

          // Usamos nuevamente la función switch() para enviar información de teclado distinta para cada botón
          switch (i) {
            case 0: //LETRA A MAYÚSCULA
              Keyboard.print('A'); // imprimimos la letra A mayúscula
              delay(pausa); // Generamos una pausa
              break;

            case 1: //LETRA B MAYÚSCULA
              Keyboard.print('B'); // imprimimos la letra B mayúscula
              delay(pausa); // Generamos una pausa
              break;

            case 2: //LETRA C MAYÚSCULA
              Keyboard.print('C'); // imprimimos la letra C mayúscula
              delay(pausa); // Generamos una pausa
              break;

            case 3: //LETRA D MAYÚSCULA
              Keyboard.print('D'); // imprimimos la letra D mayúscula
              delay(pausa); // Generamos una pausa
              break;
          }
        }
        previousButtonState[i] = buttonState[i]; // Actualizamos el estado de los botones
      }
      break;

  }


}

// Funcion que cambia el led encendido para indicar el modo de operaicion de nuestra interfaz
void leds(int modo) {
  switch (modo) {
    case 0:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    case 1:
      digitalWrite(led0, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    case 2:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    case 3:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(50);
      break;
    case 4:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    case 5:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(50);
      break;
    case 6:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(50);
      break;
  }
}
