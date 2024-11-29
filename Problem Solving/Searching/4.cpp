#include <bits/stdc++.h>
using namespace std;

/*
Implement binary search in a sorted array to locate a target value. Return the
index of the target if found; otherwise, return -1.
*/

int binary_search(vector<int> &a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binary_search(a, 5) << endl;

    return 0;
}