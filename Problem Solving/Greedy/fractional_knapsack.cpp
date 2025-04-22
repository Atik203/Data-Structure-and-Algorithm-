#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int index;
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
        double weight, value;
        cin >> weight >> value;
        items[i] = {i + 1, value, weight, value / weight};
    }
    double w;
    cin >> w;

    sort(items.begin(), items.end(), compare);

    double total_value = 0.0;

    vector<tuple<int, double, double>> selected_items;
    for (int i = 0; i < n; i++)
    {

        double fraction = min(w / items[i].weight, 1.0);
        total_value += items[i].value * fraction;
        selected_items.push_back({items[i].index, items[i].weight * fraction, items[i].value * fraction});
        w -= items[i].weight * fraction;
        if (w <= 1e-9)
            break;
    }

    cout << "Selected items:\n";
    for (const auto &item : selected_items)
    {
        int idx;
        double taken_weight, taken_value;
        tie(idx, taken_weight, taken_value) = item;
        cout << "item " << idx << ": " << taken_weight << " kg " << taken_value << " taka" << endl;
    }
    cout << "profit: " << int(total_value) << " taka" << endl;
}
