#include <iostream> 
#include <cstdlib> 

class range{
    private: 
        int n_start; 
        int n_end; 
    public: 
        class iterator; // forward 

        range(int _start, int _end) : n_start(_start), n_end(_end){
            if(n_start >= n_end){
                std::cout << "start must be less than end" << std::endl; 
                exit(EXIT_FAILURE); 
            }
        }

        iterator begin() const{
            iterator iter(n_start); 
            return iter; 
        }       

        iterator end() const{
            iterator iter(n_end); 
            return iter; 
        }

        class iterator{
            private: 
                int current_n; 
            public: 
                iterator(int _n) : current_n(_n){
                }

                int& operator*(){
                    return current_n; 
                }

                iterator operator++(){
                    current_n += 1; 
                    return *this; 
                }

                iterator operator++(int){
                    iterator tmp(current_n); 
                    current_n += 1; 
                    return tmp; 
                }

               
                iterator operator--(){
                    current_n -= 1; 
                    return *this; 
                }

                iterator operator--(int){
                    iterator tmp(current_n); 
                    current_n -= 1; 
                    return tmp; 
                }

                bool operator==(const iterator& rhs){
                    return current_n == rhs.current_n; 

                }

                bool operator!=(const iterator& rhs){
                    return current_n != rhs.current_n; 

                }
        }; 
}; 

int main(void){
    range R(10, 20); 

    range::iterator iter = R.begin(); 
    std::cout << "*iter:" << *iter << std::endl;

    while(iter != R.end()){
        std::cout << "*iter=" << *iter << std::endl;
        ++iter; 
    }

    std::cout << "using for loop" << std::endl;

    for(
        range::iterator iter = R.begin(); 
        iter != R.end(); 
        ++iter
    )
    {
        std::cout << "*iter:" << *iter << std::endl; 
    }
    return 0; 
}

// MODULAR 
// range.hpp, range.cpp, userange.cpp
// cl /c range.cpp 
// lib range.obj
// range.lib 

// cl /EHsc /Fe:app.exe userange.cpp range.lib
// app.exe

/* 

 */

/* 
print -> 10
10+5 = 15;
15+1 = 16;
16+5 = 21;
21+5 = 26;
 */