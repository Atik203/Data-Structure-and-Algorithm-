#include <bits/stdc++.h>
using namespace std;

string longestPrefix(vector<string> s, int l, int r)
{
    if (l == r)
        return s[l];

    int mid = (l + r) / 2;
    string left = longestPrefix(s, l, mid);
    string right = longestPrefix(s, mid + 1, r);

    int minLength = min(left.length(), right.length());
    for (int i = 0; i < minLength; i++)
    {
        if (left[i] != right[i])
            return left.substr(0, i);
    }
    return left.substr(0, minLength);
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    string result = longestPrefix(s, 0, n - 1);
    if (result.empty())
        cout << "No common prefix" << endl;
    else
        cout << result << endl;

    return 0;
}