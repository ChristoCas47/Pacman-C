/**
PAC-MAN EN C


Nombre clave: Pukku-man (en referencia al nombre original del juego)

Por:
Alan Leo-n
Eli  Dominguez
Ivan Fernandez
Christofer Castanieda


Progreso de desarrollo:

100%  [#########################]

- Fisicas listas
- Menu
- Mapa
- Controles listos
- Sistema de fantasmas
- Vidas
- Sistema de puntos listo
- Algoritmo de fantasmas listo
- Superpastilla casi lista (falta implementarla en el codigo principal)
- "Cinematicas" al ganar, perder y perder una vida.
- Superpastilla
- Repeticion de niveles y aumento de dificultad

*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pacLib.h"
#include <unistd.h>

/**

COLOR CODE:

\x1B[38;2;R;G;Bm  s  -   Rojo cereza



*/


//SCORE_LIMIT es el limite de cuantos puntajes se guardaran
//HEIGHT es lo alto del mapa
//WIDTH es lo largo del mapa

#define HEIGHT 25
#define WIDTH 46
#define SCORE_LIMIT 7

// Enumeracion de los valores de direccion

enum Move {UP,DOWN,LEFT,RIGHT};

// Estructura de los objetos movibles

struct Movable{

    enum Move direc;
    int X;
    int Y;

};

/**

Funcion de reinicio de fantasma

*/

void ghostKill(struct Movable *ghost, int *puntos){

    ghost->X = 17;
    ghost->Y = 7;
    *puntos += 1200;

}





// Funcion de la pantalla de puntajes. Se importa el arreglo con los puntajes.

void highScores(int scores[]){

system("cls");

    printf("\t\033[0;34m|\033[0m\033[1;33m   :::::::::     :::      ::::::::  ::::    ::::      :::     ::::    :::\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   :+:    :+:  :+: :+:   :+:    :+: +:+:+: :+:+:+   :+: :+:   :+:+:   :+:\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   +:+    +:+ +:+   +:+  +:+        +:+ +:+:+ +:+  +:+   +:+  :+:+:+  +:+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   +#++:++#+ +#++:++#++: +#+        +#+  +:+  +#+ +#++:++#++: +#+ +:+ +#+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   +#+       +#+     +#+ +#+        +#+       +#+ +#+     +#+ +#+  +#+#+#\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   #+#       #+#     #+# #+#    #+# #+#       #+# #+#     #+# #+#   #+#+#\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   ###       ###     ###  ########  ###       ### ###     ### ###    ####\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");
    printf("\t\033[0;34m|\t\t\t\t\t\t\t\t\t\t\t  |\033[0m\n");
    printf("\t\033[0;34m|\t\t\t\t\t\t\t\t\t\t\t  |\033[0m\n");

    printf("\033[0;34m\t|__________________________|\t\t      |___________________________________________|\n\033[0;0m");


puts("\t\t\t\t- Mejores puntajes -");
puts("");
puts("");
puts("");

// Se imprimen los puntajes.

for(int i = 0; i < SCORE_LIMIT; i++){

    printf("\t\t\t\t%d -> %d\n\n",i+1, scores[i]);


}

puts("");
puts("");
puts("");

puts("Presiona cualquier tecla para salir");

getch();

fflush(stdin);


}




