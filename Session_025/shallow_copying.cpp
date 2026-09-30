#include <iostream> 
#include <cstdio> 
#include <cstdlib> 

struct IntPtr{
    int* ptr; 
    unsigned int ref_count; 
}; 

class HasPtr{
    private:
        int n; 
        struct IntPtr* pIntPtr; 
    public: 
        // Paramterised constructor 
        HasPtr(int _n, int _val){
            this->n = _n; 
            this->pIntPtr = (struct IntPtr*)malloc(sizeof(struct IntPtr)); 
            this->pIntPtr->ptr = (int*)malloc(sizeof(int)); 
            *this->pIntPtr->ptr = _val;
            this->pIntPtr->ref_count = 1; 
            puts("start parameterised CC"); 
            printf("New Object whose addr is %p is initialized by parameterised CC\n", this); 
            puts("end parameterised CC"); 
        }

        // Copy Constructor 
        HasPtr(HasPtr& other){
            this->n = other.n;
            this->pIntPtr = other.pIntPtr; 
            this->pIntPtr->ref_count += 1;   
            puts("start copy constructor");  
            printf("New object whose addr is %p is initialised by Copy CC:\n", this); 
            printf("Addr of existing object:%p\n", &other); 
            puts("end copy constructor"); 
        }

        // Copy Assignment Operator 
        HasPtr& operator=(HasPtr& other){
            puts("start: copy assignment operator"); 
            printf("addr of existing object at lhs: %p\n", this); 
            printf("addr of existing object at rhs: %p\n", &other); 
            if(this != &other){
                this->n = other.n; 
                this->pIntPtr->ref_count = this->pIntPtr->ref_count - 1; 
                if(this->pIntPtr->ref_count == 0){
                    printf("copy assignment operator():ref count of %p is zero\n", this); 
                    free(this->pIntPtr->ptr); 
                    free(this->pIntPtr); 
                }
                this->pIntPtr = other.pIntPtr; 
                this->pIntPtr->ref_count = this->pIntPtr->ref_count + 1; 
                puts("end: copy assignment operator"); 
            }
            return *this; 
        }

        // DESTRUCTOR 
        ~HasPtr(){
            puts("start:Destructor"); 
            this->pIntPtr->ref_count = this->pIntPtr->ref_count - 1; 
            printf("dtor():ref cnt after decr:%u\n", this->pIntPtr->ref_count); 
            if(this->pIntPtr->ref_count == 0){
                puts("dtor:FREEING"); 
                free(this->pIntPtr->ptr); 
                free(this->pIntPtr); 
            }

           
            printf("object at addr %p will be freed\n", this); 
            puts("end:destructor"); 
        }

        unsigned int getrefcount() const {
            return this->pIntPtr->ref_count; 
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