 #include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

int main(void){
    int numerator; 
    int denomenator; 
    int quotient; 
    int remainder; 

    printf("Enter numerator:"); 
    scanf("%d", &numerator); 

    printf("Enter denomenator:"); 
    scanf("%d", &denomenator); 

    /* #ifdef DEBUG
        assert(denomenator != 0); 
    #else 
        if(denomenator == 0){
            fprintf(stderr, "Cannot divide by zero\n"); 
            exit(EXIT_FAILURE); 
        }
    #endif /* DEBUG */ 

    assert(denomenator != 0);
    
    quotient = numerator / denomenator; 
    remainder = numerator % denomenator; 

    printf("Quotient of division : %d\n", quotient); 
    printf("Remainder of division : %d\n", remainder); 

    return (EXIT_SUCCESS); 
}