int Menu(int score){

    /*

    Funcion del menu
    Se imprime el menu, y se regresa el input
    El input determina si se cierra el juego o si se empieza la partida
    Se importa el puntaje mas alto.

    */

    char press = 'a';

    while(1){
    system("cls");


    puts("");
    // printf("\033[0;34m\t__________________________________________________________________________________________\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   :::::::::     :::      ::::::::  ::::    ::::      :::     ::::    :::\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   :+:    :+:  :+: :+:   :+:    :+: +:+:+: :+:+:+   :+: :+:   :+:+:   :+:\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   +:+    +:+ +:+   +:+  +:+        +:+ +:+:+ +:+  +:+   +:+  :+:+:+  +:+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   +#++:++#+ +#++:++#++: +#+        +#+  +:+  +#+ +#++:++#++: +#+ +:+ +#+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   +#+       +#+     +#+ +#+        +#+       +#+ +#+     +#+ +#+  +#+#+#\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   #+#       #+#     #+# #+#    #+# #+#       #+# #+#     #+# #+#   #+#+#\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
    printf("\t\033[0;34m|\033[0m\033[1;33m   ###       ###     ###  ########  ###       ### ###     ### ###    ####\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");
    printf("\t\033[0;34m|\t\t\t\t\t\t\t\t\t\t\t  |\033[0m\n");
    printf("\t\033[0;34m|\t\t\t\t\t\t\t\t\t\t\t  |\033[0m\n");

    printf("\033[0;34m\t|__________________________|\t\t      |___________________________________________|\n\033[0;0m");
    printf("\t\t\033[1;31m     ,---.\033[0m \033[1;33m   ,--. \033[0m \t\t      \033[0;36m  ,--. \033[0m\033[0;32m  ,--.  \033[0m                              \n");
    printf("\t\t\033[1;31m    |oo  |\033[0m \033[1;33m_  \\   ;\033[0m\t\t     \033[0;36m  | oo |\033[0m\033[0;32m |  oo| \033[0m                              \n");
    printf("\t\t\033[1;33mo  o\033[0m\033[1;31m|~~  |\033[0m\033[1;33m(_) /   ;\033[0m\t\t      \033[0;36m | ~~ |\033[0m\033[0;32m |  ~~|\033[0mo\033[1;33m  o  o  o  o  o  o  o  o  o  o\033[0m\n");
    printf("\t\t  \033[1;31m  |/\\/\\|\033[0m\033[1;33m   '._,'\033[0m \t\t    \033[0;36m   |/\\/\\|\033[0m\033[0;32m |/\\/\\|\033[0m                               \n\033[0m");
    printf("\033[0;34m\t____________________________ \t\t       ____________________________________________\n");

    printf("\t|\t\t\t\t\t\t\t\t\t\t\t   |\n");
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t   |\n");





    /**
     * Codigos de color:
     * AMARILLO \033[1;33m
     * NORMAL \033[0m
     * ROJO \033[1;31m\
     * AZUL \033[0;34m
     *
     * El 1 y 0 representan el formato de texto (0, normal y 1, negritas)
     *
    */


    printf("\t|\033[1;31m\033[1;1m\t\t---------------  Puntuacion Maxima: %d  ---------------\033[1;0m\033[0;34m\t\t   |\n", score);
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t   |\n");
    printf("\t|\t \033[0;37m\t\t\t1) Para jugar\033[1;0m\033[0;34m\t\t\t\t\t\t   |\033[0;0m\n");
    printf("\t\t\t\t\t2) Para ver los mejores puntajes\n");
    printf("\t\t\t\t\t3) Para salir\n\033[0;0m");
    puts("");
    puts("");
    puts("");
    printf("\t\tw: arriba\ts: abajo\ta: izquierda\td: derecha\n\033[0;0m");
    puts("");
    puts("");

    press = getch();


    if(press == '1'){
        break;
    }
    if(press == '2'){
        break;
    }

    if(press == '3'){
        break;
    }

    fflush(stdin);

    }

    return press;

}




/**
 * Funcion de movimiento de objetos.
 *
 * Se revisa la direccion y se cambia las coordenadas.
 *
 * Parametros:
 *
 * struct Movable *pukku    --  Apuntador del objeto a mover
 * char map[HEIGHT][WIDTH]  --  Mapa
 * int flag                 --  Flag que indica si se va a mover un fantasma o a pacman
 *
 * Si flag = 1, entonces se activa el algoritmo del fantasma
 * el cual hace que cuando se encuentra una interseccion
 * este eliga si cambia de direccion o no.
 *
 *
*/




