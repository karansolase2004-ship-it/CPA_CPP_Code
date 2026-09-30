#include <cstdio>
#include <cstdlib>
#include "list.hpp"

int main (void){
    list_t* lst = NULL;

    lst = create_list();

    insert_start(lst,250);
    insert_start(lst,250);
    insert_start(lst,250);

    show_list(lst, "Showing linked list");
}