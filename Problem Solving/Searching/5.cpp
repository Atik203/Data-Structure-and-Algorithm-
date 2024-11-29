#include <bits/stdc++.h>
using namespace std;
// Perform binary search on a descending order sorted array to find a target value.

int binary_search(vector<int> &a, int target)
{
    int left = 0, right = a.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int target = 7;
    cout << binary_search(a, target) << endl;

    return 0;
}