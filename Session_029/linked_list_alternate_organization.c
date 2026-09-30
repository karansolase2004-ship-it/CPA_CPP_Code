#include <stdio.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct list{
    struct node* head_node;
    size_t nr_elements;
};

struct list* create_list(void){
    struct list* p_list = NULL;

    p_list = (struct list*)malloc(sizeof(struct list));
    assert(p_list != NULL);

    p_list->head_node = (struct node*)malloc(sizeof(struct node));
    assert(p_list->head_node != NULL);

    p_list->head_node->prev = p_list->head_node;
    p_list->head_node->next = p_list->head_node;

    p_list->head_node->data = 0;
    p_list->nr_elements = 0;
}