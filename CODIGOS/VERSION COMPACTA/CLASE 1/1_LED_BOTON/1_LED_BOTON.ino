// Definimos nuestras variables

const int pinLed = 6;
const int pinBoton = 2;

int boton = 0;

// Configuracion, se ejecuta una vez al inicio
void setup() {
  pinMode(pinLed, OUTPUT); // Definir el modo del pin asociado al led
  pinMode(pinBoton, INPUT_PULLUP); // Definir el modo del pin asociado al boton
}

// Programa principal
void loop() {
  boton = digitalRead(pinBoton); // leer el estado del boton
  if (boton == LOW){             // si se pulsa el boton
    digitalWrite(pinLed, HIGH);  // encender el led
  }
  else{                          // si no
    digitalWrite(pinLed, LOW);   // apagarlo
  }
}
