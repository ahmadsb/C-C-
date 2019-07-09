#include <iostream>
void printArray(int arr[], int n)
{
    int i = 0;
    for (; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}
int Max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
int Min(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}
void CountSort(int arr[], int n)
{
    const int max = Max(arr, n);
    const int min = Min(arr, n);
    const int len = max - min + 1;
    int C[len] = {};
    int i;
    /*
    1.all elements in array c is 0
    2.counter the element in ++c[arr[i]-min]
    3.c[i] += c[i+1]
    4.output[ n] n: len of root array
        output[c[arr[i] - min] - 1] =arr[i];
        -- c[arr[i] - 1];
    5.assignment the elements in output 'utilty array to arr'
    from 0 to n arr[i] = output[i]
    */
    // for(i = 0 ; i < n ; ++i)
    //     C[i] = 0;
    

    for (i = 0; i < n; ++i)
        ++C[arr[i] - min];

    for (i = 1; i < len; ++i)
        C[i] += C[i - 1];

    int output[n];
    for (i = n - 1; i >= 0; --i)
    {
        output[C[arr[i] - min] - 1] = arr[i];
        --C[arr[i] - min];
    }

    for (i = 0; i < n; ++i)
        arr[i] = output[i];
   
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    CountSort(arr, len);
    printArray(arr, len);
    return 0;
}