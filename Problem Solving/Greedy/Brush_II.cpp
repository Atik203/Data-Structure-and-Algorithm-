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