#include <cstdio>
#include <cstdlib>

void* xmalloc(size_t size_in_bytes); 
struct node* get_node(int data); 

struct node{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void test(void); 
void traverse(struct node* p_start); 

int main(void){
    test(); 
    return (0); 
}

void test(void){
    struct node* p_node_1 = NULL; 
    struct node* p_node_2 = NULL; 
    struct node* p_node_3 = NULL; 
    struct node* p_node_4 = NULL; 

    p_node_1 =  get_node(100); 
    p_node_2 =  get_node(200); 
    p_node_3 =  get_node(300); 
    p_node_4 =  get_node(400); 

    p_node_1->next = p_node_2; 
    p_node_2->next = p_node_3; 
    p_node_3->next = p_node_4; 

    p_node_2->prev = p_node_1; 
    p_node_3->prev = p_node_2; 
    p_node_4->prev = p_node_3; 

    traverse(p_node_1); 

    free(p_node_1); 
    p_node_1 = NULL; 

    free(p_node_2); 
    p_node_2 = NULL; 

    free(p_node_3); 
    p_node_3 = NULL; 

    free(p_node_4); 
    p_node_4 = NULL; 
}

void traverse(struct node* p_start){
    printf("1st data = %d\n", p_start->data); 
    printf("2nd data = %d\n", 
            p_start->next->data); 
    printf("3rd data = %d\n", 
        p_start->next->next->data); 
    printf("4th data = %d\n", 
        p_start->next->next->next->data); 
}

struct node* get_node(int data){
    struct node* ptr = NULL; 

    ptr = (struct node*)xmalloc(sizeof(struct node)); 
    ptr->data = data; 
    ptr->prev = NULL; 
    ptr->next = NULL; 

    return (ptr); 
}

void* xmalloc(size_t size_in_bytes){
    void* ptr = NULL; 

    ptr = malloc(size_in_bytes); 
    if(ptr == NULL){
        puts("MemoryAllocationError"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}