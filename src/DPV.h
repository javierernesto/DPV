/**
 * @file    DPV.h
 * @brief   Cálculo del Déficit de Presión de Vapor (DPV/VPD) para Arduino.
 * @details Implementa la fórmula de Magnus-Tetens para estimar la presión
 *          de vapor saturante (es) y, a partir de ella, el DPV.
 *
 * @author  Tu Nombre <tu@email.com>
 * @version 1.0.0
 * @date    2026
 * @license MIT
 */

#ifndef DPV_H
#define DPV_H

#include <Arduino.h>

/**
 * @class DPV
 * @brief Calcula el Déficit de Presión de Vapor a partir de T y HR.
 *
 * Unidades utilizadas:
 *  - Temperatura: grados Celsius (°C)
 *  - Humedad relativa: porcentaje (0–100 %)
 *  - Presión: kilopascales (kPa)
 */
class DPV {
public:
  /**
   * @brief Constructor por defecto.
   */
  DPV();

  /**
   * @brief Calcula la presión de vapor saturante (es) según Magnus-Tetens.
   *
   * Fórmula:
   *   es(T) = 0.6108 * exp( (17.27 * T) / (T + 237.3) )   [kPa]
   *
   * @param temperatura Temperatura del aire en °C.
   * @return Presión de vapor saturante en kPa.
   */
  float calcularPresionVaporSaturacion(float temperatura) const;

  /**
   * @brief Calcula el Déficit de Presión de Vapor (DPV/VPD).
   *
   * DPV = es(T) - ea, donde ea = (HR/100) * es(T).
   *
   * @param temperatura      Temperatura del aire en °C.
   * @param humedadRelativa  Humedad relativa en % (rango válido: 0–100).
   * @return DPV en kPa. Devuelve NAN si los argumentos están fuera de rango.
   */
  float calcularDPV(float temperatura, float humedadRelativa) const;
};

#endif // DPV_H