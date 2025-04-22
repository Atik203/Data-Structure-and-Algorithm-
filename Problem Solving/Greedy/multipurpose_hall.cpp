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
        string cid;
        int s, d;
        cin >> cid >> s >> d;
        clubs[i].id = cid;
        clubs[i].start = s;
        clubs[i].duration = d;
        clubs[i].end = s + d;
    }
    int gap;
    cin >> gap;

    sort(clubs.begin(), clubs.end(), compare); // sort by end time in ascending order

    vector<Club> selectedClubs;

    selectedClubs.push_back(clubs[0]); // select the first club
    int currentEnd = clubs[0].end;
    for (int i = 1; i < n; i++)
    {
        if (clubs[i].start >= currentEnd + gap)
        {
            selectedClubs.push_back(clubs[i]);
            currentEnd = clubs[i].end;
        }
    }

    sort(selectedClubs.begin(), selectedClubs.end(), [](const Club &a, const Club &b)
         { return a.id < b.id; });
    cout << "Chosen clubs:" << endl;
    for (int i = 0; i < selectedClubs.size(); i++)
    {
        cout << selectedClubs[i].id << endl;
    }

    return 0;
}