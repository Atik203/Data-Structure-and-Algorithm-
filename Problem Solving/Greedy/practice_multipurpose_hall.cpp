#include <bits/stdc++.h>
using namespace std;

struct Club
{
    string id;
    int start;
    int duration;
    int end;
};

bool compare(const Club &a, const Club &b)
{
    return a.end < b.end;
}

int main()
{
    int n;
    cin >> n;

    vector<Club> clubs(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        int b, c;
        cin >> a >> b >> c;
        clubs[i].id = a;
        clubs[i].start = b;
        clubs[i].duration = c;
        clubs[i].end = b + c;
    }
    int gap;
    cin >> gap;
    sort(clubs.begin(), clubs.end(), compare);

    vector<Club> selected;
    selected.push_back(clubs[0]);
    int currentEnd = clubs[0].end;
    for (int i = 1; i < n; i++)
    {
        if (clubs[i].start >= currentEnd + gap)
        {
            selected.push_back(clubs[i]);
            currentEnd = clubs[i].end;
        }
    }

    sort(selected.begin(), selected.end(), [](const Club &a, const Club &b)
         { return a.id < b.id; });

    cout << "Chosen Clubs:" << endl;
    for (auto it : selected)
    {
        cout << it.id << endl;
    }

    return 0;
}