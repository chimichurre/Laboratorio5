#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoubleList {
    Node* head;
    Node* tail;
} DoubleList;

DoubleList* create_list();
void insert_beginning(DoubleList* lista, int data);
void insert_end(DoubleList* lista, int data);
void insert_position(DoubleList* lista, int data, int position);
void deletenode(DoubleList* lista, int data);
Node* search_node(DoubleList* lista, int data);
void print_listforward(DoubleList* lista);
void print_listbackward(DoubleList* lista);
void freelist(DoubleList* lista);

#endif 