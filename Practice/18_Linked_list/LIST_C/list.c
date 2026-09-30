#include <stdio.h> 
#include <stdlib.h>
#include "list.h"

/* Interface functions declaration */
list_t* create_list(void){
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

status_t insert_start(list_t* p_list, data_t new_data){
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
}

status_t insert_end(list_t* p_list, data_t new_data){
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data){
    struct node* e_node = NULL; 

    e_node = search_node(p_list, e_data); 
    if(e_node == NULL)
        return (LIST_INVALID_DATA); 

    generic_insert(e_node, get_node(new_data), e_node->next); 
    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data){
    struct node* e_node = NULL; 

    e_node = search_node(p_list, e_data); 
    if(e_node == NULL)
        return (LIST_INVALID_DATA); 

    generic_insert(e_node->prev, get_node(new_data), e_node); 
    return (SUCCESS);
}

status_t get_start(list_t* p_list, data_t* p_data){
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_data = p_list->next->data; 
    return (SUCCESS); 
}

status_t get_end(list_t* p_list, data_t* p_data){
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_data = p_list->prev->data; 
    return (SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_data){
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_data = p_list->next->data;
    generic_delete(p_list->next);  
    return (SUCCESS); 
}

status_t pop_end(list_t* p_list, data_t* p_data){
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_data = p_list->prev->data; 
    generic_delete(p_list->prev); 
    return (SUCCESS);
}

status_t remove_start(list_t* p_list){
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    generic_delete(p_list->next);  
    return (SUCCESS);
}

status_t remove_end(list_t* p_list){
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);  
    generic_delete(p_list->prev); 
    return (SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data){
    node_t* p_delete_node = NULL;
    p_delete_node = search_node(p_list, r_data);
    if(p_delete_node == NULL)
         return(LIST_INVALID_DATA);
    generic_delete(p_delete_node);
    return(SUCCESS);
}

len_t get_length(list_t* p_list){
    len_t length=0;
    node_t* p_run = NULL;

    for(p_run = p_list->next; p_run != p_list; p_run=p_run->next){
       ++length;
    }

    return(length);
}

status_t find(list_t* p_list, data_t f_data){
    node_t* p_temp = NULL;

    p_temp = search_node(p_list, f_data);
    return (p_temp != NULL);
}

status_t is_list_empty(list_t* p_list){
    return(p_list->prev == p_list && p_list->next == p_list); 
}

void show_list(list_t* p_list, const char* msg){
    if(msg){
        puts(msg);
    }

    node_t* p_run;
    printf("[START]<->");
    for(p_run=p_list->next; p_run != p_list; p_run = p_run->next){
        printf("[%d]<->", p_run->data);
    }
    puts("[END]");
}

status_t destroy_list(list_t* p_list){
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next){
        p_run_next = p_run_next;
        free(p_run);
    }

    free(p_list);
    return (SUCCESS);
}
 

/* List auxillary function */
static void generic_insert(node_t* p_start, node_t* p_mid, node_t* p_end){
    p_mid->next = p_end; 
    p_mid->prev = p_start; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
}

static void generic_delete(node_t* p_delete_node){
    (*((*p_delete_node).prev)).next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
}

static node_t* search_node(list_t* p_list, data_t search_data){
    node_t* p_run; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        if(p_run->data == search_data)
            return (p_run); 

    return (NULL); 
}

static node_t* get_node(data_t new_data){
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->prev = NULL; 
    p_new_node->next = NULL; 

    return (p_new_node); 
}

/* General auxillary function declarations */
static void* xmalloc(size_t size_in_bytes){
    void* ptr = NULL; 

    ptr = malloc(size_in_bytes); 
    if(NULL == ptr){
        fprintf(stderr, "malloc():out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}

