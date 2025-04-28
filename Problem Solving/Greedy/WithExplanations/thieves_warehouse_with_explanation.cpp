/*
 * Logic Explanation:
 * This algorithm solves a multi-knapsack problem where multiple thieves steal items
 * from a warehouse, each with their own knapsack capacity. The goal is to determine
 * how many thieves are needed to empty the warehouse.
 *
 * Algorithm:
 * 1. Sort items by value-to-weight ratio (highest value per kg first)
 * 2. For each thief:
 *    - Fill their knapsack greedily with the most valuable remaining items
 *    - Items are divisible, so partial items can be taken
 *    - Keep track of items taken and remaining quantities
 *    - Continue until the thief's knapsack is full or warehouse is empty
 * 3. Count how many thieves were needed and report any remaining items
 *
 * Time Complexity: O(n log n) for sorting, plus O(n*k) for the thieves' selections
 * Space Complexity: O(n) for storing items and their remaining quantities
 */
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    string name;
    double value, weight, ratio;
};

bool compare(const Item &a, const Item &b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        double value, weight;
        cin >> items[i].name >> value >> weight;
        items[i] = {items[i].name, value, weight, value / weight};
    }
    int k;
    cin >> k;
    vector<double> capacities(k);
    for (int i = 0; i < k; i++)
    {
        cin >> capacities[i];
    }

    sort(items.begin(), items.end(), compare);

    int thief_count = 0;
    int item_ptr = 0;
    vector<Item> remaining = items;

    for (int t = 0; t < k; ++t)
    {
        double cap = capacities[t];
        double profit = 0.0;
        bool took_any = false;
        cout << fixed << setprecision(1);
        for (int i = 0; i < n; ++i)
        {
            if (remaining[i].weight <= 1e-9)
                continue;
            if (cap <= 1e-9)
                break;
            double take = min(cap, remaining[i].weight);
            double take_value = take * remaining[i].ratio;
            cout << "Taking " << remaining[i].name << ": " << take << " kg " << take_value << " taka" << endl;
            profit += take_value;
            remaining[i].weight -= take;
            cap -= take;
            took_any = true;
        }
        if (took_any)
        {
            thief_count++;
            cout << "Thief " << t + 1 << " profit: " << profit << " taka" << endl;
        }
        // Check if warehouse is empty
        bool empty = true;
        for (int i = 0; i < n; ++i)
        {
            if (remaining[i].weight > 1e-9)
            {
                empty = false;
                break;
            }
        }
        if (empty)
            break;
    }

    cout << "Total " << thief_count << " thieves stole from the warehouse." << endl;
    // Print remaining items
    bool any_left = false;
    for (int i = 0; i < n; ++i)
    {
        if (remaining[i].weight > 1e-9)
        {
            if (!any_left)
            {
                cout << "Still following items are left" << endl;
                any_left = true;
            }
            cout << remaining[i].name << " " << remaining[i].weight << " kg " << remaining[i].weight * remaining[i].ratio << " taka" << endl;
        }
    }
    return 0;
}