//
// Created by lenon65 on 17/02/23.
//

#ifndef FINAL17FEB_HELPER_H
#define FINAL17FEB_HELPER_H

typedef struct nodo{
    int valor;
    struct nodo * sig;
}Nodo;
typedef struct lista{
    int cant;
    Nodo * Prinodo;
}Lista;

Lista * nuevalista();
Nodo * nuevonodo(int n);
void insertar(Lista * list, Nodo * nodoainsertar);
int subconjunto(Lista * list1,Lista *list2);


//empiezo punto 2

void insertaralfinal(Lista * list, Nodo * insertarfinal);
void eliminar(Lista * list, int pos);
Nodo * buscarxpos(Lista * list, int pos);
int tamaniolist(Lista * list);
void imprimir(Lista * lista);



#endif //FINAL17FEB_HELPER_H
