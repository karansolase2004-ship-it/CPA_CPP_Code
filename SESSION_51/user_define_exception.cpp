#include <iostream>
#include <stdexcept>
#include <cstdio> 
#include <cstdlib> 
 
class usage_error : public std::runtime_error{
    public: 
        usage_error(const char* msg) : std::runtime_error(msg){
        }
}; 

class os_error : public std::exception{
    public: 
        os_error(const char* msg) : std::exception(msg){
        }
}; 

class file_not_found_error : public os_error{
    public: 
        file_not_found_error(const char* msg) : os_error(msg){
        }
}; 


FILE* get_file_handle(const char* file_path); 

int main(int argc, char* argv[]){ 
    FILE* fp = NULL; 
    if(argc != 2)
        throw usage_error("bad usage: #app.exe file_path");

    try{
        fp = get_file_handle(argv[1]);
    }catch(const file_not_found_error& exc){
        std::cout << exc.what() << std::endl; 
        exit(EXIT_FAILURE); 
    }
    
    fclose(fp); 
    fp = NULL; 

    return (0); 
}

FILE* get_file_handle(const char* file_path){
    FILE* fp = fopen(file_path, "r"); 
    if(fp == NULL)
        throw file_not_found_error("Non-existent file path"); 

    return fp; 
}
