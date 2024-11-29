#include <bits/stdc++.h>
using namespace std;

// Given a sorted array, return the index where a target value should be inserted to
// maintain the order.Use binary search.

int search_insert(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {
        1,
        3,
        5,
        6};
    int target = 4;
    cout << search_insert(a, target) << endl;
    return 0;
}