// filepath: e:\C_and_CPP\DSA\Problem Solving\Greedy\Brush_II.cpp
/*
 * Logic Explanation:
 * This algorithm finds the minimum number of horizontal brushes of width 'w' needed to
 * cover all given points on a 2D plane. Only the y-coordinates matter since the brush
 * is horizontal and covers the entire x-axis.
 *
 * Algorithm:
 * 1. Extract and sort all points by their y-coordinates
 * 2. Greedily place brushes:
 *    - Start with the lowest uncovered point
 *    - Place a brush to cover it and all points within range y to y+w
 *    - Move to the next uncovered point
 * 3. Count the total number of brushes required
 *
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(n) for storing the points
 */
#include <bits/stdc++.h>
using namespace std;

void solve(int case_number)
{
    int n, w, y;
    cin >> n >> w;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = y;
    }
    sort(a.begin(), a.end());
    int count = 0;
    int i = 0;

    while (i < n)
    {
        // Take the current point as the starting position
        int start = a[i];
        count++;

        // Skip all points that are covered by the current brush (within width w)
        while (i < n && a[i] <= start + w)
        {
            i++;
        }
    }

    cout << "Case " << case_number << ": " << count << endl;
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