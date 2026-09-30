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

    return 0;
}

void built_in_type(void){
    int* p = NULL;
    int m;
    puts("//////////////////built_in_type//////////////////");
    p = (int*)malloc(sizeof(int));  //s2 (memory allocate)
    // s3 :validation check
    if(NULL == p){
        puts("Error in allocating memory");
        exit(-1);
    }

    *p = 500;    // s4: use : write
    m = *p;      // s4: use : read

    printf("m = %d\n", m);

    free(p);    // s5 :release
    p = NULL;   // s6 : make pointer NULL
        puts("//////////////////built_in_type END//////////////////");
}

void user_defined_data_type(void){
    struct Date* pDate = NULL;  // s1
        puts("//////////////////user_defined_data_type//////////////////");

    pDate = (struct Date*)malloc(sizeof(struct Date));  // s2
    // s3

    if (NULL == pDate){
        puts("Error in allocating memory");
        exit(-1);
    }

    // s4
    pDate->day = 26;
    pDate->month = 5;
    pDate->year = 2024;

    printf("TODAY : %d/%d/%d\n",
            pDate->day,
            pDate->month,
            pDate->year
    );

    free(pDate);   // s5
    pDate = NULL;
    puts("//////////////////user_defined_data_type END//////////////////");
}

void array_of_built_in_type(void){
    size_t N = 5;
    int* p = NULL; // S1
    size_t i;

    puts("//////////////////array_of_built_in_type//////////////////");

    p = (int*)malloc(N * sizeof(int));  //S2
    if(NULL == p){
        puts("Error in allocating memory");
        exit(-1);
    }

    *(p + 0) = 100;
    *(p + 1) = 200;
    *(p + 2) = 300;
    *(p + 3) = 400;
    *(p + 4) = 500;

    p[0] = 100;  // *(p+0)
    p[1] = 200;  // *(p+1)
    p[2] = 300;  // *(p+2)
    p[3] = 400;  // *(p+3)
    p[4] = 500;  // *(p+4) 

    for (i = 0; i < N; ++i)
        *(p + i) = (i + 1) * 100;

    for (i = 0; i < N; ++i)
        p[i] = (i + 1) * 100;

    for (i = 0; i < N; ++i)
        printf("*(p + %llu) = %d\n", i, *(p + i));

    for (i = 0; i < N; ++i)
        printf("p[%llu] : %d\n", i, p[i]);

    free(p);
    p = NULL;
    puts("//////////////////array_of_built in type_END//////////////////");
}

void array_of_user_defined_data_type(void){
    struct Date* pDate = NULL;  //s1
    size_t N = 5;
    size_t i;
    int curr_day, curr_month, curr_year;
    
    puts("//////////////////array_of_user_defined_data_type//////////////////");

    // s2
    pDate = (struct Date*)malloc(N * sizeof(struct Date));
    // s3

    if (NULL  == pDate){
        puts("allocation error");
        exit(-1);
    }

    // s4 : write
    for (i = 0; i < N; ++i){
        pDate[i].day = 26;
        pDate[i].month = 5;
        pDate[i].year = 2024;
    }

    //s4 : read operation 
    for (i = 0; i < N; ++i){
        curr_day = (*(pDate+i)).day;
        curr_month = (*(pDate+i)).month;
        curr_year = (*(pDate+i)).year;

        printf("%d/%d/%d\n", curr_day, curr_month, curr_year);
    }

    free(pDate);   // s5
    pDate = NULL;  // s6
    puts("//////////////////array_of_user_defined_data-type END//////////////////");


}

/* M[1000 : 1059] 
   
   M[1000] -> index 0 == *(pDate+0) == pDate[0]
   M[1012] -> index 1 == *(pDate+1) == pDate[1]
   M[1024] -> index 2 == *(pDate+2) == pDate[2]
   M[1036] -> index 3 == *(pDate+3) == pDate[3]
   M[1048] -> index 4 == *(pDate+4) == pDate[4]
   
   (*(pDate+0)).day    == pDate[0].day
   (*(pDate+0)).day    == pDate[0].month
   (*(pDate+0)).year   == pDate[0].year
   
   */