#ifndef TEXTO_H
#define TEXTO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void *item;
typedef void *Text;

/*Cria um barco do tipo texto.
Entrada: nenhuma
Saida: um ponteiro do tipo struct texto*/
Stext* createText();

/*Constroi o barco do tipo texto
entrada: um ponteiro do tipo char contendo os comandos para a criação do barco do tipo texto e a struct do tipo texto que vai receber as informações
saida: a struct do tipo texto inserida na entrada, porém com as informações organizadas de acordo com cada variavel*/
item buildText(char *command, Text text);

/*Pega a id de um barco do tipo texto
Entrada: a struct do tipo texto que deseja coletar a informação
Saida: um valor inteiro contendo a Id da struct*/
int getIdText(Stext *texto);

/*Informa a coordenada X de um barco do tipo texto
Entrada: uma struct do tipo barco
saida: um valor do tipo double com a coordenada X do barco*/
double getXText(Stext *texto);

/*Informa a coordenada Y de um barco do tipo texto
Entrada: uma struct do tipo barco
saida: um valor do tipo double com a coordenada Y do barco*/
double getYText(Stext *texto);


/*Informa a cor da borda de um barco do tipo texto
Entrada: uma struct do tipo barco
saida: um valor do tipo char* com a cor da borda do barco*/
char* getCorBText(Stext *texto);


/*Informa a cor do preenchimento de um barco do tipo texto
Entrada: uma struct do tipo barco
saida: um valor do tipo char* com a cor do preenchimnto do barco*/
char* getCorPText(Stext *texto);


/*Informa o texto de um barco do tipo texto
Entrada: uma struct do tipo textu
saida: um valor do tipo char* com o texto do barco*/
char* getCorValueText(Stext *texto);


/*Informa a ancora de um barco
Entrada: uma struct do tipo texto
saida: um valor do tipo char com a ancora do barco*/
char getAnchorText(Stext texto);

#endif