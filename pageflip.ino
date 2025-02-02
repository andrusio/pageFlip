#include <BleKeyboard.h>

BleKeyboard bleKeyboard("FlipPage", "Andytronic");

const int pulsadorPin = 33;

unsigned long tiempoPulsacionInicio = 0;
const unsigned long tiempoPulsacionCorta = 1000; 
const unsigned long tiempoIgnorarPulsacion = 120; 

bool pulsacionLargaEnviada = false;

void setup() {
  Serial.begin(115200);
  pinMode(pulsadorPin, INPUT_PULLUP);
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int pulsadorEstado = digitalRead(pulsadorPin);

    if (pulsadorEstado == LOW) {
      tiempoPulsacionInicio = millis();
      pulsacionLargaEnviada = false; 

      while (digitalRead(pulsadorPin) == LOW) {
        unsigned long tiempoTranscurrido = millis() - tiempoPulsacionInicio;

        if (tiempoTranscurrido >= tiempoPulsacionCorta && !pulsacionLargaEnviada) {
          Serial.println("Sending 'Pg Up'...");
          bleKeyboard.write(KEY_PAGE_UP);
          pulsacionLargaEnviada = true;
        }
      }

      if (!pulsacionLargaEnviada) {
        unsigned long tiempoTranscurrido = millis() - tiempoPulsacionInicio;
        if (tiempoTranscurrido >= tiempoIgnorarPulsacion) {
          Serial.println("Sending 'Pg Down'...");
          bleKeyboard.write(KEY_PAGE_DOWN);
        }
      }
    }
  }
}
