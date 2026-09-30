#// This code demonstrates existence of destructor but 
// not its use case 

#include <cstdio>

class Test{
    private : 
        int num;
        char c;
        float f_num;
    public : 
       Test(){
        puts("In Test::Test()"); //ctor
        printf("Test::Test():this = %llu\n", 
            (unsigned long long)this);
       }

       ~Test(){
        puts("In Test::~test"); //dtor
        printf("Test::~Test():this = %llu\n", 
             (unsigned long long)this);
       }
};

/* class -> object 
Struct Test{
    int num;
    char c;
    float f_num;
};

pTest = new Test;
==
{
struct Test* pTest = malloc(sizeof(struct Test));
Test::TEst(pTest);
}

delete pTest;
==
{
    Test::~Test(pTest);
    free(pTest);
}

struct Test* pTest = malloc(sizeof(struct Test));

pTest = NULL; //Memory Leak !!!
//VALEGRIND

free(pTest);
 */


int main (void){
    Test* pTest = 0;

    pTest = new Test;

    printf("main():pTest:%llu\n", (unsigned long long)pTest);

    delete pTest;
    pTest = 0;

    return 0;
}