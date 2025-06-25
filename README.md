[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Pokémon Battle]

## Descripción del Proyecto
Este proyecto consiste en un **juego de batalla por turnos basado en el universo Pokémon**, donde dos jugadores locales compiten eligiendo cada uno un Pokémon con habilidades únicas. El juego se desarrolla completamente en consola usando C++, y hace uso de estructuras y funciones para organizar la lógica, junto con estructuras de control (`if`, `switch`, `while`, `do-while`, `for`) y operaciones para calcular daños, turnos y condiciones de victoria.

## Equipo

- **Nombre del equipo:** [Syntax Error]

### Integrantes del equipo

1. **Nombre completo:** [Alejandro Antonio Méndez Marenco]  
   **Carnet:** [00085425]

2. **Nombre completo:** [Gabriela Michelle Navas Quinteros]  
   **Carnet:** [00167525]

3. **Nombre completo:** [Evelyn Michelle Miranda Acuña]  
   **Carnet:** [00019425]

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [https://github.com/FDP-01-2025/project-syntax-error](https://github.com/FDP-01-2025/project-syntax-error)
   cd project-syntax-error/
   code .

2. Compila el proyecto desde consola:
   ```bash
   g++ main.cpp -o main
   .\\main

## Temática y Ambientación

El juego se sitúa en el mundo Pokémon, en un ambiente de duelo entre entrenadores. La ambientación del juego está diseñada para trasladar al jugador a un escenario que recuerda a los combates pokémon, incorporando elementos visuales como ASCII, colores personalizados en consola y efectos de texto que simulan animaciones retro. Al mismo tiempo que mantienen una estructura accesible y funcional desde el punto de vista técnico.


## Mecánica Principal

- Juego por turnos entre los jugadores.
- Elección de Pokémon con características únicas.
- Ataques con diferentes efectos y probabilidades.
- Sistema de combate influenciado por la velocidad del Pokémon.
- Ganador de rondas: el jugador cuyo Pokémon quede con vida al final del combate.
- Ganador de partidas: el jugador que haya ganado 3 rondas.

## Idea General de la Jugabilidad

1. Pantalla de bienvenida preguntando modo de juego.
2. Menú de selección para elegir Pokémon.
3. Muestra de estadísticas.
4. Inicio del combate:
   - Turno por jugador, seleccionando ataque.
   - Se determina el orden por velocidad.
   - Se aplican daños y se actualiza el HP.
5. Finaliza cuando uno de los Pokémon es derrotado.
6. Se muestra un mensaje de victoria.

## Aplicación de los Temas Vistos en Clase

A continuación se detallan todos los temas vistos en clase y cómo fueron aplicados en el desarrollo del proyecto Pokémon Battle:

- **Variables y Tipos de Datos**  
  Se usaron variables para almacenar información como puntos de vida (HP), nombres de Pokémon y ataques, valores numéricos para daños y velocidades, y estados del juego. Se utilizaron tipos básicos como `int`, `float` y `string` entre otros para manejar estos datos.

- **Estructuras Condicionales (`if`, `else`, `switch`)**  
  Se implementaron para tomar decisiones durante la ejecución del juego, como:
  - Verificar qué jugador ataca primero comparando velocidades.
  - Determinar si un Pokémon fue derrotado (HP ≤ 0).
  - Procesar las elecciones del jugador en menús con `switch` para las opciones disponibles.

- **Ciclos (`for`, `while`, `do while`)**  
  - `for`: para recorrer y mostrar listas de Pokémon y ataques en menús.  
  - `while`: para mantener activo el ciclo de combate mientras ambos Pokémon tengan HP > 0.  
  - `do while`: para asegurar que el usuario seleccione opciones válidas en los menús antes de continuar.

- **Funciones**  
  El código se divide en funciones que realizan tareas específicas, como:
  - Mostrar menús.
  - Seleccionar Pokémon y ataques.
  - Calcular daño y actualizar HP.
  - Imprimir mensajes con efectos visuales.
  
  Esto facilita la reutilización y mejora la organización.

- **Estructuras de Datos**  
  Se usaron:
  - **Estructuras (`struct`)** para definir los datos de Pokémon, ataques y tipos.

- **Manejo de Archivos**  
  Para guardar o cargar datos del juego, como estadísticas o resultados.

- **Manejo de Errores**  
  Se incluyeron validaciones para evitar entradas inválidas del usuario, como seleccionar opciones fuera del rango permitido o caracteres no reconocidos. Se manejan mediante bucles que solicitan nuevamente la entrada hasta que es correcta.

- **Interfaz Básica (Consola)**  
  El juego usa la consola para interacción:
  - Entrada con `cin` y `getch()` para lectura de teclas.
  - Salida con `cout` para mostrar información.
  - Uso de colores y posicionamiento del cursor con funciones de `<windows.h>` para mejorar la experiencia visual.

## Consideraciones Técnicas

- Desarrollado en C++
- Uso de consola de Windows 
- Estructura de carpetas:




