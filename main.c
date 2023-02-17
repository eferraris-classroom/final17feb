#include <stdio.h>
#include "helper.h"

int main() {
    Lista * list1=nuevalista();
    insertar(list1, nuevonodo(1));
    insertar(list1, nuevonodo(2));
    insertar(list1, nuevonodo(1));
    insertar(list1, nuevonodo(3));
    insertar(list1, nuevonodo(23));
    insertar(list1, nuevonodo(4));
    insertar(list1, nuevonodo(223));
    Lista * list2=nuevalista();
    insertar(list2, nuevonodo(1));
    insertar(list2, nuevonodo(2));
    insertar(list2, nuevonodo(3));
    insertar(list2, nuevonodo(4));
    if(list1->cant<list2->cant){
        if(subconjunto(list1,list2)){
            printf("el conjunto \n");
            imprimir(list1);
            printf("es subconjunto del conjunto \n");
            imprimir(list2);
        } else{
            printf("no esta incluido\n");
        }
    } else{
        if(subconjunto(list2,list1)){
            printf("el conjunto \n");
            imprimir(list2);
            printf("es subconjunto del conjunto \n");
            imprimir(list1);
        } else{
            printf("no esta incluido\n");
        }
    }
    imprimir(list1);
    insertaralfinal(list1, nuevonodo(12));
    imprimir(list1);
    int posaliminar=6;
    eliminar(list1,posaliminar);
    imprimir(list1);
    int posbuscado=5;
    if(buscarxpos(list1,posbuscado)!=NULL){
        printf("el valor es %d del nodo en la posicion %d\n", (buscarxpos(list1, posbuscado))->valor, posbuscado);
    } else{
        printf("la posicion excede a la cantidad de nodos de la lista\n");
    }

    printf("la lista tiene %d cantidad de nodos\n", tamaniolist(list1));
    return 0;
}
