#include <bits/stdc++.h>
using namespace std;
// Given an array of integers, find the first occurrence of a target integer. If the target
//  is not in the array, return -1.

int linear_search(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << linear_search(arr, target) << endl;

    return 0;
}