#include <iostream>
/*
    heap sort is min heap or max heap 
    heap sort is complete Tree 'i --> 2i , 2i+1' all the layout is ful 
    and the final layout is not full or full but the important to full from left to right
*/
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
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

      
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    heapSort(arr, len);
    printArray(arr, len);

    return 0;
}