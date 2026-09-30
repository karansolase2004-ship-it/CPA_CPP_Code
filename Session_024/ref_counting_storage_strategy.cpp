#include <iostream> 
#include <cstdlib> 

struct IntPtr{
    int* p; 
    int ref_count; 
}; 

class HasPtr{
    private: 
        int n; 
        struct IntPtr* pIntPtr; 
    public: 
        HasPtr(int _n, int _val) : n(_n){
            pIntPtr = (struct IntPtr*)malloc(sizeof(struct IntPtr)); 
            if(pIntPtr == 0){
                std::cout << "AllocationError:struct IntPtr" << std::endl; 
                exit(EXIT_FAILURE); 
            }
            pIntPtr->p = (int*)malloc(sizeof(int)); 
            if(pIntPtr->p == 0){
                std::cout << "AllocationError:int" << std::endl; 
                exit(EXIT_FAILURE); 
            }
            pIntPtr->ref_count = 1;
            *pIntPtr->p = _val; 
        }

        HasPtr(const HasPtr& other) : n(other.n), pIntPtr(other.pIntPtr){
            pIntPtr->ref_count += 1; 
        }

        HasPtr& operator=(const HasPtr& other){
            if(this != &other){
                this->pIntPtr->ref_count -= 1; 
                if(this->pIntPtr->ref_count == 0){
                    free(this->pIntPtr->p); 
                    free(this->pIntPtr); 
                }

                this->n = other.n; 
                this->pIntPtr = other.pIntPtr; 
                this->pIntPtr->ref_count += 1; 
            }
            return *this; 
        }

        ~HasPtr(){
            this->pIntPtr->ref_count -= 1; 
            if(this->pIntPtr->ref_count == 0){
                free(this->pIntPtr->p); 
                free(this->pIntPtr);
            }
        }

        void show_ref_cnt(const char* msg) const{
            std::cout << msg << std::endl;
            std::cout <<"Ref cnt:" << pIntPtr->ref_count << std::endl; 
        }

        void show_ptr_val(){
            printf("%d\n", *this->pIntPtr->p);
        }

        IntPtr* show_adr(){
            return this->pIntPtr;
        }
}; 

void test(void); 

int main(void){
    test(); 
    return EXIT_SUCCESS; 
}

void test(void){
    HasPtr* p1 = new HasPtr(100, 200); 
    p1->show_ref_cnt("On p1:");

    HasPtr* p2 = new HasPtr(*p1); 
    p2->show_ref_cnt("On p2:");
    
    HasPtr* p3 = new HasPtr(*p1); 
    p3->show_ref_cnt("On p3:");

    printf("p3 address : %d = p2 Address %d = p1 Address %d\n", p3->show_adr(), p2->show_adr(), p1->show_adr());

    HasPtr* p6 = new HasPtr(50, 60);
    p6->show_ref_cnt("on p6: ");

    *p6 = *p3;
    p6->show_ref_cnt("On p6:");
    
    HasPtr* p4 = new HasPtr(1000, 2000); 
    p4->show_ref_cnt("On p4:");
    
    HasPtr* p5 = new HasPtr(*p4);
    p5->show_ref_cnt("On p5:");

    printf("p4 address : %d = p5 Address %d\n", p4->show_adr(), p5->show_adr());

    // p4->show_ptr_val();
}

/*
    CLAIRTY IS BETTETER THAN CLEVERNESS! 
*/