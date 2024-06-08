//Laboratorio #5
//Asbel Mena
//C14647

#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

//Creación de la lista doblemenente enlazada
DoubleList* create_list() {
    DoubleList* lista = (DoubleList*)malloc(sizeof(DoubleList));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

//Inserción del nodo al principio de la lista
void insert_beginning(DoubleList* lista, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = lista->head;

    if (lista->head != NULL) {
        lista->head->prev = newNode;
    } else {
        lista->tail = newNode;
    }

    lista->head = newNode;
}

//Inclusión del nodo al final de la lista
void insert_end(DoubleList* lista, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = lista->tail;

    if (lista->tail != NULL) {
        lista->tail->next = newNode;
    } else {
        lista->head = newNode;
    }

    lista->tail = newNode;
}

//Inclusión del nodo en un lugar determinado de la lista 
void insert_position(DoubleList* lista, int data, int position) {
    if (position == 0) {
        insert_beginning(lista, data);
        return;
    }

    Node* actual = lista->head;
    for (int i = 0; actual!= NULL && i < position - 1; i++) {
        actual = actual->next;
    }

    if (actual == NULL) {
        printf("Falló, posición no hallado en el rango de datos\n");
        return;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = actual->next;
    newnode->prev = actual;

    if (actual->next != NULL) {
        actual->next->prev = newnode;
    } else {
        lista->tail = newnode;
    }

    actual->next = newnode;
}

//Supresión del nodo con base en su valor
void deletenode(DoubleList* lista, int data) {
    Node* actual = lista->head;

    while (actual != NULL && actual->data != data) {
        actual = actual->next;
    }

    if (actual == NULL) {
        printf("Falló, nodo no hallado en el set de datos\n");
        return;
    }

    if (actual->prev != NULL) {
        actual->prev->next = actual->next;
    } else {
        lista->head = actual->next;
    }

    if (actual->next != NULL) {
        actual->next->prev = actual->prev;
    } else {
        lista->tail = actual->prev;
    }

    free(actual);
}

//Averiguar nodo con base a su valor
Node* search_node(DoubleList* lista, int data) {
    Node* actual = lista->head;
    while (actual != NULL && actual->data != data) {
        actual = actual->next;
    }
    return actual;
}

//Impresión de la lista desde el head hasta el tail
void print_listforward(DoubleList* lista) {
    Node* actual = lista->head;
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->next;
    }
    printf("\n");
}

//Desplegar la lista desde atrás hacia adelante
void print_listbackward(DoubleList* lista) {
    Node* actual = lista->tail;
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->prev;
    }
    printf("\n");
}

//Desvincular toda la memoria empleada por la lista
void freelist(DoubleList* lista) {
    Node* actual = lista->head;
    while (actual != NULL) {
        Node* next = actual->next;
        free(actual);
        actual = next;
    }
    free(lista);
}