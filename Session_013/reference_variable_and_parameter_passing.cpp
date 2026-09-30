#include <stdlib.h>
//assignemnt statement: lhs = rhs
//type(rhs) == type(lhs)

///////////////////////////////////////////////////////////////

void test1(int m);
void test2(int *p);
void test3(int& ref);

int test4(void);
int* test5();
int& test6();
/////////////////////////////////////////////////////////////

int main (void){
    int n = 500;

    test1(n);
    test1(1000);

    test2(&n); //int* p = &n // ok // param passing ok
    test2(1000);  // int*p = 1000; // error // param passing error

    test3(n); // int& ref = n // ok // param passing ok
    test3(1000); // int& ref = 1000; // error // param passing error
}

/////////////////////////////////////////////////////////////

//format_param = actual_param

// int  m = n;
// int m = 1000;

///////////////////////////////////////////////////////////////

int test4(void){
    int n;
    return 100; //ok
    return n;  // ok
}

int* test5(){
    int n; 

    return &n;
}

// int* tmp

int& test6(){
    return 1000; // error
}

// int& tmp = 1000; // error // return error

int& test6(){
    int n = 1000;

    return n; //dangling
}

//int& tmp = n;

int& test6(){
    static int n;

    return n;
}

int& test6(){
    int* p = (int*)malloc(sizeof(int));

    return  *p;
}

// int& tmp = *p;

int test6(){
    int* p =(int*)malloc(sizeof(int));
    *p = 1000;
    return  *p; //Memory leak
}

int main (void){
    int ret;

    ret =test6();
}

// int tmp = *p;

////////////////////////////////////////////////////////////////

//int tmp = 100;
// int tmp = n;

int n =10;

int*p;  // int n; &n
        // malloc(sizeof(int));


// type -> memory bloxk -> address hold -> pointer

/////////////////////////////////////////////////////////////

int* f(){
    int *p;

    return *p;
}

////////////////////////////////////////////////////////////

int* f(){
    int n;

    return &n;
}

// int* tmp = &n;
//////////////////////////////////////////////////////////////
int* f1(){
    static int n;

    return &n; // ok
}
 
//////////////////////////////////////////////////////////////

int* f2(){
    int* p = (int*)malloc(sizeof(int));
    return (p); //ok
}

///////////////////////////////////////////////////////////////////

// Understanding and using C pointer -> richard reese
// oreilly publication
//chapter 5 : Arrays and pointers.