// filepath: e:\C_and_CPP\DSA\Problem Solving\Greedy\Scarecrow.cpp
/*
 * Logic Explanation:
 * This algorithm finds the minimum number of scarecrows needed to protect
 * a farm field represented as a string, where:
 * '.' represents a plot that needs protection
 * '#' represents a plot that doesn't need protection
 *
 * Algorithm:
 * 1. Greedily place scarecrows from left to right
 * 2. When a plot that needs protection is found:
 *    - Place a scarecrow at that position
 *    - Skip the next two positions (since a scarecrow protects 3 consecutive plots)
 *    - Increment the count of scarecrows needed
 *
 * Time Complexity: O(n) where n is the length of the field
 * Space Complexity: O(1) excluding input storage
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            i += 2; // Skip the next two positions
            count++;
        }
    }
    cout << "Case " << t << ": " << count << endl;
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