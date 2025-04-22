#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, d;
    cin >> N >> d;
    vector<int> coins(d);
    for (int i = 0; i < d; ++i)
    {
        cin >> coins[i];
    }
    sort(coins.rbegin(), coins.rend()); // Sort coins descending

    vector<pair<int, int>> used; // {coin, count}
    int remaining = N;
    for (int coin : coins)
    {
        if (remaining == 0)
            break;
        int cnt = remaining / coin;
        if (cnt > 0)
        {
            used.push_back({coin, cnt});
            remaining -= cnt * coin;
        }
    }

    if (remaining != 0)
    {
        cout << "Cannot make change" << endl;
    }
    else
    {
        for (auto &p : used)
        {

            cout << p.first << " cents --- " << p.second << endl;
        }
        cout << endl;
    }
    return 0;
}