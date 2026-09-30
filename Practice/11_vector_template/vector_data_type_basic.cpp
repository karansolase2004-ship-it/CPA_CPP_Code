#include <iostream>
#include <vector>

void test_vector(void);

int main (void){
    test_vector();

    return 0;
}

void test_vector(void){
    std::vector<int> ivec;
    std::vector<double> dvec;

    ivec.push_back(100);
    ivec.push_back(200);
    ivec.push_back(300);

    dvec.push_back(1.1);
    dvec.push_back(2.2);
    dvec.push_back(3.3);
    dvec.push_back(4.4);

    int num1, num2, num3;
    num1 = ivec[0];
    num2 = ivec[1];
    num3 = ivec[2];

    std::cout << "num1 :" << num1 << std::endl
              << "num2 :" << num2 << std::endl
              << "num3 :" << num3 << std::endl;

    size_t length_ivec = ivec.size();
    std::cout << "Length(ivec):" << length_ivec << std::endl;
            
    float num01, num02, num03, num04;
    num01 = dvec[0];
    num02 = dvec[1];
    num03 = dvec[2];
    num04 = dvec[3];

    std::cout << "num1 :" << num01 << std::endl
              << "num2 :" << num02 << std::endl
              << "num3 :" << num03 << std::endl
              << "num4 :" << num04 << std::endl; 
              
    size_t length_dvec = dvec.size();
    std::cout << "Length(dvec):" << length_dvec << std::endl;

    for(std::vector<int>::size_type i=0; i != ivec.size(); ++i)
        std::cout << "ivec[" << i << "]:" << ivec[i] << std::endl;
    
    ivec.pop_back();
    ivec.pop_back();
    ivec.pop_back();

    std::cout << "Length(ivec) :" << ivec.size() << std::endl;

    for(std::vector<double>::size_type i=0; i !=dvec.size(); ++i)
        std::cout << "dvec[" << i << "]:" << dvec[i] << std::endl;  

    dvec.pop_back();
    dvec.pop_back();
    dvec.pop_back();
    dvec.pop_back();

    std::cout << "Length(dvec) :" << dvec.size() << std::endl;
}