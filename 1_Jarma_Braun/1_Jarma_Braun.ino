/*
 El primer programa sirve para corroborar la correcta conexión de los elementos de hardware.
 El mismo deberá encender TODOS los LEDs cuando se presione el pulsador y apagarlos cuando éste se suelte.
*/

int ledsPins[4] = {2, 3, 4, 5}; // Lista con los pines de los leds.
const int BTN = 9;

void setup() {
  // Configuración inicial
  for (int i = 0; i < 4; i++) { // Recorremos cada pin con un led 
    pinMode(ledsPins[i], OUTPUT); // Lo establecemos como salida (porque es un actuador)
  }
  pinMode(BTN, INPUT_PULLUP); // Configuramos el botón con resistencia pull-up interna
}

void loop() {
  int isBtnPressed = digitalRead(BTN); // Leemos el estado del botón

  if (isBtnPressed == LOW) { // Si el botón está presionado (LOW por INPUT_PULLUP)
    for (int i = 0; i < 4; i++) { // Encendemos todos los LEDs
      digitalWrite(ledsPins[i], HIGH);
    }
  } else { // Si NO está presionado (HIGH)
    for (int i = 0; i < 4; i++) { // Apagamos todos los LEDs
      digitalWrite(ledsPins[i], LOW);
    }
  }
  delay(150); // Para evitar los missClicks ponemos unos milisegundos de retraso.
}
