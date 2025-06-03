#ifndef PACLIB_H_INCLUDED
#define PACLIB_H_INCLUDED

void gameOver();
void dead();
enum Move PukkuMove(char ARRIBA, char ABAJO, char IZQ, char DER, enum Move direc);
void scoreWrite(int num);
void highScoreEnOrden(int arr[], int num, int* n);
void gameWin();
void tutorial();

#endif // PACLIB_H_INCLUDED
