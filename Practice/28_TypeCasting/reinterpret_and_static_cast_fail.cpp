#include <iostream>

class A{
    private :
    int a;
    char b;
    float c;
};

class B
{
    private :
    double x, y;
};

int main (void)
{
    B objB;

    const int n = 0;
    volatile int j = 234;

    int* ptr_1 = reinterpret_cast<int*>(&objB);

    int* ptr_2 = reinterpret_cast<int*>(&n);
    int* ptr_3 = reinterpret_cast<int*>(&j);

    int* ptr_4 = static_cast<int*>(&n);
    int* ptr_5 = static_cast<int*>(&j);

    int* ptr_6 = (int*)(&objB);
    int* ptr_7 = (int*)(&n);
    int* ptr_8 = (int*)(&j);

    // Above three Statements are wokring because it is c style type casting

    return (0);
}