#include "HX711.h"

const int LOADCELL_DOUT_PIN = 5;
const int LOADCELL_SCK_PIN = 6;

HX711 balanza;

void setup() {
Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:  ");
  balanza.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(-366650); // Establecemos la escala
  balanza.tare(20);  //El peso actual es considerado Tara.
  
  Serial.println("Listo para pesar");  
}

void loop() {
  Serial.print("Peso: ");
  Serial.print(balanza.get_units(20),3);
  Serial.println(" kg");
  delay(500);
}
