#include <stdexcept>

class list_invalid_data : public std::runtime_error{
    public : 
    list_invalid_data(const char* msg) : std::runtime_error(msg){

    }
};

class list_empty : public std::runtime_error{
    public : 
    list_empty(const char* msg) : std::runtime_error(msg){

    }
};
