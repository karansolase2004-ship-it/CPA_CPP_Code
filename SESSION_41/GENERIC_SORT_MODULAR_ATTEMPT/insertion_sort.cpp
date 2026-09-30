#include "insertion_sort.hpp"

template <typename T> 
void insertion_sort(T* a, int N){
    int i, j; 
    T key; 

    for(j = 1; j < N; ++j){
        key = a[j]; 
        i = j - 1; 
        while(i > -1 && a[i] > key){
            a[i+1] = a[i]; 
            i = i - 1; 
        }
        a[i+1] = key; 
    }
}

template <typename T> 
void show(T* a, int N, const char* msg){
    int i; 

    if(msg != 0)
        std::cout << msg << std::endl; 
    for(i = 0; i < N; ++i)
        std::cout << "a[" << i << "]:" << a[i] << std::endl; 
}

