#include <bits/stdc++.h>
using namespace std;

pair<int, string> longestCommonSubsequence(string x, string y)
{
    int m = x.length();
    int n = y.length();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS string
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs = x[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return {dp[m][n], lcs};
}

int main()
{
    string x, y;

    cout << "Enter first string: ";
    cin >> x;

    cout << "Enter second string: ";
    cin >> y;

    auto result = longestCommonSubsequence(x, y);
    int length = result.first;
    string lcs = result.second;

    cout << "\nString 1: " << x << endl;
    cout << "String 2: " << y << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "LCS Length: " << length << endl;

    return 0;
}