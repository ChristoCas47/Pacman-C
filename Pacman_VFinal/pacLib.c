#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define HEIGHT 25
#define WIDTH 46

#define SCORE_LIMIT 7
enum Move {UP,DOWN,LEFT,RIGHT};

struct Movable{

    enum Move direc;
    int X;
    int Y;

};

void highScoreEnOrden(int arr[], int num, int* n) {
    int i;
    if (*n < SCORE_LIMIT) {
        arr[(*n)++] = num;
    }
    else {
        for (i = 0; i < SCORE_LIMIT; i++) {
            if (num > arr[i]) {
                break;
            }
        }
        if (i < SCORE_LIMIT) {
            for (int j = SCORE_LIMIT-1; j > i; j--) {
                arr[j] = arr[j-1];
            }
            arr[i] = num;
        }
    }

    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void scoreWrite(int num)
{
//hScore es nuestro arreglo donde guardaremos nuestros puntajes
int hScore[SCORE_LIMIT]={0};
//n es un contador para nuestro arreglo
int n = 0;
//num es el puntaje de entrada
int copy = num;
//Crear archivo hishScore.txt
char archivo[] = "highScore.txt";

//Si no existe archivo lo creamos
FILE *fPtr = fopen(archivo,"r");
if (fPtr ==NULL){
    fPtr = fopen(archivo,"w");

}else {
//While para revisar si ya hay datos en el archivo
    while (fscanf(fPtr, "%d", &num) == 1) {
            highScoreEnOrden(hScore, num, &n);
        }
        fclose(fPtr);
    }
//Aqui entraria el score en la variable num, use un prompt como prueba



highScoreEnOrden(hScore, copy, &n);

//Bucle for para imprimir nuestro arreglo hScore en nuestro archivo highScore.txt
 fPtr = fopen("highScore.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fPtr, "%d\n",hScore[i]);
    }
    fclose(fPtr);

}



void gameWin( ){

system("cls");

      printf("\x1B[38;2;255;230;0m");

printf(
"##       ######## ##     ## ######## ##          ##     ## ########  \n"
"##       ##       ##     ## ##       ##          ##     ## ##     ## \n"
"##       ##       ##     ## ##       ##          ##     ## ##     ## \n"
"##       ######   ##     ## ######   ##          ##     ## ########  \n"
"##       ##        ##   ##  ##       ##          ##     ## ##        \n"
"##       ##         ## ##   ##       ##          ##     ## ##        \n"
"######## ########    ###    ######## ########     #######  ##        \n"
);


    Sleep(200);
    system("cls");

          printf("\x1B[38;2;40;160;30m");

printf(
"##       ######## ##     ## ######## ##          ##     ## ########  \n"
"##       ##       ##     ## ##       ##          ##     ## ##     ## \n"
"##       ##       ##     ## ##       ##          ##     ## ##     ## \n"
"##       ######   ##     ## ######   ##          ##     ## ########  \n"
"##       ##        ##   ##  ##       ##          ##     ## ##        \n"
"##       ##         ## ##   ##       ##          ##     ## ##        \n"
"######## ########    ###    ######## ########     #######  ##        \n"
);


    Sleep(200);
    system("cls");

              printf("\x1B[38;2;30;90;160m");

printf(
"##       ######## ##     ## ######## ##          ##     ## ########  \n"
"##       ##       ##     ## ##       ##          ##     ## ##     ## \n"
"##       ##       ##     ## ##       ##          ##     ## ##     ## \n"
"##       ######   ##     ## ######   ##          ##     ## ########  \n"
"##       ##        ##   ##  ##       ##          ##     ## ##        \n"
"##       ##         ## ##   ##       ##          ##     ## ##        \n"
"######## ########    ###    ######## ########     #######  ##        \n"
);


    Sleep(200);
    system("cls");

    printf("\033[1;0m");


}






void gameOver(){

      system("cls");

      printf("\033[1;31m");

printf(""
" ####    ##   #    # ######     ####  #    # ###### #####  \n"
"#    #  #  #  ##  ## #         #    # #    # #      #    # \n"
"#      #    # # ## # #####     #    # #    # #####  #    # \n"
"#  ### ###### #    # #         #    # #    # #      #####  \n"
"#    # #    # #    # #         #    #  #  #  #      #   #  \n"
" ####  #    # #    # ######     ####    ##   ###### #    # \n"
""
);


    printf("\033[1;0m");

    Sleep(2500);



}

void dead(){

      system("cls");

      printf("\033[1;31m");

printf(""
"         #                             \n"
"        ##      #    # # #####    ##   \n"
"       # #      #    # # #    #  #  #  \n"
" #####   #      #    # # #    # #    # \n"
"         #      #    # # #    # ###### \n"
"         #       #  #  # #    # #    # \n"
"       #####      ##   # #####  #    # \n"
"                                       \n"
);


    printf("\033[1;0m");

    Sleep(2500);


}



enum Move PukkuMove(char ARRIBA, char ABAJO, char IZQ, char DER, enum Move direc){

  /*
  Funcion de movimiento.

  kbhit permite que se ejecute la funci�n
  _getch guarda la tecla presionada.
  el switch regresa un valor de "enum Move" a pukku.direc
  El fflush hace que no se guarden inputs en el buffer.

  */



    char input = _getch();

    switch (input)
    {
  case 'w':
  case 'W':

    fflush(stdin);
    if(ARRIBA != '#')
        return UP;
    break;

  case 's':
  case 'S':

    fflush(stdin);
    if(ABAJO != '#')
        return DOWN;
    break;

  case 'a':
  case 'A':

    fflush(stdin);
    if(IZQ != '#')
        return LEFT;
    break;

  case 'd':
  case 'D':

    fflush(stdin);
    if(DER != '#')
        return RIGHT;
    break;

  case 'o':
  case 'O':
    return 4;
    break;


  default:
    break;
    }

    return direc;



}


void tutorial(){

int nextOne;
puts("");

printf("\t\033[0;34m|\033[0m\033[1;33m   :::::::::     :::      ::::::::  ::::    ::::      :::     ::::    :::\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   :+:    :+:  :+: :+:   :+:    :+: +:+:+: :+:+:+   :+: :+:   :+:+:   :+:\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   +:+    +:+ +:+   +:+  +:+        +:+ +:+:+ +:+  +:+   +:+  :+:+:+  +:+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   +#++:++#+ +#++:++#++: +#+        +#+  +:+  +#+ +#++:++#++: +#+ +:+ +#+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   +#+       +#+     +#+ +#+        +#+       +#+ +#+     +#+ +#+  +#+#+#\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   #+#       #+#     #+# #+#    #+# #+#       #+# #+#     #+# #+#   #+#+#\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   ###       ###     ###  ########  ###       ### ###     ### ###    ####\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");

//      printf("\x1B[38;2;30;90;160m");
//      printf("\033[1;0m");

printf("\x1B[38;2;30;230;160m");
printf("\n\n\n\n\n");
puts(

"         _______ \n"
"        |\\     /|\n"
"        | +---+ |\n"
"        | |   | |\n"
"        | |w  | |\n"
"        | +---+ |\n"
"        |/_____\\|\n"
" _______ _______ _______ \n"
"|\\     /|\\     /|\\     /|\n"
"| +---+ | +---+ | +---+ |\n"
"| |   | | |   | | |   | |\n"
"| |a  | | |s  | | |d  | |\n"
"| +---+ | +---+ | +---+ |\n"
"|/_____\\|/_____\\|/_____\\|\n"
     );
     printf("\033[1;0m");

     puts("W: Arriba | A: Izquierda | S: Abajo | D: Derecha");

     puts("\n\n\nPresiona cualquier tecla para continuar");

    nextOne = getch();

    //#########################################

    system("cls");

    puts("");

printf("\t\033[0;34m|\033[0m\033[1;33m   :::::::::     :::      ::::::::  ::::    ::::      :::     ::::    :::\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   :+:    :+:  :+: :+:   :+:    :+: +:+:+: :+:+:+   :+: :+:   :+:+:   :+:\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   +:+    +:+ +:+   +:+  +:+        +:+ +:+:+ +:+  +:+   +:+  :+:+:+  +:+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   +#++:++#+ +#++:++#++: +#+        +#+  +:+  +#+ +#++:++#++: +#+ +:+ +#+\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   +#+       +#+     +#+ +#+        +#+       +#+ +#+     +#+ +#+  +#+#+#\033[0m \033[0;31m     ###\033[0;34m\t  |\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   #+#       #+#     #+# #+#    #+# #+#       #+# #+#     #+# #+#   #+#+#\033[0m \033[0;31m     ###    ###\033[0;34m|\033[0m\n");
printf("\t\033[0;34m|\033[0m\033[1;33m   ###       ###     ###  ########  ###       ### ###     ### ###    ####\033[0m \033[0;31m      ########\033[0;34m |\033[0m\n");

//      printf("\x1B[38;2;30;90;160m");
//      printf("\033[1;0m");


/**
inky - red
printf("\033[1;31mn\033[0m");

pinky - pink
printf("\033[1;35mn\033[0m");

blinky - blue
printf("\033[1;36mn\033[0m");

bob
printf("\033[1;32mn\033[0m");


*/


printf("\n\n\n\n\n");
printf("Conoce a la pandilla!\n\n");


    printf("\t\t\033[1;31m     ,---.\033[0m \033[1;33m   ,--. \033[0m \t\t      \033[0;36m  ,--. \033[0m\033[0;32m  ,--.  \033[0m \033[0;35m,--.                              \n");
    printf("\t\t\033[1;31m    |oo  |\033[0m \033[1;33m_  \\   ;\033[0m\t\t     \033[0;36m  | oo |\033[0m\033[0;32m |  oo| \033[0m\033[0;35m|  oo|                           \n");
    printf("\t\t\033[1;33mo  o\033[0m\033[1;31m|~~  |\033[0m\033[1;33m(_) /   ;\033[0m\t\t      \033[0;36m | ~~ |\033[0m\033[0;32m |  ~~|\033[0m \033[0;35m| ~~ |\033[0m\n");
    printf("\t\t  \033[1;31m  |/\\/\\|\033[0m\033[1;33m   '._,'\033[0m \t\t    \033[0;36m   |/\\/\\|\033[0m\033[0;32m |/\\/\\|\033[0;35m |/\\/\\|                 \n\033[0m");

puts("\n\n");

printf("\033[1;33mAqui esta tu personaje, Pacman: o  <\n\n");

printf("\033[1;31mEste es Inky: n\033[0m\n\n");


printf("\033[1;35mEl es Pinky: n\033[0m\n\n");


printf("\033[1;36mAqui esta Blinky: n\033[0m\n\n");


printf("\033[1;32mBob: n\033[0m");


     puts("\n\n\nPresiona cualquier tecla para continuar");

    nextOne = getch();


}
