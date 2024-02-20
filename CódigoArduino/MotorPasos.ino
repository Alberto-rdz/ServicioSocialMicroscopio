// Incluye la librería Stepper
#include <Stepper.h>

// Define el número de pasos por revolución y los pines a los que está conectado el motor
const int stepsPerRevolution = 500;  // Este valor depende del motor a pasos
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  // Pines de control del puente H L298

//MOTOR PEQUE
const int MotorPeque = 2040; // El número de pasos por revolución del motor pequeño
const int motorPin1 = 2; // Conecta el cable rojo del motor pequeño al pin 2
const int motorPin2 = 3; // Conecta el cable amarillo del motor pequeño al pin 3
const int motorPin3 = 4; // Conecta el cable azul del motor pequeño al pin 4
const int motorPin4 = 5; // Conecta el cable naranja del motor pequeño al pin 5

Stepper myStepper2(MotorPeque, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  // Inicializa el puerto serial a 9600 bps
  Serial.begin(9600);

  // Establece la velocidad del motor en rpm (ajusta según sea necesario)
  myStepper.setSpeed(60);
  myStepper2.setSpeed(10); // 10 RPM
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Realiza el patrón mencionado
    if (command == '0') {
      for(int t = 0; t<=10; t++){
      // Primer ciclo
      myStepper2.step(700);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);

      // Segundo ciclo
      myStepper2.step(700);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      }
      
    } else if(command == '1'){
      myStepper2.step(700);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
      myStepper.step(50);
      delay(500);
    } else if(command == '2'){
      myStepper2.step(-700);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
      myStepper.step(-50);
      delay(500);
    }
  }
}
