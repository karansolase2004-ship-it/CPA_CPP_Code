#include "cpa_list.hpp"
#include "cpa_list_exceptions.hpp"

// this function wont be called 
void test(cpa::dsa::list& L){
   try{
        int data = L.get_start(); 
        L.insert_after(-100, 100);
    }/* catch(const  std::runtime_error& exc){
        std::cout << exc.what() << std::endl; 
    } */catch(const list_empty& exc){
        std::cout << exc.what() << std::endl;
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl; 
        std::cout << "Un-anticipated error" << std::endl; 
    }
    printf("hello");
    try{
        L.insert_before(-100, 100);
    }catch(const std::runtime_error& exc){
        std::cout << exc.what() << std::endl;
    }
}

int main(void){
    cpa::dsa::list L; 
    int data; 

    std::cout << "main():try to get data from empty list" << std::endl; 
    try{
        data = L.get_start(); 
    }catch(const list_empty& exc){
        std::cout << exc.what() << std::endl; 
    }

    for(data = 0; data < 5; ++data)
        L.insert_end(data); 

    std::cout << "main():Try to insert after non-existent data" << std::endl; 
    try{
        L.insert_after(-100, 100); 
    }catch( const list_invalid_data& exc){
        std::cout << exc.what() << std::endl;
    }

    test(L);
    return EXIT_SUCCESS;    
}