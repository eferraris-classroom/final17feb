//
// Created by lenon65 on 17/02/23.
//

#include <stdlib.h>
#include <stdio.h>
#include "helper.h"

Lista *nuevalista() {
    Lista * aux=(Lista*) malloc(sizeof(Lista));
    if(aux==NULL){
        printf("No hay memoria\n");
        exit(-1);
    }
    aux->Prinodo=NULL;
    aux->cant=0;
    return aux;
}

Nodo *nuevonodo(int n) {
    Nodo * aux=(Nodo *) malloc(sizeof(Nodo));
    if(aux==NULL){
        printf("No hay memoria\n");
        exit(-1);
    }
    aux->valor=n;
    aux->sig=NULL;
    return aux;
}

void insertar(Lista *list, Nodo *nodoainsertar) {
    if(list->Prinodo==NULL){
        list->Prinodo=nodoainsertar;
        list->cant++;
    } else{
        Nodo *aux=list->Prinodo;
        int i=0;
        for (;aux!=NULL ;aux=aux->sig) {
            if(aux->valor==nodoainsertar->valor){
                i++;
                break;
            }
        }
        if(i==0){
            aux=list->Prinodo;
            list->Prinodo=nodoainsertar;
            nodoainsertar->sig=aux;
            list->cant++;
        }
    }
}

int subconjunto(Lista *list1, Lista *list2) {
    Nodo * aux1;
    Nodo * aux2;
    int i=0;
    for (aux1=list1->Prinodo;aux1!=NULL ;aux1=aux1->sig) {
        for (aux2=list2->Prinodo;aux2!=NULL ;aux2=aux2->sig) {
            if(aux1->valor==aux2->valor){
                i++;
                break;
            }
        }
    }
    if(i==list1->cant)
        return 1;
    else
        return 0;
}

void imprimir(Lista *lista) {
    Nodo * aux=lista->Prinodo;
    for (;aux!=NULL;aux=aux->sig) {
        printf("(%d)",aux->valor);
    }
    printf("\n");

}
