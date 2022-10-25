#ifndef _MINA_H_
#define _MINA_H_

#include "texto.h"

/**
Uma mina é um objeto que pode ser colocado no campo de batalha e que explode quando um barco passa por cima dela
*/
typedef void *Mina;

/** Cria uma mina */
Mina createMina(int id, double x, double y, char *corb, char *corp, char *ancora);

/** Seta o id da mina */
void setMinaId(Mina mina, int id);

/** Seta a coordenada x da ancora da mina */
void setMinaX(Mina mina, double x);

/** Seta a coordenada y da ancora da mina */
void setMinaY(Mina mina, double y);

/** Seta a cor da borda da mina */
void setMinaCorb(Mina mina, char *cor);

/** Seta a cor de preenchimento da mina */
void setMinaCorp(Mina mina, char *cor);

/** Seta a ancora da mina */
void setMinaAncora(Mina mina, char *ancora);

/** Retorna o id da mina */
int getMinaId(Mina mina);

/** Retorna a coordenada x da ancora da mina */
double getMinaX(Mina mina);

/** Retorna a coordenada y da ancora da mina */
double getMinaY(Mina mina);

/** Retorna a cor da borda da mina */
char *getMinaCorB(Mina mina);

/** Retorna a cor de preenchimento da mina */
char *getMinaCorp(Mina mina);

/** Retorna a ancora da mina */
char *getMinaAncora(Mina mina);

/** Libera a memória alocada para a mina */
void killMina(Mina mina);

#endif