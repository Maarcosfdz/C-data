#include "estaticaListaEnlazada.h"


void createEmptyList(tList *L) {
    L->lastPos = LNULL; //este ten a flecha porque é un puntero
}

bool isEmptyList(tList L) {
    // Si una lista estática está vacía, el puntero que apunta a la última posición debe ser LNULL
    return L.lastPos == LNULL;
}

tPosL first(tList L) {
    return 0; // Como una list estática es un array, la primera posición siempre será la 0
}

tPosL last(tList L) {
    return L.LastPos;
}

tPosL previous(tPosL p, tList L) {
    return --p;
}

tPosL next(tPosL p, tList L) {
    if (p == L.LastPos) 
        return LNULL;
    else 
        return ++p;
}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

void updateItem(tItemL d, tPosL p, tList *L) {
    L->data[p] = d;
}

tPosL findItem(tItemL d, tList L) {
    // p -> el iterador que buscará el elemento deseado
    tPosL p;

    if(isEmptyList(L)) {
        return LNULL;
    } else {
        for(p = 0; (p < L.LastPos) && (L.data[p] != d); p++); //bucle que recorre a lista
        if(L.data[p] == d) { 
            return p;
        } else {
            return LNULL;
        }
    }

}

bool insertItem(tItemL d, tPosL p, tList *L) {
    /* i -> Iterador que moverá todos los elementos una posición más adelante en caso de que se inserte el elemento
     * por el medio de la lista, este comenzará desde el final e irá hasta la posición en la que lo querramos añadir */
    tPosL i;

    if(L->LastPos == MAX - 1) { // Comprueba si la lista está llena, o de -1, é porque a última posición, ao ser un string está reservada para o \0
        return false;
    } else {
        L->lastPos++; // Como estamos insertando un elemento, al tamaño del array aumenta en 1

        if(p == LNULL) { // Si se quiere insertar en la última posición
            L->data[L->LastPos] = d;

        } else { // Si se quiere insertar en primera posición o cualquier otra intermedia
            // Desplazamos todos los elementos una posición más adelante en el array
            for(i = L->LastPos; i > p; i--) {
                L->data[i] = L->data[i - 1];
            }

            L->data[p] = d;
        }
    return true;
    }
}

void deleteList(tList *L) {
    L->LastPos = LNULL;
}

bool copyList(tList L, tList *M) { // Copiar la lista de un array en otro
    tPosL p;

    createEmptyList(M);

    for(p = 0; p <= L.LastPos; p++) { // Desde la primera posición de L hasta la última
        M->data[p] = L.data[p]; // Iremos igualando el campo data de cada elemento
    }

    M->LastPos = L.LastPos; // Como son dos listas idénticas, la última posición será la misma en ambas

    return true;
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;

    L->lastPos--; // Como estamos eliminando un elemento, estamos reduciendo el tamaño del array, por eso se resta 1

    for(i = p; i <= L->lastPos; i++) {
        /* Todos los elementos posteriores al eliminado, se desplazan una posición a la izquierda para evitar
         * dejar huecos libres en el array */
        L->data[i] = L->data[i + 1];
    }

}
