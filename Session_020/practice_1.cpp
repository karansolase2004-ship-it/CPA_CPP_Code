#include <cstdio>

class CPAint{
    private :
       int n;
       int m;
    public :
      CPAint() : n(0), m(0){

      };

      CPAint(int _m, int _n) : n(_n), m(_m){

      };

      CPAint operator++(){
        this->n = this->n + 1;
      }

      void show(){
        printf("n = %d\nm = %d",this->n, this->m);
      }
};

int main (void){
    CPAint first(1 , 1);
    ++first;
    CPAint Second(first);
    Second.show();
}