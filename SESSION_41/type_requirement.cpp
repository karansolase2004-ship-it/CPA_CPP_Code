 int a, b, c; 

c = a + b; 

movl    a, %eax 
movl    b, %edx 
addl    %edx, %eax 
movl    %eax, c

#-------------------------

short a, b, c; 

c = a + b; 

movw    a, %ax 
movw    b, %dx
addw    %dx, %ax 
movw    %ax, c


template <typename T> 
void f(){
    T a, b, c; 

    c = a + b; 
}
