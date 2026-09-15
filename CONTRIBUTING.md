# Guía de contribución

¡Gracias por querer aportar a **DPV**! 🌱

Antes de participar, por favor leé nuestro
[`CODE_OF_CONDUCT.md`](CODE_OF_CONDUCT.md). Aplica a todas las
interacciones del proyecto (issues, PRs, discusiones).

## 🗂️ Estructura del repositorio

## 🐛 Cómo reportar un bug
1. Verificá que no exista ya un issue abierto.
2. Usá la plantilla de *bug report*.
3. Incluí: placa, versión del IDE/PlatformIO, código mínimo reproducible y salida esperada vs obtenida.

## ✨ Cómo proponer una mejora
1. Abrí un issue con la plantilla *feature request*.
2. Explicá el caso de uso agronómico/ambiental.
3. Si es una fórmula, citá la fuente (paper, FAO, etc.).

## 🔧 Pull Requests
- Rama desde `main`: `git checkout -b feat/mi-mejora`.
- Seguí el estilo del código existente (Doxygen en comentarios, sufijo `f` para floats, `expf` en lugar de `exp`).
- Un commit por cambio lógico. Mensajes en modo imperativo (`Añade soporte BME280`).
- Actualizá `CHANGELOG.md` en la sección `[Unreleased]`.
- Ejecutá el ejemplo `DHT22_DPV` en al menos un Arduino real o simulador antes de subir.

## 🎨 Estilo
- C++11 compatible (Arduino IDE 1.8+).
- 2 espacios de indentación.
- Todo comentario y documentación en **español**.
- Nombres de variables y funciones en **español** (coherencia con el dominio).
- Sufijo `f` en literales float (`0.6108f`, no `0.6108`).
- Funciones matemáticas específicas para `float` (`expf`, `sqrtf`, etc.).

## 📜 Licencia
Al contribuir aceptás que tu código se publique bajo la licencia **MIT** del proyecto.
