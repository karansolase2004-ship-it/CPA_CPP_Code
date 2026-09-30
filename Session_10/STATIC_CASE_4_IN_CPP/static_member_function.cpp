#include <cstdio>

void func1(void);
static void func2(void);

namespace X{
    void func3(void){
        puts("In X::func3()");
    }
}

class Test{
    private:
        double d1, d2;
    public :
        void xyz(int p, int q){
            printf("Test::xyz():p=%d, q = %d\n", p, q);
            printf("this = %llu\n", (unsigned long long)this);
        }

        static void uvw(int a, int b){
            printf("Test::uvw():a = %d, b = %d\n", a,b);
        }
};


int main (void){
    func1();
    func2();
    X::func3();

    Test t;
    printf("main():&t = %llu\n", (unsigned long long)&t);
    t.xyz(1000, 2000);

    t.uvw(3000, 4000);
    Test::uvw(3000, 4000);

    return 0;
}

void func1(void){
    puts("In func1()");
}

static void func2(void){
    puts("In func2()");
}
