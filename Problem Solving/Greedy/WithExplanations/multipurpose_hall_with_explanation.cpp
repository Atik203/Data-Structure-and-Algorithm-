/*
 * Logic Explanation:
 * This algorithm solves an interval scheduling problem with gaps:
 * maximize the number of club activities that can be scheduled in a hall,
 * given that there must be a minimum gap between activities.
 *
 * Algorithm:
 * 1. Sort all clubs by their end times in ascending order
 * 2. Greedily select clubs:
 *    - Always pick the club with the earliest end time first
 *    - Only select subsequent clubs if they start after the
 *      previous club's end time plus required gap
 * 3. Sort the selected clubs by ID for output
 *
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(n) for storing the clubs
 */
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