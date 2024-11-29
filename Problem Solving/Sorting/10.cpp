#include <bits/stdc++.h>
using namespace std;
// You are given a list of tasks, where each task is represented as
// (StartTime, FinishTime).The goal is to sort the tasks based on their durations(calculated as FinishTime - StartTime) in ascending order.

void selection_sort(vector<pair<int, int>> &tasks)
{
    int n = tasks.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (tasks[j].second - tasks[j].first < tasks[min_index].second - tasks[min_index].first)
            {
                min_index = j;
            }
        }
        swap(tasks[i], tasks[min_index]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    selection_sort(tasks);

    for (int i = 0; i < n; i++)
    {
        cout << tasks[i].first << " " << tasks[i].second << endl;
    }

    return 0;
}