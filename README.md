# **Cub3D**

Este proyecto, **Cub3D**, representa la primera incursión en la programación de gráficos en la escuela **42**. El objetivo es crear un motor de videojuegos en 3D muy básico utilizando el algoritmo de trazado de rayos **DDA (Digital Differential Analyzer)** para renderizar un laberinto desde una perspectiva en primera persona. Inspirado en los gráficos retro de clásicos como **Wolfenstein 3D**, este proyecto demuestra un conocimiento sólido de geometría, matemáticas aplicadas a la computación gráfica y gestión de la ventana de visualización.

---

## **✅ Habilidades y Funcionalidades Principales**

La finalización de Cub3D demuestra la capacidad para implementar un sistema gráfico desde cero, integrando las siguientes características clave:

* **Motor de Trazado de Rayos con Algoritmo DDA**: Implementación del **algoritmo DDA** para calcular eficientemente las colisiones con las paredes. Este enfoque matemático es la base para la proyección 3D del entorno 2D del laberinto.
* **Proyección y Renderizado 3D**: Capacidad para transformar un mapa 2D en una vista en primera persona, creando la ilusión de profundidad.
* **Gestión de Movimiento y Colisiones**: Implementación de controles del jugador (**movimiento y rotación**) y una robusta detección de **colisiones** para evitar que el jugador atraviese las paredes.
* **Manejo de Texturas**: Aplicación de **texturas** en las paredes para dar vida al entorno, requiriendo un cálculo preciso de las coordenadas de la textura en el momento del renderizado.
* **Manejo de Ventana y Eventos**: Uso de la librería **MiniLibX** para crear y gestionar la ventana de visualización, así como para manejar los eventos de teclado para el control del jugador.

---

## **💡 Características Bonus Implementadas**

Se han incorporado funcionalidades adicionales que elevan la calidad del proyecto y demuestran una comprensión más profunda de la programación gráfica.

* **Sprites**: Renderizado de objetos dinámicos (**sprites**) en el mapa, que se visualizan correctamente desde cualquier ángulo del jugador, demostrando un manejo avanzado de la proyección y el renderizado.
* **Minimapa**: Inclusión de un **minimapa** en tiempo real que muestra la posición del jugador y la estructura del laberinto.
* **Texturas para el Suelo y el Techo**: En lugar de simples colores, se han aplicado **texturas al suelo y al techo** para mejorar la inmersión visual.

---

## **🛠️ Tecnologías y Habilidades Aplicadas**

* **Lenguaje de Programación**: El proyecto fue desarrollado íntegramente en **Lenguaje C**, lo que demuestra un sólido dominio de la programación a bajo nivel, la gestión manual de memoria y el uso de librerías.
* **Fundamentos Matemáticos**: Aplicación de conceptos de **trigonometría y álgebra lineal** para el trazado de rayos, la rotación de la cámara y la proyección 3D.
* **Calidad y Estándares de Código**: Adherencia estricta a la normativa de codificación **Norminette** de 42, lo que asegura un código limpio, legible y fácil de mantener.

---

## **🏆 ¿Qué demuestra la finalización de este proyecto?**

Completar Cub3D es una prueba tangible de las siguientes competencias:

* **Resolución de Problemas Complejos**: Habilidad para analizar y resolver problemas matemáticos y de lógica para la creación de gráficos 3D.
* **Pensamiento Algorítmico**: Comprensión y aplicación de algoritmos como el **DDA** y otros de geometría computacional.
* **Programación Rigurosa**: Capacidad para escribir código eficiente en un lenguaje de bajo nivel como **C**, optimizando el rendimiento para la representación gráfica.

---

## **Video demostracion**

![Cub3D Demo](./Video/Cub3dVideo.gif)
