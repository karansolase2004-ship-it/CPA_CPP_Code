#include <stdio.h> 
#include <stdlib.h> 

unsigned int n = 0x0a0b0c0d; 

int main(void){
    if(*(unsigned char*)&n == 0x0d)
        puts("The Little Endian Machine"); 
    else if(*(unsigned char*)&n == 0x0a)
        puts("The Big Endian Machine"); 
    else 
        puts("Machine from the Shadow World!(control flow should not come here)"); 

    printf("n = %x\n", n);
    return (EXIT_SUCCESS); 
}

/* 
printf("%x", n) prints the logical value stored in n, not the memory layout.
The number 0x0a0b0c0d is stored in little-endian order in memory, but when printed as a number, it is interpreted in its natural order (0a0b0c0d).
*/