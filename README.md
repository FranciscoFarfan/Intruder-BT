# Intruder-BT: Restauración de Camioneta RC 4x4

**Estado:** Abandonado | Sin uso de IA | Personal

## Descripción

Este proyecto de hardware y software nació del reto de revivir una antigua camioneta 4x4 RC de los años 90. Debido a que su electrónica original estaba obsoleta y resultaba imposible de reparar de forma convencional, diseñé una solución personalizada de bajo costo. Utilizando un Arduino como cerebro central, reemplacé por completo el sistema de radio control original. El proyecto consistió en programar el Arduino para actuar como receptor Bluetooth, interpretar comandos de joystick en texto plano enviados por puerto serial utilizando una aplicación móvil genérica de la Play Store y un cliente de escritorio propio programado en Java (incluido en este repositorio), y traducir estas señales en movimiento físico a través de un puente H para el motor principal y un servomotor moderno para la dirección.

Aunque el proyecto se detuvo una vez que demostró ser exitoso y adquirí equipo de RC comercial, representa un excelente ejemplo de resolución de problemas, integración de microcontroladores con electrónica de potencia y "retrofit" de hardware antiguo.

## Características

### Funcionalidades

- **Control Inalámbrico:** Manejo de la dirección y tracción de la camioneta mediante comandos de joystick y botones enviados como texto plano por Bluetooth, compatible tanto con aplicaciones genéricas de control en la Play Store como con el programa de escritorio diseñado a medida.
- **Procesamiento de Señales:** Recepción e interpretación de datos en tiempo real mediante el microcontrolador Arduino actuando como receptor RC.
- **Control de Potencia:** Gestión de la potencia y el sentido de giro del motor DC original a través de un módulo controlador de motor (Puente H).
- **Dirección Modernizada:** Adaptación e instalación de un servomotor moderno de 3 cables para la dirección, reemplazando el complejo y obsoleto sistema original de 7 cables.

### Tecnologías Usadas

- **Hardware:** Arduino (Microcontrolador principal), Módulo Bluetooth, Controlador de Motor Puente H, Servomotor.
- **Software/Lenguajes:** C / C++ (Arduino IDE) para el firmware, y Java para el desarrollo del cliente de escritorio de control remoto (código disponible en el repositorio).
- **Electrónica:** Diseño de circuitos básicos para control de motores y lógica de señales.

### Innovaciones

- **Retrofit Tecnológico:** Revitalización de hardware mecánico de los años 90 integrando electrónica moderna y asequible, demostrando capacidad para adaptar componentes de distintas épocas.
- **Desarrollo de Receptor Custom:** Creación de toda la lógica de recepción y actuación desde cero en lugar de utilizar soluciones "Plug and Play", evidenciando un entendimiento de la comunicación inalámbrica y el control de motores.
- **Ingeniería con Recursos Limitados:** Solución creativa y funcional desarrollada con bajo presupuesto para resolver un problema técnico de hardware (electrónica original insalvable).

## Fotos
