/*
 * Logic Explanation:
 * This algorithm solves a strategic matchmaking problem for a karate competition where:
 * - When our player wins, we get 2 points
 * - When tied, we get 1 point
 * - When our player loses, we get 0 points
 *
 * Algorithm:
 * 1. Sort both our team and opponent team in ascending order
 * 2. Use two pointers for each team (start and end of array)
 * 3. For each match, use a greedy strategy:
 *    - If our strongest player beats their strongest, match them (2 points)
 *    - Else if our weakest player beats their weakest, match them (2 points)
 *    - Otherwise, match our weakest player with their strongest (0/1 point)
 *
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(n) for storing the teams
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> our_team(n);
        vector<int> opponent_team(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> our_team[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> opponent_team[i];
        }

        sort(our_team.begin(), our_team.end());
        sort(opponent_team.begin(), opponent_team.end());

        int points = 0;
        int a_start = 0, a_end = n - 1;
        int b_start = 0, b_end = n - 1;

        for (int k = 0; k < n; ++k)
        {
            if (our_team[a_end] > opponent_team[b_end])
            {
                points += 2;
                a_end--;
                b_end--;
            }
            else if (our_team[a_start] > opponent_team[b_start])
            {
                points += 2;
                a_start++;
                b_start++;
            }
            else
            {
                if (our_team[a_start] == opponent_team[b_end])
                {
                    points += 1;
                }
                a_start++;
                b_end--;
            }
        }
        cout << "Case " << cs++ << ": " << points << endl;
    }
    return 0;
}