# DPV — Déficit de Presión de Vapor para Arduino

[![Arduino Library](https://img.shields.io/badge/Arduino-Library-blue.svg)](https://www.arduino.cc/reference/en/libraries/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-1.0.0-green.svg)]()

Librería ligera para **Arduino** que calcula el **Déficit de Presión de Vapor (DPV / VPD)** a partir de la temperatura y la humedad relativa, usando la fórmula de **Magnus-Tetens**.

## 📖 ¿Qué es el DPV?

El Déficit de Presión de Vapor (VPD, por sus siglas en inglés) es la diferencia entre la presión de vapor saturante (`es`) y la presión de vapor real (`ea`). Es un indicador clave en:

- 🌱 Agricultura de precisión e invernaderos
- 🌦️ Meteorología y evapotranspiración
- 🏠 Control ambiental

Unidades: **kPa** (kilopascales).

## 🚀 Instalación

### Arduino IDE
1. Descarga el repositorio como `.zip`.
2. En el IDE: `Programa → Incluir librería → Añadir librería .ZIP`.
3. Listo. Ya puedes hacer `#include <DPV.h>`.

### PlatformIO
Añade al `platformio.ini`:
```ini
lib_deps =
  https://github.com/tu-usuario/DPV.git
```

## 🧠 Uso rápido

```cpp
#include <DHT.h>
#include <DPV.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
DPV dpv;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature(); // °C
  float h = dht.readHumidity();    // %
  float vpd = dpv.calcularDPV(t, h);
  Serial.print("DPV: "); Serial.print(vpd, 3); Serial.println(" kPa");
  delay(2000);
}
```

## 🧩 API

| Método | Descripción | Retorno |
|---|---|---|
| `DPV()` | Constructor | — |
| `calcularPresionVaporSaturacion(float t)` | Presión de vapor saturante (Magnus-Tetens) | `float` en **kPa** |
| `calcularDPV(float t, float hr)` | Déficit de presión de vapor | `float` en **kPa** (`NAN` si hay error) |

### Fórmulas
```
es(T) = 0.6108 · exp( (17.27 · T) / (T + 237.3) )   [kPa]
ea    = (HR / 100) · es                              [kPa]
DPV   = es - ea                                      [kPa]
```

## 📂 Ejemplos
En `examples/DHT22_DPV/` encontrarás un sketch completo con sensor DHT22.

## 🗺️ Roadmap
- [ ] Soporte para BME280
- [ ] Cálculo de punto de rocío
- [ ] Método con fórmula de Buck (mayor precisión)
- [ ] Tests unitarios con PlatformIO

## 🤝 Contribuir
¡Las PRs son bienvenidas! Lee [`CONTRIBUTING.md`](CONTRIBUTING.md) antes.

## 📜 Licencia
MIT — ver [`LICENSE`](LICENSE).

## 🏷️ Keywords / Topics para GitHub

Copia estos `topics` en la configuración del repo:

```
arduino, arduino-library, vpd, vapor-pressure-deficit, dpv, dht22,
magnus-tetens, agriculture, greenhouse, iot, esp32, esp8266,
sensors, meteorology, embedded
```

## ⭐ Créditos
Fórmula basada en Allen et al. (1998) — *FAO Irrigation and Drainage Paper 56*.