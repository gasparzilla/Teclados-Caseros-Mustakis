// Configuracion, se ejecuta una vez al comienzo
void setup() {
  Serial.begin(9600); // Iniciar comunacion serial

}

// Programa principal
void loop() {
  int pot = analogRead(A0); // leemos el valor del potenciometro

  String texto = "El valor es = " + String(pot); // Generamos texto con el valor leido

  Serial.println(texto); // mostramos el texto en el monitor
}
