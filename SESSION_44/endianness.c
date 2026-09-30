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

    printf("n = %llx\n", n);
    return (EXIT_SUCCESS); 
}

