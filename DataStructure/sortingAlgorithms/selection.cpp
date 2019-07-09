#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n)
{
    int index_min = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        index_min = i;
        for(int j = i+1; j < n ; ++j)
        {
            if(arr[index_min] > arr[j])
                index_min = j;
        }
        swap(arr[index_min], arr[i]);

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
    int data[] = {5, 4, 3, 2, 1};
    int len = sizeof(data) / sizeof(data[0]);
    printArray(data, len);
    SelectionSort(data, len);
    printArray(data, len);

    return 0;
}