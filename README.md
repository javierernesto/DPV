# DPV — Déficit de Presión de Vapor (Arduino, FAO-56)

[![Arduino CI](https://github.com/javierernesto/DPV/actions/workflows/arduino-ci.yml/badge.svg)](https://github.com/javierernesto/DPV/actions/workflows/arduino-ci.yml)
[![Arduino Library](https://img.shields.io/badge/Arduino-Library-blue.svg)](https://www.arduino.cc/reference/en/libraries/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-1.0.0-green.svg)](https://github.com/javierernesto/DPV/releases/tag/v1.0.0)

Librería ligera para **Arduino** que calcula el **Déficit de Presión de Vapor (DPV / VPD)** a partir de temperatura y humedad relativa, usando la fórmula **FAO-56** (Magnus-Tetens, Allen et al., 1998).

Pensada para proyectos **agronómicos**: agricultura de precisión, invernaderos, riego, evapotranspiración y control ambiental.

## 🌾 ¿Qué es el DPV?

El Déficit de Presión de Vapor es la diferencia entre la presión de vapor **saturante** (`es`) y la presión de vapor **real** (`ea`):

```
DPV = es - ea
```

Es un indicador clave del **poder evaporativo del aire** y del **estrés hídrico** de los cultivos. Se expresa en **kPa**.

## 🚀 Instalación

### Arduino IDE
1. Descarga el repositorio como `.zip`.
2. `Programa → Incluir librería → Añadir librería .ZIP`.
3. Listo. Usa `#include <DPV.h>`.

### PlatformIO
```ini
lib_deps =
  https://github.com/javierernesto/DPV.git
```

## 🧠 Uso rápido

```cpp
#include <DHT.h>
#include <DPV.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature(); // °C
  float h = dht.readHumidity();    // %
  float vpd = DPV::calcularDPV(t, h);
  Serial.print("DPV: "); Serial.print(vpd, 3); Serial.println(" kPa");
  delay(2000);
}
```

## 🧩 API

Todos los métodos son **estáticos** — no hace falta instanciar la clase.

| Método | Descripción | Retorno |
|---|---|---|
| `DPV::calcularPresionVaporSaturacion(float t)` | Presión de vapor saturante (FAO-56) | `float` en **kPa** |
| `DPV::calcularDPV(float t, float hr)` | Déficit de Presión de Vapor | `float` en **kPa** (`NAN` si hay error) |

### Fórmulas (FAO-56, Allen et al., 1998)

```
es(T) = 0.6108 · exp( (17.27 · T) / (T + 237.3) )   [kPa]   (Ec. 11)
ea    = (HR / 100) · es                              [kPa]
DPV   = es - ea                                      [kPa]
```

**Rangos validados:**
- Temperatura: `-50 °C` a `60 °C`
- Humedad relativa: `0 %` a `100 %`

Fuera de rango, `calcularDPV` devuelve `NAN`.

## 📂 Ejemplos
- `examples/DHT22_DPV/` — lectura con sensor DHT22.

## 🗺️ Roadmap
- [ ] Soporte para BME280 / SHT31
- [ ] Cálculo de punto de rocío
- [ ] Variante con fórmula de Buck (1981) para comparación
- [ ] Tests unitarios con PlatformIO

## 🤝 Contribuir
Lee [`CONTRIBUTING.md`](CONTRIBUTING.md) antes de abrir una PR.

## 📜 Licencia
MIT — ver [`LICENSE`](LICENSE).

## 📚 Referencias
- Allen, R.G., Pereira, L.S., Raes, D., Smith, M. (1998). *Crop evapotranspiration — Guidelines for computing crop water requirements*. **FAO Irrigation and Drainage Paper 56**, Roma.

## ⭐ Topics sugeridos para GitHub
```
arduino, arduino-library, vpd, vapor-pressure-deficit, dpv, fao-56,
dht22, magnus-tetens, agriculture, precision-agriculture, greenhouse,
irrigation, iot, esp32, esp8266, sensors, agronomy, embedded
```
