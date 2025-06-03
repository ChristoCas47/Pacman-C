artifact identifier="github-description" type="text/markdown" title="README para Pac-Man en C">
# 🎮 Pac-Man en C (Pukku-man)
Un clon completo del clásico juego Pac-Man implementado en C para terminal, desarrollado como proyecto académico.
✨ Características

Jugabilidad clásica: Controla a Pac-Man para comer todos los puntos mientras evitas a los fantasmas
Sistema de fantasmas inteligente: 4 fantasmas únicos (Inky, Pinky, Blinky y Bob) con algoritmos de movimiento aleatorio
Superpastillas: Come las superpastillas (?) para poder eliminar temporalmente a los fantasmas
Sistema de niveles progresivos: Dos mapas diferentes que se alternan con dificultad creciente
Sistema de puntuación y récords: Guarda los mejores 7 puntajes en archivo local
Interfaz colorida: Gráficos ASCII con colores ANSI para una mejor experiencia visual
Efectos de sonido: Sonidos del sistema usando la función Beep de Windows

🎯 Sistema de Puntuación

Puntos normales (*): 10 puntos
Cerezas (+): 30 puntos
Superpastillas (?): 3000 puntos
Fantasmas eliminados: 1200 puntos cada uno

🕹️ Controles

W: Mover arriba
A: Mover izquierda
S: Mover abajo
D: Mover derecha
O: Salir del juego (elimina el puntaje actual)

🏗️ Estructura del Proyecto
├── main.c          # Archivo principal con lógica del juego
├── pacLib.c        # Funciones auxiliares (menú, puntuación, animaciones)
├── pacLib.h        # Declaraciones de funciones
├── readme.txt      # Manual de usuario en español
└── highScore.txt   # Archivo de puntajes (generado automáticamente)
🚀 Compilación y Ejecución
Requisitos

Compilador GCC
Sistema Windows (usa funciones específicas de Windows API)
Terminal con soporte para colores ANSI

Compilar
bashgcc main.c pacLib.c -o pacman.exe
Ejecutar
bash./pacman.exe
🎮 Cómo Jugar

Ejecuta el programa y selecciona "1) Para jugar"
Usa WASD para mover a Pac-Man por el laberinto
Come todos los puntos (*) y cerezas (+) para completar el nivel
Evita a los fantasmas o perderás una vida (tienes 3 vidas)
Come las superpastillas (?) para poder eliminar fantasmas temporalmente
Completa todos los niveles para ganar

👥 Desarrolladores

Alan León
Eli Domínguez
Ivan Fernández
Christofer Castañeda

📋 Estado del Desarrollo
✅ Completado al 100%

 Físicas y movimiento
 Sistema de menús
 Mapas y niveles
 Sistema de controles
 Algoritmo de fantasmas
 Sistema de vidas
 Sistema de puntuación
 Superpastillas
 Cinemáticas de victoria/derrota
 Progresión de niveles y dificultad

🔧 Características Técnicas

Lenguaje: C estándar
Plataforma: Windows (usa windows.h, conio.h)
Gráficos: ASCII art con colores ANSI
Audio: Función Beep() del sistema
Persistencia: Archivo de texto para puntajes

📝 Notas
Este proyecto fue desarrollado como ejercicio académico para demostrar conceptos de programación en C, incluyendo:

Manejo de estructuras y enumeraciones
Algoritmos de movimiento y colisiones
Gestión de archivos
Interfaz de usuario en terminal
Programación modular


Inspirado en el clásico Pac-Man de Namco. Desarrollado con fines educativos.
</artifact>
