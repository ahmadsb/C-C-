#include <iostream>

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; ++i)
    {
        key = arr[i];
        j = i - 1;
        while(j >=0 && arr[j] >  key)
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    insertionSort(arr, len);
    printArray(arr, len);
    return 0;
}