// filepath: e:\C_and_CPP\DSA\Problem Solving\Greedy\coin_change.cpp
/*
 * Logic Explanation:
 * This is a greedy coin change algorithm that finds the minimum number of coins needed
 * to make up a given amount using a set of available coin denominations.
 *
 * Algorithm:
 * 1. Sort the coins in descending order
 * 2. For each coin denomination, starting from the largest:
 *    - Take as many coins of that denomination as possible without exceeding the target amount
 *    - Reduce the remaining amount accordingly
 * 3. If the remaining amount is zero, we've found a valid solution
 *    Otherwise, no solution exists with the given denominations
 *
 * Time Complexity: O(d log d) where d is the number of coin denominations
 * Space Complexity: O(d)
 */
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
    int count = 0;
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
            count += p.second;
            cout << p.first << " cents --- " << p.second << endl;
        }
        cout << endl;
    }
    cout << "Total " << count << " coins";
    return 0;
}