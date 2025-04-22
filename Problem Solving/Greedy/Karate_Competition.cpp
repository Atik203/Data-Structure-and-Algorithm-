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