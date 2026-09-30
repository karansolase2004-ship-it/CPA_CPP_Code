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