//Laboratorio #5
//Asbel Mena 
//C14647

#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList* lista = create_list();

    //Insertando nodos al inicio
    insert_beginning(lista, 8);
    insert_beginning(lista, 18);
    printf("Primeros dos nodos ingresados: ");
    print_listforward(lista);

    //Insertando nodos al final
    insert_end(lista, 28);
    insert_end(lista, 38);
    printf("**Adición de dos nodos al final**: ");
    print_listforward(lista);

    //Insertando nodo en una posición específica
    insert_position(lista, 57, 3);
    printf("**Adición del nodo %d en la posición 3 del conjunto**: ",57);
    print_listforward(lista);

    //Suprimiendo un nodo basado en el contenido del data
    deletenode(lista, 38);
    printf("**Eliminación del nodo %d**: ",38);
    print_listforward(lista);

    //Buscar un elemento
    Node* encontrado = search_node(lista, 57); //Rastreando el nodo que posee el número 57
    if (encontrado != NULL) {
        printf("Nodo %d encontrado en el set de datos\n", encontrado->data);
    } else {
        printf("Nodo %d no localizado en el set de datos\n", 57);
    }

    //Recorrer la lista hacia adelante
    printf("Lista hacia adelante: ");
    print_listforward(lista);

    //Recorriendo la lista hacia atrás
    printf("Lista hacia atrás: ");
    print_listbackward(lista);

    //Liberar la lista
    freelist(lista);

    return 0;
}