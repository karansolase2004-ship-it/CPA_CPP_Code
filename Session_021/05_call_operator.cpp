#include <iostream> 

int add(int, int);  
int sub(int, int); 

class ArithmeticOperators{
    private: 
        int (*ptr_function)(int, int); 
    public: 
        ArithmeticOperators() : ptr_function(0){
        }

        void set(  int (*pfn)(int, int) ){
            ptr_function = pfn; 
        }

        int operator()(int op1, int op2){
            return ptr_function(op1, op2); // (*ptr_function)(op1, op2); 
        }
}; 

int main(void){
    ArithmeticOperators ao; 

    ao.set(add); 

    int ret = ao(100, 200); // ArithmeticOperators::opeartor(&ao, 100, 200)
    std::cout << "add:ret:" << ret << std::endl; // 300 

    ao.set(sub); 
    ret = ao(200, 100);
    std::cout << "sub:ret:" << ret << std::endl; 

    return 0;  
}

int add(int a, int b){
    return a + b; 
}

int sub(int a, int b){
    return a - b; 
}

/* for(std::vector<int>::iterator iter = ivec.begin(): 
    iter != ivec.end(); 
    ++iter)
    *iter;  */