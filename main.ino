/*
  =============================================================================
  Proyecto: Control de Servomotores con Arduino
  Fecha: 29/10/2026
  Descripción:
    Este programa controla 3 servomotores mediante diferentes entradas:
    1. Servomotor 1: Controlado por un pulsador (ejecuta un giro de 0° a 90° y regresa).
    2. Servomotor 2: Controlado por un switch deslizante (cambia entre 0° y 180°).
    3. Servomotor 3: Funcionamiento independiente (realiza un barrido continuo/automático).
  =============================================================================
*/

#include <Servo.h>

// Definición de Objetos Servo
Servo servo1;
Servo servo2;
Servo servo3;

// Definición de Pines de Entrada
const int PIN_PULSADOR = 2;
const int PIN_SWITCH   = 3;

// Definición de Pines para Servomotores
const int PIN_SERVO1 = 9;
const int PIN_SERVO2 = 10;
const int PIN_SERVO3 = 11;

// Variables de Estado y Control
int estadoPulsador = 0;
int estadoSwitch   = 0;

// Variables para el barrido automático del Servo 3 (sin pausar el código)
int posServo3 = 0;
int direccionServo3 = 1;
unsigned long tiempoPrevio = 0;
const long intervalo = 20; // Velocidad del movimiento en ms

void setup() {
  // Configuración de entradas con resistencias PULL-UP internas
  pinMode(PIN_PULSADOR, INPUT_PULLUP);
  pinMode(PIN_SWITCH, INPUT_PULLUP);

  // Vinculación de servomotores a sus respectivos pines
  servo1.attach(PIN_SERVO1);
  servo2.attach(PIN_SERVO2);
  servo3.attach(PIN_SERVO3);

  // Posiciones iniciales
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  // -------------------------------------------------------------------------
  // CONTROL SERVOMOTOR 1 (Pulsador)
  // Al presionar el pulsador (lectura LOW por INPUT_PULLUP), gira a 90°.
  // Al soltarlo, regresa a 0°.
  // -------------------------------------------------------------------------
  estadoPulsador = digitalRead(PIN_PULSADOR);
  if (estadoPulsador == LOW) {
    servo1.write(90);
  } else {
    servo1.write(0);
  }

  // -------------------------------------------------------------------------
  // CONTROL SERVOMOTOR 2 (Switch Deslizante)
  // Dependiendo de la posición del switch, se posiciona en 0° o 180°.
  // -------------------------------------------------------------------------
  estadoSwitch = digitalRead(PIN_SWITCH);
  if (estadoSwitch == HIGH) {
    servo2.write(180);
  } else {
    servo2.write(0);
  }

  // -------------------------------------------------------------------------
  // CONTROL SERVOMOTOR 3 (Actuación Independiente / Barrido Continuo)
  // Realiza un barrido continuo automático de 0° a 180° usando millis()
  // para no bloquear el programa con delays.
  // -------------------------------------------------------------------------
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoPrevio >= intervalo) {
    tiempoPrevio = tiempoActual;

    posServo3 += direccionServo3;
    servo3.write(posServo3);

    // Cambia la dirección al llegar a los límites (0° o 180°)
    if (posServo3 <= 0 || posServo3 >= 180) {
      direccionServo3 = -direccionServo3;
    }
  }
}
