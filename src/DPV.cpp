/**
 * @file    DPV.cpp
 * @brief   Implementación de la clase DPV.
 */

#include "DPV.h"

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------
DPV::DPV() {}

// -----------------------------------------------------------------------------
// Presión de vapor saturante (Magnus-Tetens)
// -----------------------------------------------------------------------------
float DPV::calcularPresionVaporSaturacion(float temperatura) const {
  // La fórmula ya asume T en °C; no se necesita Kelvin.
  return 0.6108f * expf((17.27f * temperatura) / (temperatura + 237.3f));
}

// -----------------------------------------------------------------------------
// Déficit de Presión de Vapor
// -----------------------------------------------------------------------------
float DPV::calcularDPV(float temperatura, float humedadRelativa) const {
  // Validación básica de rangos físicos.
  if (humedadRelativa < 0.0f || humedadRelativa > 100.0f) {
    return NAN; // Humedad fuera de rango.
  }
  if (temperatura < -50.0f || temperatura > 60.0f) {
    return NAN; // Temperatura fuera de rango razonable.
  }

  const float es = calcularPresionVaporSaturacion(temperatura); // kPa
  const float ea = (humedadRelativa / 100.0f) * es;             // kPa
  return es - ea;                                               // kPa
}