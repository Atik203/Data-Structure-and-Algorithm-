/*
 * Logic Explanation:
 * This algorithm determines whether a given number can be represented as a sum of
 * factorials (n!), and if possible, finds such a representation with minimal terms.
 *
 * Algorithm:
 * 1. Pre-calculate factorials from 0! to 20! (20! is very large, near 10^18)
 * 2. Use a greedy approach:
 *    - Start from the largest factorial (20!) and work down
 *    - If the current factorial fits into the remaining number, include it
 *    - Subtract the factorial value from the remaining number
 * 3. If the remaining number becomes zero, a solution was found
 *    Otherwise, the number cannot be represented as a sum of factorials
 *
 * Time Complexity: O(1) as we process at most 21 factorials
 * Space Complexity: O(1) for storing the factorials and answer
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int case_number)
{
    long long n;
    cin >> n;

    // Pre-calculate the factorials
    vector<long long> fact(21, 0);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    vector<int> ans;

    for (int i = 20; i >= 0; i--)
    {
        if (n >= fact[i])
        {
            n -= fact[i];
            ans.push_back(i);
        }
    }

    if (n != 0)
    {
        cout << "Case " << case_number << ": impossible" << endl;
        return;
    }

    sort(ans.begin(), ans.end());

    cout << "Case " << case_number << ": ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "!";
        if (i < ans.size() - 1)
            cout << "+";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}