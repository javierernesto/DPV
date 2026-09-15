# Changelog

Todas las modificaciones notables de este proyecto se documentan aquí.
Formato basado en [Keep a Changelog](https://keepachangelog.com/es-ES/1.1.0/).
Versionado según [SemVer](https://semver.org/lang/es/).

## [Unreleased]

## [1.0.0] - 2026-09-15
### Añadido
- Cálculo de presión de vapor saturante (FAO-56, Ec. 11).
- Cálculo del Déficit de Presión de Vapor (DPV/VPD) en kPa.
- Validación de rangos de temperatura y humedad relativa.
- API estática (`DPV::calcularDPV`).
- Ejemplo con sensor DHT22.
- Soporte para el Arduino Library Manager (`library.properties`).
