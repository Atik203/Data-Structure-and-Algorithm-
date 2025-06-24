#include <bits/stdc++.h>
using namespace std;

struct RopeInfo
{
    int totalCost;
    vector<int> ropesUsed;
    int joinCost;

    RopeInfo() : totalCost(INT_MAX), joinCost(0) {}
    RopeInfo(int cost, vector<int> ropes, int joins) : totalCost(cost), ropesUsed(ropes), joinCost(joins) {}
};

void ropeWithJoiningCost(vector<int> &ropes, vector<int> &ropeCosts, int joinCost, int targetLength)
{
    int n = ropes.size();

    // DP table: dp[i] = RopeInfo for making length i
    vector<RopeInfo> dp(targetLength + 1);

    dp[0].totalCost = 0; // Base case: no cost for length 0

    // Fill the DP table
    for (int i = 1; i <= targetLength; i++)
    {
        // Try using each single rope type
        for (int j = 0; j < n; j++)
        {
            if (ropes[j] <= i && dp[i - ropes[j]].totalCost != INT_MAX)
            {
                int newCost = dp[i - ropes[j]].totalCost + ropeCosts[j];
                int newJoinCost = dp[i - ropes[j]].joinCost;

                // If we're adding to existing ropes, we need joining cost
                if (i - ropes[j] > 0)
                {
                    newCost += joinCost;
                    newJoinCost += joinCost;
                }

                if (newCost < dp[i].totalCost)
                {
                    dp[i].totalCost = newCost;
                    dp[i].ropesUsed = dp[i - ropes[j]].ropesUsed;
                    dp[i].ropesUsed.push_back(ropes[j]);
                    dp[i].joinCost = newJoinCost;
                }
            }
        }

        // Try splitting at different points (combining two solutions)
        for (int k = 1; k < i; k++)
        {
            if (dp[k].totalCost != INT_MAX && dp[i - k].totalCost != INT_MAX)
            {
                int newCost = dp[k].totalCost + dp[i - k].totalCost + joinCost;
                int newJoinCost = dp[k].joinCost + dp[i - k].joinCost + joinCost;

                if (newCost < dp[i].totalCost)
                {
                    dp[i].totalCost = newCost;
                    dp[i].ropesUsed = dp[k].ropesUsed;
                    dp[i].ropesUsed.insert(dp[i].ropesUsed.end(),
                                           dp[i - k].ropesUsed.begin(),
                                           dp[i - k].ropesUsed.end());
                    dp[i].joinCost = newJoinCost;
                }
            }
        }
    }

    // Check if solution exists
    if (dp[targetLength].totalCost == INT_MAX)
    {
        cout << "No solution possible for length " << targetLength << " meters" << endl;
        return;
    }

    // Sort ropes for better presentation
    vector<int> result = dp[targetLength].ropesUsed;
    sort(result.begin(), result.end(), greater<int>());

    // Print results
    cout << "\n=== ROPE PROBLEM SOLUTION ===" << endl;
    cout << "Target length: " << targetLength << " meters" << endl;
    cout << "Joining cost: $" << joinCost << " per join" << endl;

    cout << "\nMinimum total cost: $" << dp[targetLength].totalCost << endl;
    cout << "Total joining cost: $" << dp[targetLength].joinCost << endl;
    cout << "Total rope cost: $" << (dp[targetLength].totalCost - dp[targetLength].joinCost) << endl;

    cout << "\nRopes used: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "m";
        if (i < result.size() - 1)
            cout << " + ";
    }
    cout << " = " << targetLength << "m" << endl;

    // Count frequency of each rope
    map<int, int> ropeCount;
    for (int rope : result)
    {
        ropeCount[rope]++;
    }

    cout << "\nRope breakdown:" << endl;
    int totalRopeCost = 0;
    for (auto &pair : ropeCount)
    {
        int ropeLength = pair.first;
        int count = pair.second;

        // Find the cost of this rope type
        int costPerRope = 0;
        for (int i = 0; i < n; i++)
        {
            if (ropes[i] == ropeLength)
            {
                costPerRope = ropeCosts[i];
                break;
            }
        }

        int subtotal = count * costPerRope;
        totalRopeCost += subtotal;

        cout << count << " rope(s) of " << ropeLength << "m @ $" << costPerRope
             << " each = $" << subtotal << endl;
    }

    int numJoins = result.size() - 1;
    cout << "\nNumber of joins needed: " << numJoins << endl;
    cout << "Cost breakdown:" << endl;
    cout << "  Rope cost: $" << totalRopeCost << endl;
    cout << "  Join cost: $" << dp[targetLength].joinCost << " (" << numJoins << " joins @ $" << joinCost << " each)" << endl;
    cout << "  Total: $" << dp[targetLength].totalCost << endl;
}

int main()
{
    int d, targetLength, joinCost;

    cout << "=== ROPE PROBLEM WITH JOINING COST ===" << endl;
    cout << "Enter number of rope types: ";
    cin >> d;

    vector<int> ropes(d);
    vector<int> ropeCosts(d);

    cout << "Enter rope lengths and their costs:" << endl;
    for (int i = 0; i < d; i++)
    {
        cout << "Rope " << (i + 1) << " - Length (meters): ";
        cin >> ropes[i];
        cout << "Rope " << (i + 1) << " - Cost ($): ";
        cin >> ropeCosts[i];
    }

    cout << "Enter joining cost per join ($): ";
    cin >> joinCost;

    cout << "Enter target rope length (meters): ";
    cin >> targetLength;

    ropeWithJoiningCost(ropes, ropeCosts, joinCost, targetLength);

    return 0;
}
