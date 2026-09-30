  /* 
    To cast expression 'e' in type T, write following 
    (T)e. 

    int n; 

    m = n; 

    inferred type of n == int 

    m = (char)n; 

    Ti = inferred type: annotated types of variables names in expression 
                        + meaning of operators in the context of types 

    Tc = cast type: overridden type of expression 

    (Tc)e

    Why? 
    
    ((tata)yogeshwar).pay_tax(); 

    Operation((Tc)e)

    operator(e)

    int n = 0x0a0b0c0d; 

    [0d][0c][0b][0a]
    x   +1  +2  +3 

    int* p = &n; 

    RHS: 
        type(n):    int     ... annotated by programmer 
        type(&n):   int*    ... type system rule 

        type(RHS):  int* 

    LHS 
        type(p):    int*    ... annotated by programmer 

    type(LHS) == type(RHS)

    Let us apply dereference operator on expression p. 

    *p;

    *(unsigned char*)p;

    unsigned char* p1; 

    *p1;

*/