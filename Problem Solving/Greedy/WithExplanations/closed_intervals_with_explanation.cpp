/*
 * Logic Explanation:
 * Given a set of points on a real line, this algorithm finds the minimum number of
 * unit-length closed intervals needed to cover all points.
 *
 * Algorithm:
 * 1. Sort all points in ascending order
 * 2. Greedily place intervals starting from the leftmost uncovered point:
 *    - For each uncovered point, create a unit-length interval starting at that point
 *    - Skip all points that are covered by this interval
 *    - Continue until all points are covered
 *
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(n) for storing the points and intervals
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<double> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    sort(points.begin(), points.end());

    vector<pair<double, double>> intervals;

    int i = 0;
    while (i < n)
    {

        double left = points[i];
        double right = left + 1.0;
        intervals.push_back({left, right});

        while (i < n && points[i] <= right)
        {
            i++;
        }
    }

    for (auto interval : intervals)
    {
        cout << interval.first << endl;
    }

    return 0;
}