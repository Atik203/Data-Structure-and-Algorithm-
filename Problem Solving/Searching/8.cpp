#include <bits/stdc++.h>
using namespace std;
// In a sorted array, count the occurrences of a target value using binary search.

int count_occurrence(vector<int> &a, int x)
{
    int n = a.size();
    int low = 0, high = n - 1;
    int count = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            count++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && a[left] == x)
            {
                count++;
                left--;
            }
            while (right < n && a[right] == x)
            {
                count++;
                right++;
            }
            return count;
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
    return count;
}

int main()
{
    vector<int> a = {1, 1, 2, 2, 2, 2, 3};
    int x = 2;
    cout << count_occurrence(a, x) << endl;

    return 0;
}