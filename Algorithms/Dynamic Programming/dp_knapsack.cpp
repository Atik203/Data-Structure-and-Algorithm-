#include <bits/stdc++.h>
using namespace std;

int KnapsackBottomUp(int val[], int wt[], int n, int W)
{
    int table[100][100];

    // Initialize first row
    for (int w = 0; w <= W; w++)
    {
        table[0][w] = 0;
    }

    // Fill the table
    for (int i = 1; i <= n; i++) // Start from 1, not 0
    {
        table[i][0] = 0;
        for (int w = 1; w <= W; w++)
        {
            if (wt[i] <= w)
            {
                table[i][w] = max(val[i] + table[i - 1][w - wt[i]], table[i - 1][w]);
            }
            else
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    // Backtrack to find taken items
    int i = n;
    int w = W;
    vector<int> taken_items;
    while (i > 0 && w > 0) // Fixed condition
    {
        if (table[i][w] != table[i - 1][w]) // Item was taken
        {
            taken_items.push_back(i);
            w = w - wt[i];
            i--;
        }
        else
        {
            i--;
        }
    }

    // Print items in the requested format
    cout << "Selected items:" << endl;
    for (int j = taken_items.size() - 1; j >= 0; j--)
    {
        int item_index = taken_items[j];
        cout << "item " << item_index << ": " << wt[item_index] << ".0 kg "
             << val[item_index] << ".0 taka" << endl;
    }
    cout << "profit: " << table[n][W] << " taka" << endl;

    return table[n][W];
}

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int val[n + 1], wt[n + 1];
    val[0] = 0; // Dummy value for 0th index
    wt[0] = 0;  // Dummy weight for 0th index

    cout << "Enter weight and value for each item:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Item " << i << " weight and value: ";
        cin >> wt[i] >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nKnapsack Solution:" << endl;
    KnapsackBottomUp(val, wt, n, W);

    return 0;
}