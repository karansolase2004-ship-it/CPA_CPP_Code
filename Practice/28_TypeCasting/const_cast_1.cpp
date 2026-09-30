#include <iostream>

void use_case_1(void);
void use_case_2(void);
void print_value(const int& val);

int main (void)
{
    use_case_1();
    use_case_2();

    return (0);
}

void use_case_1(void)
{
    std::cout << "------- USe Case 1 : --------" << std::endl;
    
    const int num = 100;
    int* p_num;

    p_num = const_cast<int*>(&num);

    std::cout << "BEFORE : " << *p_num << std::endl;
    *p_num = 500;
    std::cout << "After : " << *p_num << std::endl;
}

void use_case_2(void){
    int x = 10;
    print_value(static_cast<const int&>(x));

    x = 20;
}

void print_value(const int& val)
{
    std::cout << "Value : " << val << std::endl;
}