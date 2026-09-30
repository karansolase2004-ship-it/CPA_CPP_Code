#include <iostream>
#include <cstdlib>

struct intptr{
    friend class hasptr;

    private :
      int* ptr;
      unsigned int ref_count;

      intptr(int _val) : ptr(new int(_val)), ref_count(1){

      };

      ~intptr(){
        free(ptr);
      }
};

class hasptr{
    private :
       int n;
       intptr* pintptr;

    public :
       hasptr(int _n, int _val):n (_n), pintptr(new intptr(_val)){

       };

       hasptr(hasptr& other): n(other.n), pintptr(other.pintptr){
        pintptr->ref_count += 1;
       }

       hasptr& operator=(const hasptr& other){
        if(this != &other){
            pintptr->ref_count -= 1;
            if(pintptr->ref_count == 0){
                delete pintptr;
            }
            n = other.n;
            pintptr = other.pintptr;
            pintptr->ref_count += 1;
        }
        return *this;
       }

       ~hasptr(){
        pintptr->ref_count -= 1;
        if(pintptr->ref_count == 0){
            delete pintptr;
        // OR : 
        /* if(--this->pintptr->ref_count == 0){
            delete pintptr;
        } */
        }
       }

       void all(const char* msg) const{
         if(msg){
                puts(msg);
            }
        printf("Address in ptr  =%d\n",pintptr->ptr);
            printf("ptr value :%d\n", *pintptr->ptr);
            printf("ref_count = %d\n", pintptr->ref_count);
        }

};



void test(void){
    hasptr* p1 = new hasptr(100, 200);
    p1->all("on p1 :");
    hasptr* p2 = new hasptr(*p1);
    p2->all("on p2 :");
    hasptr* p3 = new hasptr(100, 200);
    p3->all("on p3:");
    *p3 = *p1;
    p3->all("on p3 :");

    hasptr* p4 = new hasptr(1000, 2000);
    p4->all("on p4");
    hasptr* p5 = new hasptr(4500, 5600);
    p5->all("on p5 :");

    *p5 = *p4;
    p5->all("on p5 :");
    p4->all("on p4 :");

    delete p1;
    p1 = NULL;

    delete p2;
    p2 = NULL;

    delete p3;
    p3 = NULL;

    delete p4;
    p4 = NULL;

    delete p5;
    p5 = NULL; 
}

int main (void){
    test();
}
