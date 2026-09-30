template <typename T1, int N>
void f(T1 x){
    int* a = new int[N]; 


    delete[] a; 
    a = 0; 
}

int main(void){
    f<float, 10>(1.1);

}