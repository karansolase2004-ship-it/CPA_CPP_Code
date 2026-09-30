void insertion_sort(int * a, int N)
{
    int i, j; 
    int key; 

    for(j = 1; j < N; ++j)
    {
        key = a[j];
        i = j - 1; 
        while(i > -1 && a[i] > key)
        {
            a[i+1] = a[i];
            i = i - 1; 
        }

        a[i+1] = key; 
    }
}