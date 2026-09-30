#include <cstdio>
#include <cstdlib>

const int gc_num = 100;
int g_num = 15;

int main (void){
    void types_1();
    return 0;
}

void types_1(){
    int l_num;
    const int lc_num = 200;

    // 1)
    int* p1 = &l_num;
    // p1 = &lc_num; // error : const int* to int*
    // but possible using const cast
    p1 = &g_num;
    // p1 = &gc_num; // error : const int* to int*
    // also not possible using const cast 
    // otherwise error :  memory violation exception error

    // 2) 
    const int* p2 = &l_num;
    p2  = &gc_num;
    p2 = &g_num;
    // All ok because p2 will not write any variable only read

    //3) 
    int* const p3 = &l_num; 
    int* const p5 = &lc_num;
    int* const p6 = &lc_num;
    int* const p7 = &g_num;
    // p3 = &lc_num;
    // p3 = &gc_num;
    // p3 = &g_num;
    //  because p3 can not be modified.

    // 4) 
    const int* const p4 = &l_num; // &gc_num // &g_num // &lc_num;
    // p4 = &lc_num;
    // p4 = &gc_num;
    // p4 = &g_num;
    //  because p4 can not be modified. 
}




/* 

because p4 can not be modified. 
*/