#ifndef TAD_ESTATICA_H
#define TAD_ESTATICA_H

#include <stdbool.h>

/* Definición de tipos de datos */
#define SNULL -1
#define SMAX 10 // Número máximo de elementos en la pila

typedef int tItemS;

typedef int tPosS;

typedef struct Stack {
    tItemS data[SMAX];
    tPosS top;
} tStack;

/* Cabeceras
 * S -> Pila
 * p -> posición o nodo de la pila
 */
bool isEmptyStack(tStack S);
void createEmptyStack(tStack *S);
bool push(tItemS d, tStack *S); //añade elemento
void pop(tStack *S); //borra elemento
tItemS peek(tStack S); //recupera elemento de la cima

#endif //TAD_ESTATICA_H
