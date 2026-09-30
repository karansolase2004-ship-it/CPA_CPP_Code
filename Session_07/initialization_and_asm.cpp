int num1 = 100; // data definition + initialisation 
int num2;       // data definition 

int main(void){
    num2 = 200; // assignemnt

    int num3 = 300;// initialization + assignment 
}

/* 
    .section .data 
        num1: 
        .int    100 

    .section .bss 
        .comm   num2, 4, 4 

    .section .text 
    main: 
        # PROLOGUE 
        pushl   %ebp 
        movl    %esp, %ebp 

        movl    $200, num2 # ASSIGNMENT -> ASSEMBLY CPU INSTRUCTION 
*/

void test(void){
    const int num = 100; 

    // num = 200; 
    
}