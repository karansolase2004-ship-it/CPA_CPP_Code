#include <cstdio> 

class Test1{
    private: 
        int num ; 
        const int c_num; 

    public: 
        Test1() : c_num(200){
            this->num = 100; 
        }
}; 

class Test2{
    private: 
        int num; 
        const int c_num; 

    public: 
        Test2(int a, int b) : num(a), c_num(b){

        }

        void show() {
            printf("%d/%d\n", num, c_num); 
        }
}; 

int main(void){
    Test1 t1; 
    Test2 t2(100, 20000); 
    t2.show(); 
    return 0; 
}