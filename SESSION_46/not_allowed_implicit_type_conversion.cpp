#include <iostream> 
#include <cstdlib> 

struct Date{
    int day;
    int month; 
    int year;
};

struct temp{
  double x, y;
};

int main(void){
    int* ptr = NULL; 

    ptr = malloc(sizeof(int));  // implicit type conversion 
                                // from void* (rhs type)
                                // to T* (lhs_type) is not 
                                // allowed 

    struct Date pDate;
    struct temp* p_temp = &pDate;

    struct Date mydate;
    int p;
    int* ptr_2 = NULL;
    float f = 0.00;
    ptr_2 = reinterpret_cast<int*>(&mydate);
    void* ptr = &p;
    void* ptr_1;

    int* ptr = ((void*)0);
    int* temp = NULL;

    ptr_1 = &f;
  return (0); 
}



