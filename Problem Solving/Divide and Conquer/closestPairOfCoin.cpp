#include <bits/stdc++.h>
using namespace std;

// Function to find the distance between two points
double distance(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

// Structure to store the closest pair and their distance
struct Result
{
    pair<int, int> p1;
    pair<int, int> p2;
    double distance;
};

// Function to find the closest pair of points using divide and conquer
Result closestPair(vector<pair<int, int>> &points, int left, int right)
{
    // Base case: if there are 2 or 3 points, use brute force
    if (right - left <= 3)
    {
        Result res;
        res.distance = DBL_MAX;
        for (int i = left; i < right; i++)
        {
            for (int j = i + 1; j < right; j++)
            {
                double dist = distance(points[i], points[j]);
                if (dist < res.distance)
                {
                    res.distance = dist;
                    res.p1 = points[i];
                    res.p2 = points[j];
                }
            }
        }
        return res;
    }

    // Find the middle point
    int mid = (left + right) / 2;
    Result leftResult = closestPair(points, left, mid);
    Result rightResult = closestPair(points, mid, right);

    Result res;
    if (leftResult.distance < rightResult.distance)
    {
        res = leftResult;
    }
    else
    {
        res = rightResult;
    }

    // Create an array to store points within the strip
    vector<pair<int, int>> strip;
    for (int i = left; i < right; i++)
    {
        if (abs(points[i].first - points[mid].first) < res.distance)
        {
            strip.push_back(points[i]);
        }
    }

    // Sort the strip according to the y-coordinate
    sort(strip.begin(), strip.end(), [](pair<int, int> p1, pair<int, int> p2)
         { return p1.second < p2.second; });

    // Find the closest points in the strip
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < res.distance; j++)
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < res.distance)
            {
                res.distance = dist;
                res.p1 = strip[i];
                res.p2 = strip[j];
            }
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    // Sort points according to x-coordinate
    sort(points.begin(), points.end());

    // Find the closest pair of points
    Result result = closestPair(points, 0, n);

    cout << "The closest pair of points are: " << endl;
    cout << "(" << result.p1.first << ", " << result.p1.second << ") and ";
    cout << "(" << result.p2.first << ", " << result.p2.second << ")" << endl;
    cout << "The distance between them is: " << result.distance << endl;

    return 0;
}