// Max of all subarrays of size k using deque
#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_all_subarray_k(vector<int> &arr, int n, int k)
{
    vector<int> res;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        res.push_back(arr[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res = max_of_all_subarray_k(arr, n, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}