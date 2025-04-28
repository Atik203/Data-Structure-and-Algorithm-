/*
 * Logic Explanation:
 * This is a greedy algorithm for finding the minimum number of gas stations
 * needed to reach a destination with a vehicle that has a limited fuel tank.
 *
 * Algorithm:
 * 1. Add starting point (0) and destination (D) to the list of stations
 * 2. For each current position:
 *    - Find the furthest reachable station within tank capacity
 *    - If no progress can be made, the destination is unreachable
 *    - Add the selected station to our stops list and move to it
 *    - Continue until we reach the destination
 *
 * Time Complexity: O(n) where n is the number of gas stations
 * Space Complexity: O(n) for storing the stations and stops
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D, m, n;
    cin >> D >> m >> n;
    vector<int> stations(n + 2);
    stations[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> stations[i];
    }
    stations[n + 1] = D;

    vector<int> stops;
    int curr = 0;

    while (curr <= n)
    {
        int next = curr;
        // Move as far as possible within tank range
        while (next + 1 <= n + 1 && stations[next + 1] - stations[curr] <= m)
        {
            ++next;
        }
        if (next == curr)
        {
            cout << "Can't reach destination" << endl;
            return 0;
        }
        if (next <= n)
        {
            stops.push_back(next);
        }
        curr = next;
    }

    for (int idx : stops)
    {
        cout << "stop at gas station " << idx << " (" << stations[idx] << " miles)" << endl;
    }
    return 0;
}