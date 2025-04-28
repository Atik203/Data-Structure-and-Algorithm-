// filepath: e:\C_and_CPP\DSA\Problem Solving\Greedy\practice_multipurpose_hall.cpp
/*
 * Logic Explanation:
 * This is a practice implementation of the interval scheduling problem with gaps.
 * The algorithm maximizes the number of club activities that can use a multipurpose hall.
 *
 * Algorithm:
 * 1. Sort all clubs by their end times (earliest finish time first)
 * 2. Greedily select clubs:
 *    - Start with the club that finishes earliest
 *    - For each subsequent club, check if it starts after the required gap from previous activity
 *    - If compatible, select it and update current end time
 * 3. Sort selected clubs by ID for output
 *
 * Time Complexity: O(n log n) for sorting
 * Space Complexity: O(n) for storing clubs
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