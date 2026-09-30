#include <cstdio>

class Test{
    private : 
       int m;
       int k;
       static int n;

    public :
    int l;
       Test() : m(-1), k(-1){

       }

       void w_member_function(int a, int b, int c){
        m = a;  //this->m == a;
        k = b;  // this->k == b;
        n = c;  //Test :: n == c
       }

       void r_member_function(){
        printf("m =%d, k = %d, n =%d\n", m , k, n);
       }

       static void static_member_function(){
         // m = 100; //CTE
         // k = 200; //CTE
         n = 500; //Test::n == 500
         // l =0; 

         Test t3;

         t3.m = -100;
         t3.k = -200;
       }

       static int pub_n;
};

int Test::n = 100;
int Test::pub_n = 500;

int main (void){
    //1 : static datamember does not partcipate in object allocation
    Test t1, t2; // t1.m == -1, t1.k==-1, t2.m==-1, t2.k==-1

    printf("Sizeof(t1):%zu, sizeof(t2):%zu\n", 
            sizeof(t1), sizeof(t2));

    t1.r_member_function();  // -1, -1, 100
    t2.r_member_function();  // -1, -1, 100

    t1.w_member_function(1000, 2000, 4000);
    t2.r_member_function();  // inter object communication is proved
    t1.r_member_function(); 

    Test::pub_n = 1000; // Accessing
    printf("Test::pub_n = %d\n", Test::pub_n);
    Test::n; //CTE private
    
    return 0;
}