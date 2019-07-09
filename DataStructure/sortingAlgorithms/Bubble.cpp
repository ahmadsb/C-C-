#include <iostream>
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int arr[5] = {5,4,3,2,1};
    int i, j;
    for (i = 0; i < 5; ++i)
    {
        for (j = 1; j < 5 - i; ++j)
        {
            if(arr[j-1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }

    for(i = 0 ; i < 5; ++i){
        std::cout << arr[i] <<" ";
    }
    return 0;
}