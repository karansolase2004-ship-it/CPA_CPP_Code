#include <stdio.h> 

static int is_x_negative(double x); 
static double angle_in_degrees;  

double angle;

double cpa_sqrt(double x){
    puts("Implementing my version of sqrt"); 
    
    if(is_x_negative(x)){
        puts("I cannot yet compute the square root of negative numbers"); 
        return (-1.0); 
    }

    return (0.0); 
}

static int is_x_negative(double x){
    return (x < 0.0); 
}