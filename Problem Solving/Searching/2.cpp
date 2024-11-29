#include <bits/stdc++.h>
using namespace std;
// Given an array, find all the indices where a target integer appears. Return an array
// of indices.If the target does not appear, return an empty array.

vector<int> findIndices(vector<int> a, int target)
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == target)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> target;
    vector<int> ans = findIndices(a, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}