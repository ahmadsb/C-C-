// A C++ Program to find the longest common prefix
#include <bits/stdc++.h>
using namespace std;

// A Function to find the string having the minimum
// length and returns that length
int findMinLength(string arr[], int n)
{
    int min = INT_MAX;

    for (int i = 0; i <= n - 1; i++)
        if (arr[i].length() < min)
            min = arr[i].length();
    return (min);
}

bool allContainsPrefix(string arr[], int n, string str,
                       int start, int end)
{
    for (int i = 0; i <= n - 1; i++)
        for (int j = start; j <= end; j++)
            if (arr[i][j] != str[j])
                return (false);
    return (true);
}

// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix(string arr[], int n)
{
    int index = findMinLength(arr, n);
    string prefix; // Our resultant string

    // We will do an in-place binary search on the
    // first string of the array in the range 0 to
    // index
    int low = 0, high = index;

    while (low <= high)
    {
        // Same as (low + high)/2, but avoids overflow
        // for large low and high
        int mid = low + (high - low) / 2;

        if (allContainsPrefix(arr, n, arr[2], low, mid))
        {
            // If all the strings in the input array contains
            // this prefix then append this substring to
            // our answer
            prefix = prefix + arr[2].substr(low, mid - low + 1);

            // And then go for the right part
            low = mid + 1;
        }

        else // Go for the left part
            high = mid - 1;
    }

    return (prefix);
}

// Driver program to test above function
int main()
{
    string arr[] = { "geeks",
                    "geek", "geezer","geeksforgeeks"};
    int n = sizeof(arr) / sizeof(arr[0]);

    string ans = commonPrefix(arr, n);

    if (ans.length())
        cout << "The longest common prefix is " << ans << endl;
    else
        cout << "There is no common prefix" << endl;
    return (0);
}
