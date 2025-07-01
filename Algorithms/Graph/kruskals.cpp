#include <bits/stdc++.h>
using namespace std;

int n_vertex, n_edge, p[100], rankk[100];

void make_set()
{

    for (int i = 0; i < n_vertex; i++)
    {
        p[i] = i;
        rankk[i] = 0;
    }
}

int find_set(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    else
        return p[x] = find_set(p[x]);
}

int union_sets(int x, int y)
{
    int r1 = find_set(x);
    int r2 = find_set(y);
    if (r1 == r2)
        return 0;
    if (rankk[r1] > rankk[r2])
    {
        p[r2] = r1;
    }
    else
    {
        p[r1] = r2;
        if (rankk[r1] == rankk[r2])
            rankk[r2]++;
    }
    return 1;
}

int main()
{
    vector<pair<int, pair<int, int>>> graph;

    int u, v, w, total_weight = 0;
    cout << "Enter the number of vertex: " << endl;
    cin >> n_vertex;
    cout << "Enter the number of edges: " << endl;
    cin >> n_edge;
    cout << "Enter the graph u,v,w: " << endl;
    for (int i = 0; i < n_edge; i++)
    {
        cin >> u >> v >> w;
        graph.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(graph.begin(), graph.end());

    make_set();

    cout << "Minimum Spanning Tree: " << endl;
    for (int i = 0; i < n_edge; i++)
    {
        u = graph[i].second.first;
        v = graph[i].second.second;
        if (union_sets(u, v) != 0)
        {
            cout << " ( " << u << "," << v << " )" << " --> " << graph[i].first << endl;
            total_weight += graph[i].first;
        }
    }

    cout << "Total MST weight: " << total_weight << endl;

    return 0;
}