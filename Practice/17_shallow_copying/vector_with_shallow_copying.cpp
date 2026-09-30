#include <iostream>
#include <stdexcept>
#include <cstring>

class intptr{

    friend class vector;
    friend std::ostream& operator<<(std::ostream& os, const vector& v);

    private :
        size_t N;
        int* ptr;
        unsigned int ref_count;

    public :
        intptr() : N(0), ptr(0), ref_count(1){

        }

        intptr(size_t _N) : N(_N), ptr(new int[_N]){
            ref_count = 1;
        };

        ~intptr(){
            delete [] ptr;
        }
        
};

class vector{
    private :
       intptr* pintptr;

    public :
      vector() : pintptr(new intptr()){

      }

      vector(size_t _N): pintptr(new intptr(_N)){     
      }

      vector(const vector& other){
        this->pintptr = other.pintptr;
        this->pintptr->ref_count += 1;
      }

      vector& operator=(const vector& other){
        if(this != &other){
            this->pintptr->ref_count -= 1;
            if(this->pintptr->ref_count == 0){
                delete pintptr;
            }
            this->pintptr = other.pintptr;
            this->pintptr->ref_count += 1;
        }
        return *this;
      }

      ~vector(){
        this->pintptr->ref_count -= 1;
        if(this->pintptr->ref_count == 0){
            delete pintptr;
        }
      }

      int& operator[](size_t index){
        if(index < 0 || index >= pintptr->N){
            throw std::runtime_error("bad index");
        }
        return *(pintptr->ptr+index);
      }

      void push_back(int val){
        this->pintptr->ptr = (int*)realloc(this->pintptr->ptr, (this->pintptr->N + 1) * sizeof(int));
        this->pintptr->N += 1;
        this->pintptr->ptr[this->pintptr->N - 1] = val;
      }

      friend std::ostream& operator<<(std::ostream& os, const vector& v);

      void print_ref_count(){
        printf("ref_count = %d\n", this->pintptr->ref_count);
      }

      void print_pintptr(){
        printf("pintptr = %d\n", pintptr);
      }

      void print_ptr(){
        printf("ptr = %d\n", this->pintptr->ptr);
      }

      void print_N(){
          printf("N = %d\n", pintptr->N);
        }
};

std::ostream& operator<<(std::ostream& os, const vector& v){
    for(size_t i=0; i<v.pintptr->N; ++i){
        os << "ptr[" << i << "] :" << v.pintptr->ptr[i] << std::endl;
    }
    std::cout << std::endl;
    return os;
}

void test(void);

int main(void){
  test();

  return EXIT_SUCCESS;
}

void test(void){
  vector v1;
  v1.push_back(01);
  v1.push_back(02);
  v1.push_back(03);
  v1.push_back(04);
  v1.push_back(05);
  v1.print_ref_count();
  vector v2(v1);
  std::cout << v1;
  std::cout << v2;
  v2.print_ref_count();
  vector v3 = v2;
  v3.print_ref_count();

  vector v4;
  v4.push_back(100);
  v4.push_back(200);
  v4.push_back(300);
  v4.push_back(400);
  v4.push_back(500);

  std::cout << v4;
  v4.print_ref_count();
  vector v5;
  v5 = v4;
  v5.print_ref_count();
}
