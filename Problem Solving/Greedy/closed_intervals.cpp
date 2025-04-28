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