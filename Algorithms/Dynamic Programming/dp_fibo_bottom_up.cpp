#include <bits/stdc++.h>
using namespace std;
vector<int> F(11, 0);

int Fib(int n)
{
    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }

    return F[n];
}

int main()
{
    F[0] = 0, F[1] = 1;
    int n;
    cin >> n;

    cout << "Answer: " << Fib(n) << endl;
    return 0;
}