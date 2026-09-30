#include <stdio.h> 
#include <stdlib.h> 

struct C{
    int a; 
    int b; 
}; 

struct B{
    int n1; 
    struct C* pC; 
    int n2; 
}; 

struct A{
    int u; 
    struct B* pB; 
    int v; 
}; 

struct A* allocateA(){
    struct A* pA = (struct A*)malloc(sizeof(struct A)); 
    pA->u = 10; 
    pA->v = 20; 
    pA->pB = (struct B*)malloc(sizeof(struct B)); 
    pA->pB->n1 = 100; 
    pA->pB->n2 = 200; 
    pA->pB->pC = (struct C*)malloc(sizeof(struct C)); 
    pA->pB->pC->a = 1000; 
    pA->pB->pC->b = 2000; 
}

void test(void){
    struct A* pA = allocateA(); 
    // pA->u, pA->v, pA->pB->n1, pA->pB->n2, pA->pB->pC->a, pA->pB->pC->b; 
    free(pA->pB->pC); 
    free(pA->pB); 
    free(pA); 
}

// delete = automated call to destructor + free() 
// new = malloc() + automated call to constructor 


// COMPLEX EXAMPLE: 
/*

struct Point{
    double x, y; 
}; 

struct Segment{
    struct Point* pPoint1; 
    struct Point* pPoint2; 
}; 

struct Triangle{
    struct Segment* pSeg1; 
    struct Segment* pSeg2; 
    struct Segment* pSeg3; 
}; 

struct Polygon{
    size_t N; 
    struct Segment** ppSegment; 
}; 

*/