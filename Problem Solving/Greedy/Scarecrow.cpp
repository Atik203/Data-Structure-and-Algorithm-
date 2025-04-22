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