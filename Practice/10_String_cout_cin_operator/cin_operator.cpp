#include <cstdio>
#include <iostream>

int main(void)
{
    int n;
    std::cout << "Enter the size of array :";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter elements of array : " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Element arr[" << i + 1 << "]" << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Elements of Array : " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Element arr[" << i + 1 << "]" << ": " << arr[i] << std::endl;
    }
}