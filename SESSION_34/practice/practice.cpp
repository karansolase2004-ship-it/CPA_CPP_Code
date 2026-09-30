#include <iostream>

class quad{
    private : 
       int n;
    public :
      void print(){
        printf("qdqwd");
      }

      void left(){
         printf("Left");
      }
};

class square : public quad{
    private :
       int n;
    public :
      square(int _n) : n(_n){

      }

      void disp(){
        printf("mnbmnbmnb");
      }

     void print(){
        printf("ioojijioj");
     }
};

/* class rhombus : public square{
    private :
       int n;
    public :
     rhombus(int _n) : square(_n), n(_n){

      }
};

class paralellogram : public  rhombus{
    private :
         int n;
    public :
        paralellogram(int _n) : rhombus(_n),  n(_n){

        }
}; */

int main(void){
    quad* pointer_1 = new square(12);
    // quad* pointer_2 = new paralellogram(12);
    pointer_1->print();
    // pointer_1->disp(); 
    square* pointer_2 = new square(13);
    pointer_2->print();
    pointer_2->disp();

    square sqobj(10);

    sqobj.print();
    sqobj.quad::print();
    sqobj.quad::left();
}