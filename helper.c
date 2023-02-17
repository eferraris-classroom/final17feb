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
    if(nodoainsertar->valor >= 0 && nodoainsertar->valor <= 127){
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

void insertaralfinal(Lista *list, Nodo *insertarfinal) {
    if(list->Prinodo==NULL){
        list->Prinodo=insertarfinal;
    } else{
        Nodo * ant;
        for (ant=list->Prinodo;ant->sig!=NULL;ant=ant->sig) {}
        ant->sig=insertarfinal;
    }
    list->cant++;
}

void eliminar(Lista *list, int pos) {
    Nodo * limpiar;
    if(pos<=list->cant){
        if(pos==1){
            limpiar=list->Prinodo;
            list->Prinodo=list->Prinodo->sig;
            free(limpiar);
        } else{
            Nodo * eliminar=list->Prinodo;
            for (int i = 0; i < pos - 2; ++i) {
                eliminar=eliminar->sig;
            }
            limpiar=eliminar->sig;
            if(eliminar->sig!=NULL){
                eliminar->sig=eliminar->sig->sig;
            }
            free(limpiar);
        }
        list->cant--;
    }
}

Nodo *buscarxpos(Lista *list, int pos) {
    if(pos<=list->cant){
        Nodo * buscado=list->Prinodo;
        for (int i = 0; i < pos - 1; ++i) {
            buscado=buscado->sig;
        }
        return buscado;
    } else{
        return NULL;
    }
}

int tamaniolist(Lista *list) {
    return list->cant;
}
