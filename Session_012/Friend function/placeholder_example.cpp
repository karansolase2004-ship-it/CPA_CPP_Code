class C{
    private :  
       int i_num;
       double d_num;
    C(int _n, double _d) : i_num(_n) , d_num(_d){

    };
    public : 
       static C* get_instance(){
        return new C(0, 0.0);
       }
};

void test_function(void);


int main (void){
    test_function();
    return 0;
}

void test_function(void){
    // C obj(100, 3.14);
    // C* pC = new C(200, 3.14150);

    C* pC = C::get_instance(); //ok   
    delete pC;
    pC = 0; 
}