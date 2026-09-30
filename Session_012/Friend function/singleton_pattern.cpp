#include <iostream>
#include <stdexcept>

class Singleton{
    private :
       int i_num;
       double d_num;

       Singleton(int _n, double _d): i_num(_n), d_num(_d){

       }

       static int obj_cnt;

    public:
      static Singleton* get_instance(int _n, double _d){
        ++obj_cnt;

        if (obj_cnt > 1)
            throw std::runtime_error("Only one object of this class can be created");
        
        return new Singleton(_n, _d);
      }

};

int Singleton::obj_cnt = 0;

void test_singleton(void);

int main (void){
    test_singleton();
    return 0;
}


void test_singleton(void){
    Singleton* pSingleton_1 = Singleton::get_instance(100, 3.1415);
    std::cout <<"First object of Singleton class is created" <<std::endl;

    try{
        Singleton* pSingleton_2 = Singleton::get_instance(100, 6.2628);
    }catch(std::runtime_error& e){
        std::cout << e.what() <<std::endl;
    }

    delete pSingleton_1;
    pSingleton_1 = 0;
}

