#include <bits/stdc++.h>
using namespace std;
// Given a sorted array, find the first and last positions of a target value. If the target
// is not found, return (-1, -1).

vector<int> binary_search(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n - 1;
    int first = -1, last = -1;

    // First occurrence of target
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            first = mid;
            high = mid - 1;
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
    low = 0, high = n - 1;

    // Last occurrence of target
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            last = mid;
            low = mid + 1;
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
    return {first, last};
}

int main()
{
    vector<int> a = {
        1,
        2,
        2,
        2,
        3,
        4,
    };
    int target = 2;
    vector<int> ans = binary_search(a, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}