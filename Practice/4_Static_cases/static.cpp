#include <cstdio>

void Test(void);

class Test{
    private :
       int m;
    static int n; // Declaration static n
    //const int l; // intializer syntax must be there 
    public : 
      Test() : m(-1), n(-1){
        printf("\nInside the constructor\n");
        printf("m = %d\n", m);
        printf("Outside the constructor\n");
        printf("--------------------------------------------------");
      };

      void write(int a, int b){
        printf("\nInside the write member function\n");
        m = a; // this->n = a;
        n = b; // Test::k = b; i.e n is accessible because it is declared gloabally
        printf("m = %d,\nn =%d\n",m, n);
        printf("Write member function ends\n");
        printf("--------------------------------------------------");
      };

      static void write(){
        // a nonstatic member reference must be relative to a specific object
         // m = 900; 
         // j  = 0;
         //  because  static function has no this pointer available 
        n = 9; // n is accessible because it is gloablly declared.
        k = 4;
        printf("\nInside the static write function : \n");
        printf("n = %d\nk = %d\n",n, k);
        printf("--------------------------------------------------");
        Test t3;
        t3.m = 9;
        t3.n = 8;
        printf("\nt3.m = %d\nt3.n = %d\n", t3.m, t3.n);
        printf("static write function ends\n");
        printf("--------------------------------------------------");
      }
      static int k; // Declaration static k
      int j;
};

int Test::n; 
int Test::k;
// ^ Definition of static n and k

int main (void){
    Test t1;

    printf("\nsizeof(t1) :%d\n"
    "this proves that static int n does not consist memory allocation\n", 
    sizeof(t1));
    printf("--------------------------------------------------");

    t1.write(15, 13);
    t1.write();
    
    Test::write();

    test();
    // c = 9; // static function is accessible only to that function 
    
    Test::k = 0;
    printf("%d\n", Test::k);
}

void test(void){
    printf("\nInside the test() function");
    static int c;
    // Test::n = 9; // despite n is globally declared but not accessible 
    // because it is private. 
    Test::k = 8;
    Test t4;
    printf("\nTest::k = %d",Test::k);
    // printf("\nTest::k = %d",t4.m);
    printf("\nOutside the test function\n");
    printf("--------------------------------------------------");
}

