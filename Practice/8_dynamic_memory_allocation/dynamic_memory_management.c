#include <stdio.h> 
#include <stdlib.h> 

struct Date{
    int day; 
    int month; 
    int year; 
}; 

void built_in_type(void); 
void user_defined_data_type(void); 

void array_of_built_in_type(void); 
void array_of_user_defined_data_type(void); 

int main(void){
    built_in_type(); 
    user_defined_data_type(); 
    array_of_built_in_type(); 
    array_of_user_defined_data_type(); 

    return (0); 
}

void built_in_type(void){
    int* p = NULL;  // s1 
    int m; 
    puts("////////////////////built_in_type///////////////////////////"); 
    p = (int*)malloc(sizeof(int)); // s2 (memory allocate)
    // s3: validation check 
    if(NULL == p){
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    *p = 500;   // s4: use: write 
    m = *p;     // s4: use: read 

    printf("m = %d\n", m);
    
    free(p);    // s5: release 
    p = NULL;   // s6: make pointer null 
    puts("////////////////////built_in_type END///////////////////////////"); 
}

void user_defined_data_type(void){
    struct Date* pDate = NULL;  // s1 
    
    puts("////////////////////user_defined_data_type///////////////////////////"); 

    pDate = (struct Date*)malloc(sizeof(struct Date)); // s2 
    // s3 
    if(NULL == pDate){
        puts("error in allocating memory"); 
        exit(-1); 
    }

    // s4 
    pDate->day = 26; 
    pDate->month = 5; 
    pDate->year = 2024; 

    printf("TODAY:%d/%d/%d\n",
        pDate->day, 
        pDate->month, 
        pDate->year
    ); 

    free(pDate);    // s5 
    pDate = NULL;   // s6 
    puts("////////////////////user_defined_data_type END///////////////////////////"); 
}

void array_of_built_in_type(void){
    size_t N = 5; 
    int* p = NULL;  // s1 
    size_t i; 

    puts("////////////////////array_of_built_in_type///////////////////////////"); 

    p = (int*)malloc(N * sizeof(int));  // s2 
    if(NULL == p){
        puts("error in allocating memory"); 
        exit(-1); 
    }

    *(p + 0) = 100; 
    *(p + 1) = 200; 
    *(p + 2) = 300; 
    *(p + 3) = 400; 
    *(p + 4) = 500;

    p[0] = 100; // *(p+0)
    p[1] = 200; // *(p+1)
    p[2] = 300; // *(p+2)
    p[3] = 400; // *(p+3) 
    p[4] = 500; // *(p+4)

    for(i = 0; i < N; ++i)
        *(p+i) = (i+1)*100; 

    for(i = 0; i < N; ++i)
        p[i] = (i+1) * 100; 

    for(i = 0; i < N; ++i)
        printf("*(p + %llu) = %d\n", i, *(p+i)); 

    for(i = 0; i < N; ++i)
        printf("p[%llu]:%d\n", i, p[i]); 

    free(p); 
    p = NULL; 
    puts("////////////////////array_of_built_in_type END///////////////////////////"); 
}

void array_of_user_defined_data_type(void){
    struct Date* pDate = NULL; // s1 
    size_t N = 5; 
    size_t i;
    int curr_day, curr_month, curr_year; 

    puts("////////////////////array_of_user_defined_data_type///////////////////////////"); 
    // s2 
    pDate = (struct Date*)malloc(N * sizeof(struct Date));      
    // s3 
    if(NULL == pDate){
        puts("allocation error"); 
        exit(-1); 
    }

    // s4: write 
    for(i = 0; i < N; ++i){
        pDate[i].day = 26; 
        pDate[i].month = 5; 
        pDate[i].year = 2024; 
    }

    // pDate is pointer to array of structure Date 
    // pDate[i] access ith element of array
    // .day, .month, .year helps to access the dat, month and year data member of that structure.

    for(i=0; i<N; ++i){
        (*(pDate + i)).day = 01;
        (*(pDate + i)).month = 12;
        (*(pDate + i)).year = 2005;
    }

    for(i=0; i<N; ++i){
        printf("(*(p_date + %d)) : %d/%d/%d\n",i, 
        (*(pDate + i)).day, (*(pDate + i)).month, (*(pDate + i)).year);
    }

    // s4: read operation 
    for(i = 0; i < N; ++i){
        curr_day = (*(pDate+i)).day; 
        curr_month = (*(pDate+i)).month; 
        curr_year = (*(pDate+i)).year; 
        printf("%d/%d/%d\n", curr_day, curr_month, curr_year); 
    }

    
    for(i=0; i<N; ++i){
        (pDate+i)->day = 02;
        (pDate+i)->month = 9;
        (pDate+i)->year = 2002;
    }

    // pDate is  again pointer to an array of structs  
    // pDate+i 
    // .day, .month, .year helps to access the dat, month and year data member of that structure.

      for(i = 0; i < N; ++i){
        curr_day = (*(pDate+i)).day; 
        curr_month = (*(pDate+i)).month; 
        curr_year = (*(pDate+i)).year; 
        printf("%d/%d/%d\n", curr_day, curr_month, curr_year); 
    }


    free(pDate);    // s5 
    pDate = NULL;   // s6 
    puts("////////////////////array_of_user_defined_data_type END///////////////////////////"); 

}

/* 
    M[1000:1059]

    M[1000] -> index 0 == *(pDate+0) == pDate[0]
    M[1012] -> index 1 == *(pDate+1) == pDate[1]
    M[1024] -> index 2 == *(pDate+2) == pDate[1]
    M[1036] -> index 3 == *(pDate+3) == pDate[3]
    M[1048] -> index 4 == *(pDate+4) == pDate[4]

    (*(pDate+0)).day    == pDate[0].day  
    (*(pDate+0)).month  == pDate[0].month  
    (*(pDate+0)).year   == pDate[0].year
*/

// Dot(.) Operator is used to access data members or function of an object or struct directly 
// Object_name.member_name;

// Arrow(->) operator is used to access object or struct pointed by a pointer 

// pDate[i] = denotes a object;
// (pDate+i) = denotes a pointer of an object