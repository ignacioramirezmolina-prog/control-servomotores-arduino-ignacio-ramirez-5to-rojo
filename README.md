# Control de Servomotores con Arduino

**Fecha:** 29 de Octubre de 2026  
**Entorno de simulación:** Tinkercad Circuits  

---

## 📌 Descripción del Proyecto

Este proyecto consiste en el diseño, simulación y programación de un sistema basado en **Arduino** para controlar **3 servomotores** mediante diferentes actuadores y algoritmos independientes.

---

## ⚙️ Funcionamiento de los Servomotores

1. **Servomotor 1 (Activado por Pulsador):**
   - Al mantener presionado el pulsador, el servomotor gira a una posición de **90°**.
   - Al soltarlo, regresa automáticamente a la posición de **0°**.

2. **Servomotor 2 (Activado por Switch Deslizante):**
   - Según la posición del switch deslizante, el servomotor cambia de estado entre dos posiciones fijas: **0°** y **180°**.

3. **Servomotor 3 (Actuación Independiente / Barrido Automático):**
   - Realiza un barrido angular dinámico y continuo de **0° a 180° y retorno**.
   - Está programado mediante la función `millis()` (sin bloquear el hilo de ejecución), permitiendo que funcione de forma autónoma sin interferir con la respuesta de los otros actuadores.

---

## 🛠️ Componentes Utilizados

- 1x Arduino Uno R3
- 3x Servomotores Micro SG90
- 1x Pulsador (Push Button)
- 1x Switch Deslizante (Slide Switch)
- 1x Fuente de Alimentación Externa (5V para servomotores)
- Protoboard y Cables de conexión

---

## 🔌 Diagrama de Conexiones

| Componente | Pin del Componente | Conexión Arduino / Fuente |
| :--- | :--- | :--- |
| **Servomotor 1** | Señal (Naranja) | Pin Digital 9 |
| **Servomotor 2** | Señal (Naranja) | Pin Digital 10 |
| **Servomotor 3** | Señal (Naranja) | Pin Digital 11 |
| **Pulsador** | Terminal 1A / 2A | Pin Digital 2 / GND |
| **Switch Deslizante** | Terminal Central / Lateral | Pin Digital 3 / 5V (o GND) |
| **Alimentación Servos** | VCC / GND (Rojo/Marrón) | Fuente Externa 5V / GND Compartido |

> **Nota de Seguridad:** Se recomienda alimentar los servomotores con una fuente externa de 5V conectando la tierra (GND) de la fuente al GND del Arduino para evitar sobrecargas de corriente en la placa.
