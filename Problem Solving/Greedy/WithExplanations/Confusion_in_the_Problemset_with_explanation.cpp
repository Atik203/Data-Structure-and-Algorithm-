/*
 * Logic Explanation:
 * This problem determines if a set of page numbers can be shuffled to form a valid sequence.
 * A page number is valid if it equals either:
 * - The number of pages before this page, or
 * - The number of pages after this page
 *
 * Algorithm:
 * 1. For each page number a[i]:
 *    - Calculate the two possible positions where it could be valid:
 *      pos1 = n-1-a[i] (if a[i] represents pages before)
 *      pos2 = a[i] (if a[i] represents pages after)
 *    - Try to place the page in one of these positions if not already used
 *    - If both positions are already occupied, it's impossible to form valid sequence
 * 2. If any page number is ≥ n, it's immediately invalid
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int case_number)
{
    int n;
    cin >> n;
    vector<int> a(n), used(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    bool possible = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= n)
        {
            possible = false;
            break;
        }
        int pos1 = n - 1 - a[i];
        int pos2 = a[i];
        if (!used[pos1])
        {
            used[pos1] = 1;
        }
        else if (!used[pos2])
        {
            used[pos2] = 1;
        }
        else
        {
            possible = false;
            break;
        }
    }

    cout << "Case " << case_number << ": " << (possible ? "yes" : "no") << '\n';
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