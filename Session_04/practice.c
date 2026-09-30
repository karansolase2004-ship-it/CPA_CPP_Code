#include<stdio.h>

int main (void)
{
    for (int i=0;i<2;++i)
    {
        int num=0; 
        printf("1_num = %d\n", i);
        while (i<2)
        {
            int num=1;
            printf("1.num = %d\n", i);
            ++i;
        }
    }
}