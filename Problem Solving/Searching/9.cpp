#include <bits/stdc++.h>
using namespace std;

/*Given a sorted array, find the element closest to a given target. If two elements are
equally close, return the smaller one.
*/

int closest_element(vector<int> &a, int x)
{

    int n = a.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return a[mid];
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

    if (low == 0)
    {
        return a[low];
    }
    if (high == n - 1)
    {
        return a[high];
    }

    if (abs(a[low] - x) < abs(a[high] - x))
    {
        return a[low];
    }
    else if (abs(a[low] - x) > abs(a[high] - x))
    {
        return a[high];
    }
    else
    {
        return a[low];
    }

    return -1;
}

int main()
{
    vector<int> a = {1, 3, 8, 10, 15};
    int x = 12;
    cout << closest_element(a, x) << endl;

    return 0;
}