void test(void){
    int* p = NULL; 

    p = (int*)malloc(sizeof(int)); 

    // use p : on multiple lines 
    // STACK UNWINDING PATH 
    f1();   // Khel konala daivacha kalala ? 


    free(p); 
    p = NULL; 
}