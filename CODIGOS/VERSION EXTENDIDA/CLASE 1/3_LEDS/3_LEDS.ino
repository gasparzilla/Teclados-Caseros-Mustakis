// Definición de variables que almacenarán el modo a indicar 
// por la cantidad de leds encendidos
int modo = 0;
int modo_old = 999;

// Definicion de constantes que indican los pines para cada led
const int led0 = 6;
const int led1 = 7;
const int led2 = 8;
const int led3 = 9;

void setup() {
  // Inicializamos los pines asociados a cada led
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

// Ejecucion del codigo
void loop() {
  // leemos el valor del potenciometro guardandolo en la variable "modo"
  modo = analogRead(A0);
  // asociamos el valor leido a uno de los 7 modos de operacion
  modo = map(modo, 10, 1000, 0, 6);


  // Encendemos la cantidad de leds adecuada para cada modo
  // Solo se actualiza si el modo cambia
  if (modo != modo_old) {
    modo_old = modo;
    leds(modo);
  }

}

// Funcion que cambia el led encendido para indicar el modo de operaicion de nuestra interfaz
void leds(int modo) {
  switch (modo) {
    // Si el modo es 0, sólo encendemos el primer led
    case 0:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    // Si el modo es 1, sólo encendemos el segundo led
    case 1:
      digitalWrite(led0, LOW);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    // Si el modo es 2, sólo encendemos el tercer led
    case 2:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    // Si el modo es 3, sólo encendemos el cuarto led
    case 3:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(50);
      break;
    // Si el modo es 4, encendemos los dos primeros leds
    case 4:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(50);
      break;
    // Si el modo es 5 encendemos los dos leds finales
    case 5:
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(50);
      break;
    // Si el modo es 6, encendemos todos los leds
    case 6:
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(50);
      break;
  }
}
