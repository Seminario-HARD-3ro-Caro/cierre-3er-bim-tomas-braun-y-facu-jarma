/*
  A continnuación se desea fabricar un contador binario de 4 bits.
  El programa deberá contar de 0 a 15 mostrando la cuenta actual a través de los 4 LEDs.
  Se interpreta 0 si el LED está apagado y 1 si el LED está prendido. 
  La cuenta aumenta cada vez que el pulsador es presionado, al llegar a 15 deberá volver a empezar en 0.
  IMPORTANTE: la cuenta debe aumentar UNA SOLA VEZ por cada pulsación.
*/

int ledsPins[4] = {2,3,4,5}; // Lista con los pines de los leds.
bool prev = false;
int counter = 0; // 'counter' va a llevar la cuenta de clicks hechos
const int BTN  = 9;

void setup() {
  for(int i = 0; i < 4; i++){ // Recorremos cada pin con un led y 
    pinMode(ledsPins[i], OUTPUT); // Lo establecemos como salida (porque es un actuador)
  }
  pinMode(BTN, INPUT); // El pin del boton es un 'OUTPUT'.
  Serial.begin(9600);
}
String decimalToBinary(int decimal) { // Funcion para pasar de decimal a binario
  String binario = "";  // Inicializamos una cadena vacía

  if (decimal == 0) {
    return "0000";  // Si el número es 0, devolvemos "0000" directamente
  }

  while (decimal > 0) {
    int residuo = decimal % 2;    // Obtén el residuo de la división entre 2 (0 o 1)
    decimal /= 2;                 // Divide el número decimal entre 2
    binario = String(residuo) + binario;  // Añade el residuo al inicio de la cadena
  }

  // Aseguramos que la cadena tenga exactamente 4 caracteres, añadiendo ceros a la izquierda si es necesario
  while (binario.length() < 4) {
    binario = "0" + binario;
  }

  return binario;  // Devuelve la cadena que representa el número binario
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
  if(realStateOfButton()){ // Si esta presionado:
    
    counter++; // Aumentamos el contador
    
    counter  = counter % 16; // Si supera 15 lo reseteamos a 0
    
    String res = decimalToBinary(counter);   // Obtenemos el valor en binario de 'counter'.
    Serial.println(String(counter) + " " + res);
    digitalWrite(ledsPins[0], res[3] == '1'); // Al LED 1 le damos el cuarto valor en binario.
    digitalWrite(ledsPins[1], res[2] == '1'); // Al LED 2 le damos el tercero valor en binario.
    digitalWrite(ledsPins[2], res[1] == '1'); // Al LED 3 le damos el segundo valor en binario.
    digitalWrite(ledsPins[3], res[0] == '1'); // Al LED 4 le damos el primer valor en binario.
    
    delay(150); // Para evitar los missClicks ponemos unos milisegundos de retraso.
  }
}
