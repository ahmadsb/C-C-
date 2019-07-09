#include <iostream>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void RadixSort(int arr[], int n)
{
    int i = 0, j = 0;
    for(; i< n ; ++i)
    {
        for(;j<n; ++j)
        {
            
        }
    }
}
int main()
{
    int arr[] = {25, 12, 13, 14};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    RadixSort(arr, len);
    printArray(arr, len);

    return 0;
}