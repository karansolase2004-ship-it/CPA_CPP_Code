#include <iostream> 
#include <cstdlib> 
#include <cassert> 
#include "Stack.hpp"

int main(void){
    Stack<5> int5Stack; 
    Stack<8> int8Stack; 
    ssize_t N = 5; 
    // Stack<N> int5Stack; // expression must have a constant value
    int data; 

    for(ssize_t i = 0; i < N; ++i) 
        assert(int5Stack.push(i*10) == SUCCESS); 

    // assert(int5Stack.push(500) == STACK_FULL); 
    std::cout << "int5Stack is now full" << std::endl; 

    assert(int5Stack.top(&data) == SUCCESS); 
    std::cout << "Last pushed data:" << data << std::endl; 

    while(!int5Stack.empty()){
        assert(int5Stack.pop(&data) == SUCCESS); 
        std::cout << "poped data:" << data << std::endl; 
    }

    assert(int5Stack.top(&data) == STACK_EMPTY); 
    std::cout << "Could not top from empty stack" << std::endl; 

    std::cout << "stack: all ok" << std::endl; 

    if(int5Stack.empty()){
        std::cout << "Stack is EMpty" << std::endl;
    }

    return EXIT_SUCCESS; 
}