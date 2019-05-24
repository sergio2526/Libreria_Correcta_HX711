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
  balanza.set_scale(); //La escala por defecto es 1
  balanza.tare(20);  //El peso actual es considerado Tara.
  Serial.println("Coloque un peso conocido:");
  
}


void loop() {

  Serial.print("Valor de lectura:  ");
  Serial.println(balanza.get_value(10),0);
  delay(4000);
}


