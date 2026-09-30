#include <cstdio>

class hasptr{
    private :
       int n;
       int * ptr;

    public :
       hasptr(int n, int val): n(n), ptr(new int(val)){

       }

       ~hasptr(){
        delete ptr;
       }
       
       // Synthesized copy contsructor 
       hasptr(const hasptr& other) : n(other.n), ptr(other.ptr){

       }

       // Synthesized Copy Assignment operator
       hasptr& operator=(const hasptr& other){
        if(this != &other){
            n = other.n;
            this->ptr =other.ptr;
        }

        return *this;
       }

       int get_n() const{
        return n;
       }

       int get_ptr_val() const{
        return *this->ptr;
       }

       void set_n(int new_val){
        this->n = new_val;
       }

       void set_ptr_val(int new_val){
        *this->ptr = new_val;
       }

       void show(const char* msg) const {
        if(msg){
            printf("%s\n", msg);
        }
        printf("n =%d\nptr = %d\n*ptr = %d\n", n, ptr, *ptr);
       }
};

void test(void){
    hasptr hp1(10, 20);
    hp1.show("On hp1 :");
    hasptr hp2(100, 200);
    hp2.show("On hp2 :");
    // synthesized constructor
    // hasptr hp3(hp1); 
    hasptr hp3 = hp1;
    hp3.show("On hp3 :");
    hp2  = hp3; // Synthesized COPY assignment operator 
    hp2.show("On hp2 :");
}

int main (void){
    test();
    return 0;
}

