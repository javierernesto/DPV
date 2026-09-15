# Guía de contribución

¡Gracias por querer aportar a **DPV**! 🌱

## Cómo reportar un bug
1. Verifica que no exista ya un issue abierto.
2. Usa la plantilla de *bug report*.
3. Incluye: placa, versión del IDE/PlatformIO, código mínimo reproducible y salida esperada vs obtenida.

## Cómo proponer una mejora
1. Abre un issue con la plantilla *feature request*.
2. Explica el caso de uso agronómico/ambiental.
3. Si es una fórmula, cita la fuente (paper, FAO, etc.).

## Pull Requests
- Rama desde `main`: `git checkout -b feat/mi-mejora`.
- Sigue el estilo del código existente (Doxygen en comentarios, sufijo `f` para floats, `expf` en lugar de `exp`).
- Un commit por cambio lógico. Mensajes en modo imperativo (`Añade soporte BME280`).
- Actualiza `CHANGELOG.md` en la sección `[Unreleased]`.
- Ejecuta el ejemplo `DHT22_DPV` en al menos un Arduino real o simulador antes de subir.

## Estilo
- C++11 compatible (Arduino IDE 1.8+).
- 2 espacios de indentación.
- Todo comentario y documentación en **español**.
- Nombres de variables y funciones en **español** (coherencia con el dominio).

## Licencia
Al contribuir aceptas que tu código se publique bajo la licencia **MIT** del proyecto.