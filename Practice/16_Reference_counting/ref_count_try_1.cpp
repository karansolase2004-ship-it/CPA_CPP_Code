#include <iostream> 

class HasPtr{
    private: 
        int n; 
        int* ptr; 
        int ref_count; 

    public: 
        HasPtr(int _n, int _val) : n(_n), ptr(new int(_val)), ref_count(1){
        }

        HasPtr(HasPtr& other) : n(other.n), ptr(other.ptr){
            other.ref_count += 1; 
            ref_count = other.ref_count; 
        }

        void show_ref_cnt(const char* msg) const {
            std::cout << msg << std::endl; 
            std::cout << "Ref Cnt:" << ref_count << std::endl; 
        }

        ~HasPtr(){
            std::cout << "In Dtor:ref_count:" << ref_count << std::endl; 
            ref_count -= 1; 
            if(ref_count == 0)
                delete ptr; 
        }
}; 

int main(void){
    HasPtr* p1 = new HasPtr(10, 20); 
    HasPtr* p2 = new HasPtr(*p1); 
    HasPtr* p3 = new HasPtr(*p1); 

    HasPtr* p4 = new HasPtr(40, 50);
    HasPtr* p5 = new HasPtr(*p4);

    p1->show_ref_cnt("On p1:"); // 3
    p2->show_ref_cnt("On p2:"); // 2
    p3->show_ref_cnt("On p3:"); // 3  

    delete p1; 
    p2->show_ref_cnt("On p2:"); // 2
    p3->show_ref_cnt("On p3:"); // 3  

    return (0); 
}