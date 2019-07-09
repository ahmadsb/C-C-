#include <iostream>

int BinarySearch(int arr[], int len, int value)
{
    int first = 0, last = len - 1, index = -1, i = 0;
    int mid = first + (last - first) / 2;
    while (first <= last)
    {
        mid = first + (last - first) / 2;
        if (arr[mid] > value)
            last = mid;
        if (arr[mid] < value)
            first = mid + 1;
        if (arr[mid] == value)
            return mid;
    }
    return index;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int res = BinarySearch(arr, len, 10);
    std::cout << res << std::endl;
    return 0;
}