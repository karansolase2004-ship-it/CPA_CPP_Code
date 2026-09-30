#include <cstdio>
#include <cstdlib>

void test_function_1(void);
void test_function_2(void);


const int gc_num = 100; //GLOBAL + CONST
int g_num;  // GLOBAL

int main (void){
    test_function_1();
    test_function_2();

    return 0;
}

void test_function_1(void){
    int m1, m2 ,m3;
    int* p1; //non const pointer to non_const data

    p1 = &m1; //through p1, m1 cab be r/w
               // p1 = &m2; p1 = &m3;
              // theough p1, m2 and m3 can be r/w
            
    const int* p2 = &m2; // thorugh p2, m2 can be r and NOT w
    int const* p3 = &m3; // through p3, m3 can be r and NOT w

    //p2 = &m2; p2 = &m3 is possible because the pointer itself is not const
    // p3 = &m1; p3 = &m2 is possible because the pointer itself is not const

    int* const p4 = &m1;  // thorugh p4, m1 can be r/w
    *p4 = 9;
                        // p4 = &m2; p4 = &m3 is not possible because p4
                         // is a const pointer 

    const int* const p5 = &m1;  // thorugh p5, m1 can be r NOT w
                                // p5 = &m2; p5=&m3 is not possible
                                // because p5 is a const pointer 
}

void test_function_2(void){
    int l_num;
    const int lc_num = 200;

    int* p1 = &l_num; // OK
    p1 = &g_num; // ok

    // p1 = &lc_num;  // error: const int* to int*
    // if backdoor is created using const cast 
    // it will work because lc_num is local 

    // p1 = &gc_num; // error
    // if backdoor is created using const cast
    // it wont work because gc_num is a global const
    // which is allocated in h/w protected real only area

    const int* p2;

    p2 = &g_num; // thorugh p2, g_num can be r and NOT w
    p2 = &l_num; // though p2, l_num can be r and NOT w
    p2 = &gc_num; // through p2 gc_num can be r and not w
    p2= &lc_num; // through p2 lc_num can be r and not w

    int* const p3 = &l_num;  //  thorugh p3, l_num can be r, w
    int* const p4 = &g_num; // through p4, g_num can be r , w

    // p3 = &g_num; //error
    // p4 = &l_num; //error

    // p3 = &lc_num;
    //p3 = &gc_num; // error : const int* to int*
    // if const_cast is used to override CTE
    // the addrof lc_num and gc_num can be put in p3
    // but attempt to write through p3
    // will fail for gc_num will succeed of lc_num

    const int* const p5 = &l_num;  // ok
    const int* const p6 = &g_num; //ok
    const int* const p7 = &lc_num; // ok
    const int* const p8 = &gc_num; // ok
}

