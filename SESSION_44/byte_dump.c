#include <stdio.h> 
#include <stdlib.h> 

void hex_dump(void* addr, size_t N, const char* msg); 

int main(void){
    int N1 = 0xaabbccdd; 
    
    unsigned long long N2 = 35483578903758; 
    
    struct A {
        int a; 
        char b; 
        float c;
    }inA = {0x10203040, 'z', 3.1415};

    hex_dump(&N1, sizeof(N1), "HEXDUMP(N1):"); 
    hex_dump(&N2, sizeof(N2), "HEXDUMP(N2):");
    hex_dump(&inA, sizeof(inA), "HEXDUMP(inA):");

    return (EXIT_SUCCESS); 
}

void hex_dump(void* addr, size_t N, const char* msg){
    size_t i; 

    if(msg != NULL)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf(
                "BYTE(%llu):%hhx\n", 
                i, 
                *(unsigned char*)((unsigned char*)addr + i)
            ); 
}