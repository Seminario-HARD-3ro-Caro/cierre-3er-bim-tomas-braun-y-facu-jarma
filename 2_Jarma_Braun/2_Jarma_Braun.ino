/*
  En el siguiente programa se deberá prender de a UN LED POR VEZ.
  Por cada pulsación se deberá apagar el LED prendido y prender el LED más próximo de la derecha.
  En caso de no haber, se deberá volver a empezar la vuelta, empezando desde el LED de la izquierda.
*/

int ledsPins[4] = {2,3,4,5}; // Lista con los pines de los leds.
bool prev = false;
int actualIndexOfLED = -1; // Empieza -1 para que al sumar se sume y pase a 0 entonces el verde se prende.
const int BTN  = 9;

void setup() {
  for(int i = 0; i < 4; i++){ // Recorremos cada pin con un led y 
    pinMode(ledsPins[i], OUTPUT); // Lo establecemos como salida (porque es un actuador)
  }
  pinMode(BTN, INPUT);  
}

bool realStateOfButton(){ // Esta funcion sirve para saber el estado verdadero de un boton.
  if(prev == true && digitalRead(BTN) == false){ // Si antes estaba prendido y dejamos de pulsar entonces ahora el estado anterior es apagado
    prev = false;
  }
  
  bool isBtnPressed = (digitalRead(BTN) == true && prev == false); // Si fue al revez, el estado actual es prendido
  if(isBtnPressed){
    prev = true;
    return true; // Retornamos true porque ese es el eestado del boton
  }
  return false;
}


void loop() {
  if(realStateOfButton()){ // Si esta presionado (Valor real del boton, es decir, ignorando que se mantenga):
    
    actualIndexOfLED++; // En cada click cambiamos de led hacia la derecha (sumamos uno al indice de la lista).
    actualIndexOfLED  = actualIndexOfLED % 4; // Si supera o iguala 4 lo reseteamos a 0.
    
    for (int i = 0; i < 4; i++) { // Apagamos todos los LEDs
      digitalWrite(ledsPins[i], LOW);
    }
    digitalWrite(ledsPins[actualIndexOfLED], HIGH); // Para ahora prender el LED que toca en este momento.

    delay(150); // Para evitar los missClicks ponemos unos milisegundos de retraso.
  }
  
}
