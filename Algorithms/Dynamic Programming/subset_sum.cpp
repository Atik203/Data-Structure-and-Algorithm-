#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: sum 0 is always possible (empty subset)
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            // Don't include current element
            dp[i][j] = dp[i - 1][j];

            // Include current element (if possible)
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main()
{
    int n, target;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    bool result = subsetSum(arr, target);
    cout << "Can make sum " << target << ": " << (result ? "TRUE" : "FALSE") << endl;

    return 0;
}