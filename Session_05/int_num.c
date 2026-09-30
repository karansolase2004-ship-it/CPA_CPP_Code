int num;

struct A{
    int m;
};

void test(void){
    int x;

    x = num;
    num = x + 8;

    m = 100;

    struct A inA;
    struct A* pA = malloc(sizeof(struct A));

    inA.m;
    pA->m;
}

void fun(void){
    
}

class A{
    public:
        void func(){

        }
};

int main(void)
{
    A objA;
    A* pA = new A;

    objA.func();
    pA->func();

    fun();
}