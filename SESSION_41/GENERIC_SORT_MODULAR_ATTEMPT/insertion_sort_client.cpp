#include <iostream> 
#include "insertion_sort.hpp"

int main(void){
    int ia[5] = {400, 300, 200, 100, 50}; 
    float fa[5] = {4.4f, 3.3f, 2.2f, 1.1f, 0.5f}; 

    show<int>(ia, 5, "integer array:before sort:"); 
    show<float>(fa, 5, "float array:after sort:"); 

    insertion_sort<int>(ia, 5); 
    insertion_sort<float>(fa, 5); 

    show<int>(ia, 5, "integer array:before sort:"); 
    show<float>(fa, 5, "float array:after sort:"); 

    return EXIT_SUCCESS; 
}