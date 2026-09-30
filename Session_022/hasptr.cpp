class hasptr{
    private :
      int n;
      int* ptr;

    public :
      hasptr(int _n, int val) : n(_n), ptr(new int(val)){

      }
};

int main (void){
    test();
    return 0;
}

void test(void){
    hasptr hp1(10, 20);
    hasptr hp2(100, 200);

    hasptr hp3(hp1); // synthesized constructor

    hp2  = hp3; // Synthesized COPY assignment operator 
}

// synthesized destructor will get called on hp1, hp2, hop3;