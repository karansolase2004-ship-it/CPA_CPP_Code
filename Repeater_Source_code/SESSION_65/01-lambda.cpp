#include <iostream> 

void test_lambda(void); 
double get_square(double); 

int main(void)
{
    test_lambda(); 
    return 0; 
}

double get_square(double x)
{
    return x * x; 
}

void test_lambda(void)
{
    // We writing lambda corrossponding to get_square() function 
    // which is written above     
    [](double x) -> double{        
        return x * x; 
    };
    
    // How do I access a function which I have implemented 
    // from line 21-23? 
    // Option 1: Name the function. Technically it can work. 
    // Design-wise, this option is flawed. Because lambda is 
    // at its root an anonymous function. By naming it, you are 
    // violating the core concept. 
    /* 
        auto get_square = [](double x) -> double {return x * x;}
    
    */
    // Option 2: Call it immediately after definition 

    
    double return_val = [](double x) -> double {
        return x * x;
    } (5.0); 

    std::cout << "Return Value:" << return_val << std::endl; // 25.0
}

/* 
    double get_sqaure(double x){
        return x * x; 
    }

    double (double x){
        return x * x; 
    }

    [](double x) -> double {
        return x * x; 
    }; 

    // Generalized syntax of lambda expression 
    [capture list](formal parameter list) -> return_type_annotation {
        // body 
    };
    
    return_type_annotation return_val = [capture list](formal parameter list) -> return_type_annotation {
                                                // body 
                                        }(actual_parameter_list compatible with formal_parameter_list);
    

*/