void movingPukku(struct Movable *pukku, char map[HEIGHT][WIDTH], int flag){

  switch (pukku->direc)
      {
      // w
      case UP:
        if(map[pukku->Y -1][pukku->X] != '#')
          pukku->Y -= 1;

          if(map[pukku->Y -1][pukku->X] != '#')
          pukku->direc = UP;
        else if(map[pukku->Y +1][pukku->X] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = DOWN;
        if(map[pukku->Y][pukku-> X+1] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = RIGHT;
        if(map[pukku->Y][pukku->X -1] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = LEFT;



        break;

      // s
      case DOWN:
        if(map[pukku->Y +1][pukku->X] != '#')
          pukku->Y += 1;

          if(map[pukku->Y +1][pukku->X ] != '#')
          pukku->direc = DOWN;
        else if(map[pukku->Y -1][pukku->X] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = UP;
        if(map[pukku->Y][pukku-> X+1] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = RIGHT;
        if(map[pukku->Y][pukku->X -1] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = LEFT;



        break;

      // a
      case LEFT:
        if(map[pukku->Y][pukku->X -1] != '#')
          pukku->X -= 1;

          if(map[pukku->Y][pukku->X -1] != '#')
          pukku->direc = LEFT;
         else if(map[pukku->Y][pukku-> X+1] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = RIGHT;
        if(map[pukku->Y +1][pukku->X] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = DOWN;
        if(map[pukku->Y -1][pukku->X] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = UP;



        break;

      //d
      case RIGHT:
        if(map[pukku->Y][pukku-> X+1] != '#')
          pukku-> X += 1;

         if(map[pukku->Y][pukku->X +1] != '#')
          pukku->direc = RIGHT;
        else if(map[pukku->Y][pukku->X -1] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = LEFT;
        if(map[pukku->Y +1][pukku->X] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = DOWN;
        if(map[pukku->Y -1][pukku->X] != '#' && rand() % 2 == 1 && (flag))
          pukku->direc = UP;



        break;

      default:
        break;
      }



}







/**
 *
 * Funcion del juego.
 *
 * Se declaran los enemigos, sus coordenadas y direccion inicial.
 * Se dibuja el mapa
 *
 * Toma como parametros: El jugador, el mapa y el puntaje mas alto
 *
*/

void game(struct Movable pukku, char map[HEIGHT][WIDTH], char map2[HEIGHT][WIDTH], int high){

    int ghostCount = 0;
    int frameTime = 180;
    struct Movable inky;
    struct Movable blinky;
    struct Movable pinky;
    struct Movable bob;
    char copy[HEIGHT][WIDTH];
    char copy2[HEIGHT][WIDTH];
    int vidas = 3;
    int level = 0;


    int puntos=0;
    int win = 0;

            for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                copy[i][j] = map[i][j];

            }
        }

            for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                copy2[i][j] = map2[i][j];

            }
        }




RESTART:
srand(time(NULL));
     //   vidas++;
        level++;
        frameTime -= 10;
    if((level +1)% 2 == 0){
    for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                map[i][j] = copy[i][j] ;

            }
        }

    }
    else{
    for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                map[i][j] = copy2[i][j] ;

            }
        }
    }



    // Ciclo para la creacion de puntos en el mapa
     for (int i = 0; i < HEIGHT; i++) {

        for (int j = 0; j < WIDTH; j++) {

            if (map[i][j] == ' ') {

                    map[i][j] = '*';

            }

        }

    }

    //  Ciclo para la creacion de frutos en partes aleatorias del mapa


     for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch (map[i][j]){
        case ' ':
            if (0) {
                    map[i][j] = '+';
                }
                break;
        case '*':
            if (rand() % 50 == 0) {
                    map[i][j] = '+';
                }
                break;
        default:
            break;
            }
        }
    }

int kill = 4;

//LABEL para poder reiniciar las posiciones iniciales al morir

LIFELOSS:

    kill--;

    ghostCount = 0 + 60 * (3 - kill);

// Posicion inicial de objetos

    pukku.X = 1;
    pukku.Y = 1;
    inky.X = 17;
    inky.Y = 7;
    pinky.X = 17;
    pinky.Y = 7;
    blinky.X = 17;
    blinky.Y = 7;
    bob.X = 17;
    bob.Y = 7;

//Variable que anima a pacman
    int waka = 1;

//Direccion inicial de objetos

    pukku.direc = UP;
    inky.direc = UP;
    pinky.direc = UP;
    blinky.direc = UP;
    bob.direc = UP;

//Variable de activacion de la superpastilla

    int contSuperPastillas=0;






//Ciclo principal del juego. Por el momento solo se sale si Pacman muere o se preciona 'o'

    while(pukku.direc != 4){


      system("cls");

      //Variable que indica si ya se gano

      win = 0;


      //detecta boton presionado

      if(_kbhit()){
      //Esta variable cambia la direccion
      //PukkuMove regresa un valor del "enum Move"
          pukku.direc = PukkuMove(map[pukku.Y-1][pukku.X],map[pukku.Y+1][pukku.X],map[pukku.Y][pukku.X-1],map[pukku.Y][pukku.X+1],pukku.direc);

          fflush(stdin);
      }


      // Este condicional detecta si pacman choco con un fantasma despues de moverse
      // y despues de que se muevan los fantasmas

      movingPukku(&pukku, map, 0);

      if(pukku.X == inky.X && pukku.Y == inky.Y){

      //Si el contador de la superpastilla esta activo
      //Se ejecuta la funcion de matar un fantasma
      //Si no, se ejecuta la funcion de muerte de PACMAN
        if(contSuperPastillas )
            ghostKill(&inky, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }

        }
              if(pukku.X == pinky.X && pukku.Y == pinky.Y){

        if(contSuperPastillas )
            ghostKill(&pinky, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }
        }
              if(pukku.X == blinky.X && pukku.Y == blinky.Y){
        if(contSuperPastillas )
            ghostKill(&blinky, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }
        }
              if(pukku.X == bob.X && pukku.Y == bob.Y){
        if(contSuperPastillas )
            ghostKill(&bob, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }
        }

        // Estos condicionales hacen que los fantasmas empiecen a moverse
        // Despues de un cierto tiempo y no al inicio
        // El modulo hace que se ralentizen al usar una SUPERPASTILLA

        if(contSuperPastillas % 2 == 0 )
            movingPukku(&inky, map, 1);
        if(ghostCount > 59 && (contSuperPastillas % 2 == 0 ))
            movingPukku(&pinky, map, 1);
        if(ghostCount > 119 && (contSuperPastillas % 2 == 0 ))
            movingPukku(&blinky, map, 1);
        if(ghostCount > 159 && (contSuperPastillas % 2 == 0 ))
            movingPukku(&bob, map, 1);

      if(pukku.X == inky.X && pukku.Y == inky.Y){

        if(contSuperPastillas)
            ghostKill(&inky, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }

        }
              if(pukku.X == pinky.X && pukku.Y == pinky.Y){
        if(contSuperPastillas)
            ghostKill(&pinky, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }
        }
              if(pukku.X == blinky.X && pukku.Y == blinky.Y){
        if(contSuperPastillas)
            ghostKill(&blinky, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }
        }
              if(pukku.X == bob.X && pukku.Y == bob.Y){
        if(contSuperPastillas)
            ghostKill(&bob, &puntos);

        else{

        vidas-= 1;
        dead();
        break;

        }
        }


        // Detecta si hay un punto, si hay agrega puntos al contador y cambia por un espacio vacio
        // se puede agregar el sistema de fantasmas y la colicion aqui


    switch (map[pukku.Y][pukku.X]){

        case '*':
            map[pukku.Y][pukku.X] = ' ';
            puntos=puntos+10;
            break;

        case '+':
            map[pukku.Y][pukku.X] = ' ';
            puntos=puntos+30;
            break;

        case '?':
            map[pukku.Y][pukku.X] = ' ';
            puntos=puntos+3000;
            contSuperPastillas=45;

            break;

        default:
            break;
        }



        if (contSuperPastillas>0){
            printf("Superpastilla: %d\t",contSuperPastillas);
            contSuperPastillas=contSuperPastillas-1;
        }
            printf("Nivel %d\n", level);

            printf("Vidas: %d\tScore: %d\tHighScore: %d",vidas ,puntos, high);

            puts("");

            puts("Presione 'o' para salir");
            puts("");



      //DISPLAY

      //Se imprime el mapa con un for

      for(int filas = 0; filas < HEIGHT; filas++){

        for(int colum = 0; colum < WIDTH; colum++){

            if(map[filas][colum] == '*' ){


            win = 1;

            }
            if(map[filas][colum] == '+' ){



            win = 1;

            }


            // Impresion de fantasmas
            if(colum == inky.X && filas == inky.Y){
                if(contSuperPastillas )
                    printf("\x1B[38;2;15;12;255mn\033[0m");
                else
                    printf("\033[1;31mn\033[0m");
                  continue;

            }
            if(colum == pinky.X && filas == pinky.Y){
                if(contSuperPastillas )
                    printf("\x1B[38;2;15;12;255mn\033[0m");
                else
                  printf("\033[1;35mn\033[0m");
                  continue;

            }



            if(colum == blinky.X && filas == blinky.Y){
                if(contSuperPastillas )
                    printf("\x1B[38;2;15;12;255mn\033[0m");
                else
                  printf("\033[1;36mn\033[0m");
                  continue;

            }

            if(colum == bob.X && filas == bob.Y){
                if(contSuperPastillas )
                    printf("\x1B[38;2;15;12;255mn\033[0m");
                else
                printf("\033[1;32mn\033[0m");
                  continue;

            }

            // Impresion de puntos. Si se imprime uno, quiere decir que aun no se gana la partida

            if(map[filas][colum] == '*' ){

            printf("\033[0m%c\033[0m", map[filas][colum]);
            win = 1;

            }
            if(map[filas][colum] == '+' ){

            printf("\x1B[38;2;128;17;17m%c\033[0m", map[filas][colum]);

            win = 1;

            }



            if(colum == pukku.X && filas == pukku.Y){

                //Impresion de pacman de acuerdo a su posicion

                if(waka % 2 == 0){
                  printf("\033[1;33mo\033[0m");
                  if(contSuperPastillas)
                    Beep(750, 50);
                  waka++;
                }
                else{
                  printf("\033[1;33m<\033[0m");
                  Beep(750, 50);
                  waka--;
                }

                continue;
            }


          // Impresion de paredes y espacios vacios

        if(map[filas][colum] == '#' || map[filas][colum] == ' ' )
            printf("\x1B[38;2;0;20;90m%c\033[0m", map[filas][colum]);

        // Los porcentajes sirven para crear espacios vacios y que no
        // se llenen con puntos.

        if(map[filas][colum] == '%')
            printf(" ", map[filas][colum]);

        //Superpastilla

        if(map[filas][colum] == '?')
                  printf("\033[1;32m%c\033[0m", map[filas][colum]);


        }



        puts("");


    }





  //delay entre actualizacion | 170ms inicial, en cada nivel se reduce 10ms
  Sleep(frameTime);

  //Contador para que los fantasmas salgan
  ghostCount += 1;

  //Si no se detectaron puntos en el mapa, se gano.

  if (win == 0)
    goto WINNER;


    }

if(pukku.direc != 4){
      if(vidas != 0 || win == 1){
      goto LIFELOSS;
    }

    if(vidas == 0)
        gameOver();
        goto GAMEFINAL;


    WINNER:
    if(vidas > 0)
        gameWin();
        goto RESTART;

// Se ejecuta la funcion de escritura de puntajes con los puntos de la partida
// Si se consiguio pasar un puntaje, entonces se mueve la lista.

GAMEFINAL:

scoreWrite(puntos);

}

}

// Main


int main(){

  // Declaracion inicial de pacman

    struct Movable pacman;


    pacman.direc = RIGHT;
    pacman.X = 1;
    pacman. Y = 1;
    int scores[SCORE_LIMIT];

    //Lectura de highscore al iniciar

    FILE *fPtr;
    fPtr = fopen("highScore.txt", "r");

    for(int i = 0; i< SCORE_LIMIT; i++){

        fscanf(fPtr, "%d\n", &scores[i]);

    }

    fclose(fPtr);



    /*

    Mapa del juego.

    HEIGHT y WIDTH indican el ANCHO y LARGO del mapa.
    Incluyendo los bordes.

    # es una pared

    ' ' es un espacio por el que pacman puede moverse.

    * es un punto

    */


char map[HEIGHT][WIDTH] = {
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','#'},
{'#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#',' ','#'},
{'#',' ','#','%','%','%','#',' ','#','%','%','%','%','%','#',' ','#','%','%','%','%','%','%','#',' ','#','%','%','%','%','%','%','%','#',' ','#','%','%','#',' ','#'},
{'#',' ','#','%','%','%','#',' ','#','%','%','%','%','%','#',' ','#','%','%','%','%','%','%','#',' ','#','%','%','%','%','%','%','%','#',' ','#','%','%','#',' ','#'},
{'#',' ','#','%','%','%','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','%','%','#',' ','#'},
{'#',' ','#','%','%','%','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','%','%','#',' ','#'},
{'#',' ','#','%','%','%','#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','%','%','#',' ','#'},
{'#',' ','#','%','%','%','#',' ','#','%','%','%','#',' ','#','#','#','#','#','#','#',' ','#','%','%','%','%','#',' ','#','%','%','%','%','%','%','%','%','#',' ','#'},
{'#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#','%','%','%','%','#',' ','#','#','#','#','#','#','#','#','#','#',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?',' ',' ',' ',' ',' ','#','%','%','%','%','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#','#','#','%','%','%','%','#',' ','#','#','#','#','#',' ','#','#','#','#',' ','#'},
{'#',' ','#','%','%','%','%','%','#',' ','#','%','%','%','%','#',' ','#','%','%','%','%','%','%','%','%','%','#',' ','#','%','%','%','#',' ','#','%','%','#',' ','#'},
{'#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#','#',' ','#'},
{'#','?',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};


char map2[HEIGHT][WIDTH] = {

{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?','#'},
{'#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#'},
{'#',' ','#','#','#','#','#','#','#','#',' ','#','%','%','%','%','%','%','%','%','%','#',' ','#','#',' ','#','#','#',' ','#','#','%','%','%','%','%','%','#',' ','#'},
{'#',' ','#','#','#','#','#','#','#','#',' ','#','%','%','%','%','%','%','%','%','%','#',' ','#','#',' ','#','#','#',' ','#','#','%','%','%','%','%','%','#',' ','#'},
{'#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','?',' ',' ',' ',' ','#','#','%','%','%','%','%','%','#',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#','#',' ','#','#','%','%','%','%','%','%','#',' ','#'},
{'#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#'},
{'#',' ','#','%','%','%','%','%','%','%','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','#','%','%','%','%','%','%','%','#',' ','#','%','%','%','%','%','%','%','%','%','%','%','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ','#','%','%','%','%','%','%','%','#',' ','#','%','%','%','%','%','%','%','%','%','%','%','#',' ','#','#','#',' ','#','%','%','%','%','%','%','%','%','%','#'},
{'#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#',' ','#','%','%','%','%','%','%','%','%','%','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','%','%','%','%','%','%','%','%','%','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}

};

char mapCopy[HEIGHT][WIDTH];
char mapCopy2[HEIGHT][WIDTH];


//  "\e[?25l" quita el cursor y "\e[?25h" lo regresa (al terminar programa)

printf("\e[?25l");

    char GAME = '3';


    // Ciclo que inicia el programa.
    // Se inicia el menu y despues se elige si el juego inicia o se cierra

    tutorial();

    do{

        //Reinicio del mapa

        for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                mapCopy[i][j] = map[i][j];

            }
        }

                for(int i = 0; i < HEIGHT; i++){

            for(int j = 0; j < WIDTH; j++){

                mapCopy2[i][j] = map2[i][j];

            }
        }


        //Menu

        GAME = Menu(scores[0]);

        //Juego
    if(GAME == '1'){
        game(pacman,mapCopy, mapCopy2, scores[0]);

//Lectura nueva de los puntajes



            FILE *fPtr;
    fPtr = fopen("highScore.txt", "r");

    for(int i = 0; i< SCORE_LIMIT; i++){

        fscanf(fPtr, "%d\n", &scores[i]);

    }

    }

    fclose(fPtr);

    if(GAME == '2')
        highScores(scores);


    }while(GAME != '3');

printf("\e[?25h");

}
