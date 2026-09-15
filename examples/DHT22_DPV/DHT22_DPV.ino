/**
 * @file    DHT22_DPV.ino
 * @brief   Ejemplo de uso de la librería DPV con un sensor DHT22.
 *
 * Conexiones:
 *   DHT22 VCC  -> 5V
 *   DHT22 GND  -> GND
 *   DHT22 DATA -> Pin 7 (con resistencia pull-up de 10 kΩ a VCC)
 */

#include <DHT.h>
#include "DPV.h"

#define DHTPIN   7
#define DHTTYPE  DHT22

DHT dht(DHTPIN, DHTTYPE);
DPV dpv;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println(F("Librería DPV iniciada."));
}

void loop() {
  const float t  = dht.readTemperature(); // °C
  const float h  = dht.readHumidity();    // %

  // Verificar lecturas válidas
  if (isnan(t) || isnan(h)) {
    Serial.println(F("Error: no se pudo leer el DHT22."));
    delay(2000);
    return;
  }

  const float vpd = dpv.calcularDPV(t, h); // kPa

  Serial.println(F("----------------------"));
  Serial.print(F("Temperatura: "));        Serial.print(t, 1);   Serial.println(F(" °C"));
  Serial.print(F("Humedad relativa: "));   Serial.print(h, 1);   Serial.println(F(" %"));
  Serial.print(F("DPV: "));                Serial.print(vpd, 3); Serial.println(F(" kPa"));

  delay(2000);
}