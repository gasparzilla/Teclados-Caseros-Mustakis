#include <HID-Project.h>
#include <HID-Settings.h>

// PARTE 3 TECLADO, TODOS LOS MODOS

// Importamos la libreria a utilizar


int modo = 0;
int modo_old = 999;

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
  Serial.begin(9600);

  Consumer.begin();
  delay(1000);

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
  modo = analogRead(A0);
  modo = map(modo, 10, 1000, 0, 6);

  Serial.println(modo);

  if (modo != modo_old) {
    modo_old = modo;
    leds(modo);
  }
  // Utilizamos la función switch para cambiar el comportamiento del teclado segun el potenciometro
  switch (modo) {
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
        previousButtonState[i] = buttonState[i]; // Actualizamos el estado de mis botones
      }
      break;

    case 1: // segundo set de caracteres o atajos de teclado
      // Este set incluye un ejemplo de cómo enviar los universales atajos de teclado
      // para copiar, pegar, deshacer y rehacer
      // Si usas Mac, recuerda remplazar KEY_LEFT_CTRL por KEY_LEFT_GUI
      for (int i = 0; i < C_b; i++) {
        buttonState[i] = digitalRead(Botones[i]);
        if ((buttonState[i] != previousButtonState[i])
            && (buttonState[i] == LOW)) {
          switch (i) {
            case 0: // envio el atajo de teclado para COPIAR (CTRL+C)
              Keyboard.press(KEY_LEFT_CTRL); // Presionamos la primer tecla del atajo
              Keyboard.press('c'); // Presionamos la segunda tecla del atajo
              delay(pausa); // Generamos una pausa
              Keyboard.releaseAll(); // Soltamos todas las teclas presionadas
              break;

            case 1: // envio el atajo de teclado para PEGAR (CTRL+V)
              Keyboard.press(KEY_LEFT_CTRL);
              Keyboard.press('v');
              delay(pausa);
              Keyboard.releaseAll();
              break;

            case 2: // envio el atajo de teclado para DESHACER (CTRL+Z)
              Keyboard.press(KEY_LEFT_CTRL);
              Keyboard.press('z');
              delay(pausa);
              Keyboard.releaseAll();
              break;

            case 3: // envio el atajo de teclado para REHACER (CTRL+Y)
              Keyboard.press(KEY_LEFT_CTRL);
              Keyboard.press('y');
              delay(pausa);
              Keyboard.releaseAll();
              break;
          }
        }
        previousButtonState[i] = buttonState[i];
      }
      break;


    case 2: // tercer set de caracteres o atajos de teclado
      // Este set incluye un ejemplo de cómo enviar las flechas del teclado (arriba, abajo, izquierda, derecha),
      // por ejemplo para el uso en juegos online.

      // read the pushbutton:
      for (int i = 0; i < C_b; i++) {
        buttonState[i] = digitalRead(Botones[i]);
        // if the button state has changed,
        if ((buttonState[i] != previousButtonState[i])
            // and it's currently pressed:
            && (buttonState[i] == LOW)) {
          switch (i) {
            case 0: // TECLA FLECHA ARRIBA
              Keyboard.press(KEY_UP_ARROW); // Presionamos Tecla Flecha arriba
              delay(pausa); // Generamos una pausa
              Keyboard.release(KEY_UP_ARROW); // Soltamos Tecla Flecha arriba
              break;

            case 1: // TECLA FLECHA ABAJO
              Keyboard.press(KEY_DOWN_ARROW); // Tecla Flecha abajo
              delay(pausa);
              Keyboard.release(KEY_DOWN_ARROW); // Tecla Flecha arriba
              break;

            case 2: // TECLA FLECHA IZQUIERDA
              Keyboard.press(KEY_LEFT_ARROW); // Tecla Flecha izquierda
              delay(pausa);
              Keyboard.release(KEY_LEFT_ARROW); // Tecla Flecha arriba
              break;

            case 3: // TECLA FLECHA DERECHA
              Keyboard.press(KEY_RIGHT_ARROW); // Tecla Flecha derecha
              delay(pausa);
              Keyboard.release(KEY_RIGHT_ARROW); // Tecla Flecha arriba
              break;
          }
        }
        previousButtonState[i] = buttonState[i];
      }
      break;


    case 3:  // cuarto set de caracteres o atajos de teclado
      // Este set incluye un ejemplo de cómo escribir palabras o frases enteras

      for (int i = 0; i < C_b; i++) {
        buttonState[i] = digitalRead(Botones[i]);
        if ((buttonState[i] != previousButtonState[i])
            && (buttonState[i] == LOW)) {
          switch (i) {
            case 0:
              Keyboard.println("Hola!"); //La librería no reconoce los signos invertidos (¡¿) del idioma castellano
              delay(pausa);
              break;

            case 1:
              Keyboard.print("Soy ");
              delay(pausa);
              break;
            case 2:

              Keyboard.print("una ");
              delay(pausa);
              break;
            case 3:

              Keyboard.println("interfaz experimental");
              delay(pausa);
              break;
          }
        }
        previousButtonState[i] = buttonState[i];
      }
      break;

    case 4:

      for (int i = 0; i < C_b; i++) {
        buttonState[i] = digitalRead(Botones[i]);
        if ((buttonState[i] != previousButtonState[i])
            && (buttonState[i] == LOW)) {
          switch (i) {
            case 0:
              Keyboard.press(KEY_CAPS_LOCK); // Tecla Caps Lock
              delay(pausa);
              Keyboard.release(KEY_CAPS_LOCK); // Tecla Caps Lock
              break;

            case 1:
              Keyboard.press(KEY_LEFT_CTRL);
              Keyboard.press(KEY_LEFT_SHIFT);
              Keyboard.press(KEY_ESC);
              delay(pausa);
              Keyboard.releaseAll();
              break;

            case 2:
              Keyboard.press(KEY_LEFT_CTRL);
              Keyboard.press(KEY_LEFT_ALT);
              Keyboard.press(HID_KEYBOARD_DELETE_FORWARD);
              delay(pausa);
              Keyboard.releaseAll();
              break;

            case 3:
              Keyboard.press(KEY_LEFT_GUI);
              Keyboard.press(KEY_D);
              delay(pausa);
              Keyboard.releaseAll();
              break;
          }
        }
        previousButtonState[i] = buttonState[i];
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
