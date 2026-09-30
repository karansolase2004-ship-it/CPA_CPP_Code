#include <iostream>
#include <cstdlib>

struct Date
{
    int day;
    int month;
    int year;
};

struct temp
{
    double x, y;
};

int main (void)
{
    int* ptr = NULL;

    ptr = malloc(sizeof(int)); 
    // Implicit type conversion
    // Void* to T* not allowed in cplus plus
    ptr = static_cast<int*>(malloc(sizeof(int)));

    struct Date myDate;

    ptr = reinterpret_cast<int*>(&myDate); 
    // Above is not allowed in C language. because reinterpret_cast is not valid in C. Instead, C uses implicit pointer conversions or explicit casts using (type*). given in below way.
    ptr = (int*)(&myDate); 
}