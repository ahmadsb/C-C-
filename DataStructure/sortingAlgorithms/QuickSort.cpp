#include <iostream>
void swap(int &a, int &b)
{
    a = a + b - (b = a);
}
void printArray(int arr[], int n)
{
    int i = 0;
    for (; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

int partition(int arr[], int L, int R)
{
    int mid = L + (R - L) / 2;
    int pivot = arr[mid];
    int i = L, j = R;

    while (i <= j)
    {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            --j;
            ++i;
        }
    }

    return mid;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

void QuickSortIterative(int arr[], int l, int h)
{
    int stack[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;
    while(top >= 0 )
    {
        h = stack[--top];
        l = stack[--top];

        int p = partition(arr,l, h);

        if( l > p-1)
        {
            stack[++top] = l;
            stack[++top] = p-1;
        }
        if(p+1 >h)
        {
            stack[++top] = p+1;
            stack[++top] = h;
        }
    }



}
void QuickSort(int arr[], int n)
{
    QuickSort(arr, 0, n - 1);
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    QuickSort(arr, len);
    printArray(arr, len);

    return 0;
}