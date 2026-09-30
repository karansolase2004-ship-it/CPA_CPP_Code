#include <iostream> 
#include <cstdlib> 

struct IntPtr{
    friend class HasPtr; 
    
    private: 
        int* ptr; 
        unsigned int ref_count;

        IntPtr(int _val) : ptr(new int(_val)), ref_count(1){
        }

        ~IntPtr(){
            free(ptr); 
        }
}; 

class HasPtr{
    private: 
        int n; 
        IntPtr* pIntPtr; 
    public: 
        // Parameterised constructor 
        HasPtr(int _n, int _val) : n(_n), pIntPtr(new IntPtr(_val)){
        }

        // Copy constructor 
        HasPtr(HasPtr& other) : n(other.n), pIntPtr(other.pIntPtr){
            pIntPtr->ref_count += 1; 
        }

        // Copy assignment operator 
        HasPtr& operator=(HasPtr& other){
            if(this != &other){
                pIntPtr->ref_count -= 1; 
                if(pIntPtr->ref_count == 0)
                    delete pIntPtr; 
                n = other.n; 
                pIntPtr = other.pIntPtr; 
                pIntPtr->ref_count += 1; 
            }

            return *this; 
        }

        // Destructor 
        ~HasPtr(){
            pIntPtr->ref_count -= 1; 
            if(pIntPtr->ref_count == 0)
                delete pIntPtr; 
        }

        unsigned int getrefcount() const {
            return pIntPtr->ref_count; 
        } 
}; 

void test(void); 

int main(void){
    test(); 
    return EXIT_SUCCESS; 
}

void test(void){
    puts("****HasPtr* p1 = new HasPtr(100, 200);****"); 
    HasPtr* p1 = new HasPtr(100, 200); 
    printf("test():addr in p1:%p\n", p1); 
    printf("test():p1->getrefcount():%u\n", p1->getrefcount()); 
    
    puts("****HasPtr* p2 = new HasPtr(*p1);****"); 
    HasPtr* p2 = new HasPtr(*p1); 
    printf("test():addr in p2:%p\n", p2); 
    printf("test():p1->getrefcount():%u\n", p1->getrefcount()); 
    printf("test():p2->getrefcount():%u\n", p2->getrefcount()); 

    puts("****HasPtr* p3 = new HasPtr(*p1);****"); 
    HasPtr* p3 = new HasPtr(*p1); 
    printf("test():addr in p3:%p\n", p3); 
    printf("test():p1->getrefcount():%u\n", p1->getrefcount()); 
    printf("test():p2->getrefcount():%u\n", p2->getrefcount()); 
    printf("test():p3->getrefcount():%u\n", p3->getrefcount()); 

    puts("****HasPtr* p4 = new HasPtr(1000, 2000);****"); 
    HasPtr* p4 = new HasPtr(1000, 2000); 
    printf("test():addr in p4:%p\n", p4); 
    printf("test():p4->getrefcount():%u\n", p4->getrefcount()); 

    puts("****|*p4 = *p2;|****"); 
    *p4 = *p2; 
    printf("test():p1->getrefcount():%u\n", p1->getrefcount()); 
    printf("test():p2->getrefcount():%u\n", p2->getrefcount()); 
    printf("test():p3->getrefcount():%u\n", p3->getrefcount()); 
    printf("test():p4->getrefcount():%u\n", p4->getrefcount()); 

    delete p1; 
    p1 = 0; 

    delete p2; 
    p2 = 0; 

    delete p3; 
    p3 = 0; 

    delete p4; 
    p4 = 0; 
}