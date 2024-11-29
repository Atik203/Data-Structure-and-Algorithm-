#include <bits/stdc++.h>
using namespace std;

// Custom comparator function for bubble sort
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second; // Sort by frequency in descending order
    return a.first < b.first;       // If frequencies are the same, sort by value in ascending order
}

// Bubble sort function
void bubble_sort(vector<pair<int, int>> &freq)
{
    int n = freq.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (!compare(freq[j], freq[j + 1]))
            {
                swap(freq[j], freq[j + 1]);
            }
        }
    }
}

void sort_by_frequency(vector<int> &a)
{
    int n = a.size();
    vector<pair<int, int>> freq;

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < freq.size(); j++)
        {
            if (freq[j].first == a[i])
            {
                freq[j].second++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            freq.push_back(make_pair(a[i], 1)); // or freq.push_back({a[i], 1});
        }
    }

    // Sort by frequency and value using bubble sort
    bubble_sort(freq);

    // Reconstruct the array based on sorted frequencies
    int index = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = 0; j < freq[i].second; j++)
        {
            a[index++] = freq[i].first;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort_by_frequency(a);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}