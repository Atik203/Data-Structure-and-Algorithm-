#include <bits/stdc++.h>
using namespace std;

bool linear_search(vector<int> &a, int key)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == key)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cin >> key;

    if (linear_search(a, key))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}