#include <bits/stdc++.h>
using namespace std;
/*
Given an array where elements increase and then decrease (a ”mountain” array),
find the index of the peak element using binary search.
*/

int peak_element(vector<int> &a)
{
    int n = a.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] < a[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    cout << peak_element(a) << endl;

    return 0;
}