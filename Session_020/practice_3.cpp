#include <cstdio>
#include <cstdlib>

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
        printf("n = %d\nm = %d\n",this->n, this->m);
      }
};

int main (void){
    CPAint* first_1 = new CPAint(7, 7);
    first_1->show();
    ++(*(first_1));
    CPAint first(1 , 1);
    ++first;
    CPAint Second(first);
    Second.show();
}