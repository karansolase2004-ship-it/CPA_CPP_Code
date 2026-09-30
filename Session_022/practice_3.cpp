#include <cstdio>
#include <cstdlib>
#include <iostream>

class hasptr{
    private :
      int n;
      int* ptr;
    
    public :
       hasptr(int _n, int val) : n(_n), ptr(new int(val)){

       }

       void process(){
        printf("\n%d\n", *(this->ptr));
       }

       void show(){
        printf("\nn = %d\n*ptr = %d\n", n, *ptr);
       }
};

void test(void){
    hasptr* hp1 = NULL;
    hp1 = new hasptr(10, 20);
    if (NULL == hp1){
        puts("Error in allocating the memory");
        exit(-1);
    }
    
    printf("Before delete");
    hp1->show();
    delete hp1;
    hp1->show();
    printf("After delete");
    hasptr hp2(*(hp1));
    hp2.show();
    hp2.process();

    printf("bagha hotay ka ");
}

int main (void){
    test();

    return 0;
}

