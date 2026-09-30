#include <iostream>
#include <exception>

struct MyError : std::exception {
    const char* what() const noexcept override {
        return "MyError happened!";
    }
};

int main() {
    try {
        throw MyError();
    }
    catch (std::exception e) { // Caught by value (instance)
        std::cout << e.what() << "\n";
    }
}

/* 
Print std::exception in case e is instance 
& 
MyError Happened in case e is reference 
*/