#include <iostream> 
#include <cstdlib> 
#include <cmath> 

auto func(); 

int main(void){
    
}

auto func(){
    srand(time(0)); 
    switch(rand()%3){
        case 0: 
            return 'a';
        case 1: 
            return 'b'; 
        case 2: 
            return 'c'; 
    }
}