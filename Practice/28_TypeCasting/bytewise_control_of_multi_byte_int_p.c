#include <stdio.h> 
#include <stdlib.h> 

unsigned long long int N = 0; 

//  []  []  []  []  []  []  []  []
//  x   +1  +2  +3  +4  +5  +6  +7  
// N : M[x:x+7]

// goal : 
// [ff]  []  []  []  []  []  []  []

// [ff]  [ff]  [ff]  []  []  []  []  []

//  [ff]  [ff]  [ff]  [ff]  [ff]  [ff]  [ff]  []

//  [ff]  [ff]  [ff]  [ff]  [ff]  [ff]  [ff]  [aa]

int main(void){
    printf("N = %llx\n", N); 
    *(unsigned char*)&N = 0xff; // x
    printf("N = %llx\n", N); 
    *(unsigned short*)  ((unsigned char*)&N + 1) = 0xffff; // x+1 to x+2
    printf("N = %llx\n", N); 
    *(unsigned int*)((unsigned char*)&N + 3) = 0xffffffff; // x+3  to x+6
    printf("N = %llx\n", N); 
    *(unsigned char*)((unsigned char*)&N + 7) = 0xaa; // x+6 to x+7
    printf("N = %llx\n", N); 

    return (0); 

    // output : aaffffffffffffff
    // aa is starting point because of little endianess
}

/* 
sub-goal @1: 
    To write an expression to generate address x + 1 

    &N      ==  x 
    &N + 1  ==  x + 1 * 8 

    (unsigned char*)&N + 1 == x + 1 

*/

/* 
    short v1; 
    int v2; 
    long long v3; 

        x 
    v1:[][]
        
        y 
    v2:[][][][]
        
        z 
    v3:[][][][][][][][]

*/

/* 
printf("N = %llx\n", N);

    *((reinterpret_cast<char*>(&N) + 0)) = 0xff;
    printf("N = %llx\n", N);

    *(reinterpret_cast<short*>(reinterpret_cast<char*>(&N) + 1)) = 0xffff;
    printf("N = %llx\n", N);

    *(reinterpret_cast<int*>(reinterpret_cast<char*>(&N) + 3)) = 0xffffffff;
    printf("N = %llx\n", N);

    *(reinterpret_cast<char*>(reinterpret_cast<char*>(&N) + 7)) = 0xaa;
    printf("N = %llx\n", N);
*/

/* 
practice Code :
unsigned long long int N = 0xaabbccddeeff;

int main (void)
{
    printf("N = %llx\n", N);
    *(reinterpret_cast<unsigned char*>(&N)) = 0xbb;
    printf("N = %llx\n", N);
    *(reinterpret_cast<short*>(reinterpret_cast<char*>(&N) + 1)) = 0xccaa;
    printf("N = %llx\n", N);
    *(reinterpret_cast<int*>(reinterpret_cast<short*>(reinterpret_cast<char*>(&N) + 1) + 1)) = 0xddffee;
    printf("N = %llx\n", N);
}
*/