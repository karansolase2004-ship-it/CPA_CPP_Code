#include <iostream> 

class HasPtr{
    private: 
        int n; 
        int* ptr; 
        static int ref_count; 

    public: 
        HasPtr(int _n, int _val) : n(_n), ptr(new int(_val)){
            ref_count += 1; 
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
            if(ref_count == 0){
                std::cout << "Deleting the ptr" << std::endl; 
                delete ptr; 
            }
        }
}; 

int HasPtr::ref_count = 0; 

void test(void); 

int main(void){
    HasPtr* p1 = new HasPtr(10, 20); // 1 
    HasPtr* p2 = new HasPtr(*p1); // 2 
    HasPtr* p3 = new HasPtr(*p1); // 3 

    p1->show_ref_cnt("On p1:"); // 3
    p2->show_ref_cnt("On p2:"); // 3
    p3->show_ref_cnt("On p3:"); // 3  

    delete p1; 
    p2->show_ref_cnt("On p2:"); // 2
    p3->show_ref_cnt("On p3:"); // 2

    delete p2; 
    p3->show_ref_cnt("On p3:"); 

    delete p3;
    p3->show_ref_cnt("On p3:");  
printf("\n---------------------------------\n");
    test(); 

    return (0); 
}

void test(void){
    HasPtr hp1(10, 20);     // 1 
    HasPtr hp2(hp1);        // 2 
    HasPtr hp3(hp2);        // 3 

    HasPtr hp4(100, 200);   // I want ref count of memory block 
                            // storing 200 to be 1 
    HasPtr hp5(hp4);        // ref count for hp4 and hp5 should be 2 

    hp1.show_ref_cnt("on hp1"); 
    hp2.show_ref_cnt("on hp2"); 
    hp3.show_ref_cnt("on hp3");
    hp4.show_ref_cnt("on hp4");
    hp5.show_ref_cnt("on hp5");
}