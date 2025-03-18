#include <bits/stdc++.h>
using namespace std;
int evenSum(vector<int> a, int l, int h)
{
    if (l == h)
    {
        if (a[l] % 2)
            return 0;
        else
            return a[l];
    }
    else
    {
        int mid = (l + h) / 2;
        int left = evenSum(a, l, mid);
        int right = evenSum(a, mid + 1, h);
        return left + right;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = evenSum(a, 0, n - 1);
    cout << "Sum of the even numbers in the array is: " << sum << endl;

    return 0;
}