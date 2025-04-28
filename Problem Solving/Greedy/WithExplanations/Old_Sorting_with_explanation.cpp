/*
 * Logic Explanation:
 * This algorithm finds the minimum number of swaps required to sort an array.
 * It works by finding cycles in the permutation and calculating the optimal swaps.
 *
 * Algorithm:
 * 1. Create a map from each value to its current position
 * 2. For each position not in the right place:
 *    - Follow the cycle: go from current position to the position where its value should be
 *    - Mark each visited position and count the cycle size
 *    - Number of swaps for a cycle = (cycle_size - 1)
 * 3. Sum up all required swaps from all cycles
 *
 * Time Complexity: O(n log n) due to the map usage
 * Space Complexity: O(n) for storing the position map and visited array
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int case_number)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Create a map of value -> position
    map<int, int> pos_map;
    for (int i = 0; i < n; i++)
    {
        pos_map[a[i]] = i;
    }

    // Track visited positions
    vector<bool> visited(n, false);
    int swaps = 0;

    // Find cycles in the permutation
    for (int i = 0; i < n; i++)
    {
        if (visited[i] || a[i] == i + 1)
            continue;

        int cycle_size = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = true;
            j = pos_map[j + 1]; // Go to position of the value that should be at j
            cycle_size++;
        }

        if (cycle_size > 0)
            swaps += (cycle_size - 1);
    }

    cout << "Case " << case_number << ": " << swaps << endl;
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