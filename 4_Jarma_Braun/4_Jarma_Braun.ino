int numero = 0;
bool prev = false;

void setup() {
  pinMode(9, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Leer desde el monitor de serie
  if (Serial.available() > 0) {
    // Leer el número enviado y convertirlo a un entero
    int recibido = Serial.parseInt();
    
    // Validar que el número esté entre 0 a 15
    if (recibido >= 0 && recibido <= 15) {
      numero = recibido;
    }
    // Si el numero es mayor a 15, dar mensaje de error
    if (recibido > 15) {
      Serial.println("Error, numero mayor a 15");
    }
  }

  // Control de LEDs según el valor de `numero`

  //valor de 0 (0000)
  if (numero == 0) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  //valor de 1 (0001)
  if (numero == 1) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  //valor de 2 (0010)
  if (numero == 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  //valor de 3 (0011)
  if (numero == 3) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  //valor de 4 (0100)
  if (numero == 4) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  //valor de 5 (0101)
  if (numero == 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  //valor de 6 (0110)
  if (numero == 6) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  //valor de 7 (0111)
  if (numero == 7) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }

  //valor de 8 (1000)
  if (numero == 8) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  //valor de 9 (1001)
  if (numero == 9) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  //valor de 10 (1010)
  if (numero == 10) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  //valor de 11 (1011)
  if (numero == 11) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  //valor de 12 (1100)
  if (numero == 12) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

  //valor de 13 (1101)
  if (numero == 13) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

  //valor de 14 (1110)
  if (numero == 14) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

  //valor de 15 (1111)
  if (numero == 15) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  //si el valor del numero es mayor a 15, volver a 0
  if (numero > 15) {
    numero = 0;
  }

  Serial.println(numero);
}
