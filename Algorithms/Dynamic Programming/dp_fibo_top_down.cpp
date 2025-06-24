#include <bits/stdc++.h>
using namespace std;

vector<int> F(11, 0);

int Fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (F[n - 1] == 0)
        F[n - 1] = Fib(n - 1);
    if (F[n - 2] == 0)
        F[n - 2] = Fib(n - 2);

    return F[n - 1] + F[n - 2];
}

int main()
{
    F[0] = 0, F[1] = 1;

    int n;
    cin >> n;

    cout << "Answer: " << Fib(n) << endl;

    return 0;
}