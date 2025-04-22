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
            cout << "Can’t reach destination" << endl;
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