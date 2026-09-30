#include <iostream> 
#include <vector> 
#include <list> 

void test_vector(void); 
void test_list(void); 

int main(void){
    test_vector(); 
    test_list(); 
    return 0; 
}

void test_vector(void){
    std::vector<int> ivec; 

    for(int data = 10; data <= 50; data += 10)
        ivec.push_back(data); 

    std::vector<int>::iterator iter = ivec.begin(); 
    while(iter != ivec.end()){
        std::cout << "*iter=" << *iter << std::endl; 
        ++iter; 
    }
}

void test_list(void){
    std::list<float> flist; 

    for(float data = 1.1; data <= 5.5; data += 1.0)
        flist.push_back(data); 

    std::list<float>::iterator iter = flist.begin(); 
    while(iter != flist.end()){
        std::cout << "*iter:" << *iter << std::endl; 
        ++iter; 
    }
}

