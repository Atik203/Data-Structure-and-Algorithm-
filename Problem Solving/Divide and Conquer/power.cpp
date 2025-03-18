#include <bits/stdc++.h>
using namespace std;

long long power(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    else
    {
        long long mid = y / 2;
        long long p = power(x, mid);
        if (y % 2 == 0)
            return p * p;
        else
            return x * p * p;
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << power(x, y) << endl;
    return 0;
}