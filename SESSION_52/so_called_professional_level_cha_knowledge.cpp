Segmentation fault three reasons: (mostly in the context of virtual memory environment)
(replace word mapped with valid, unmapped with invalid, same theory can be extended 
to non-virtual memory environment such bare metal etc)

1)  Given address is not mapped in virtual address space of process 
2)  Given address is mapped in virtual address space BUT operation performed 
    on addr (one out of read/write/execute) is not permitted by section 
    to which addr belongs 
    e.g. write operation on virutal address in read only data section 
    execute operation on virtual address in rodata, data, bss, stack section 
    write operation on virtual address in text section 
3)  Even though virtual address is valid, even though current operation is compatible 
    with section permissions, a segfault can occur if the addr belongs to OS (
        kernel address space)    
#---------------------------------------------------------------------------
Memory leak avoid kasa karaycha? 
Protocol in the context of local pointer: 

void test(void){
    int* p = NULL; 

    // p is assigned to address belonging to 
    // dynamic memory sections // heap 
}

1) free(p); before function returns 
2) return p; and make sure that the caller function 
    catches it. 
3) before returning from p, store address in p 
    in another pointer which will be present in program 
    memory after returning from current function and will 
    be visible to caller function (or its caller and so on)

    e.g. global pointer 

    int* g_ptr = NULL; 

    void test(void){
        int* p = NULL; 

        p = (int*)malloc(sizeof(int)); 
        assert (p != NULL)

        // use p 

        g_ptr = p; 
        // return from function without freeing p 
        // or without returning p 
        // yet you can avoid memory leak because 
        // address in p is present in g_ptr 
        // and g_ptr being a global variable will
        // be visible to caller of test(), whichever 
        // function that is 
    }


////////////////////////////////////////////

void test(void){
    int** pp = NULL; 

    pp = (int**)malloc(5 * sizeof(int*)); 
    assert(pp != NULL); 

    for(int i = 0; i != 5; ++i)
        pp[i] = (int*)malloc(sizeof(int)); 

    
    // 1) free(pp);   // 5 integers are leaked 
    // or 
    // 2)
    // for(i = 0; i != 5; ++i)
    //     free(pp[i]); 
    // forgot free(pp); 
    // 5 pointers are leaked 
}

// debugger: 
// valegrind:  