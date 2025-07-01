#include <bits/stdc++.h>
using namespace std;

int main()
{
    int graph[100][100];
    int n_vertex, n_edge, u, v, w;
    cout << "Enter the number of vertex: ";
    cin >> n_vertex;
    cout << "Enter the number of edge: ";
    cin >> n_edge;

    for (int i = 0; i <= n_vertex; i++)
    {
        for (int j = 0; j <= n_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    vector<pair<int, pair<int, int>>> edges; // Store all edges for Bellman-Ford
    cout << "Enter the graph input (u,v,w) " << endl;
    for (int i = 0; i < n_edge; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    int parent[n_vertex + 10];
    int distance[n_vertex + 10];
    int source;

    for (int i = 0; i <= n_vertex; i++)
    {
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    cout << "Enter source: ";
    cin >> source;
    parent[source] = -1;
    distance[source] = 0;

    // Bellman-Ford Algorithm: Relax edges (V-1) times
    for (int i = 1; i <= n_vertex - 1; i++)
    {
        for (int j = 0; j < n_edge; j++)
        {
            u = edges[j].second.first;
            v = edges[j].second.second;
            w = edges[j].first;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (int j = 0; j < n_edge; j++)
    {
        u = edges[j].second.first;
        v = edges[j].second.second;
        w = edges[j].first;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
    {
        cout << "Graph contains negative weight cycle!" << endl;
        return 0;
    }

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 1; i <= n_vertex; i++)
    {
        if (distance[i] == INT_MAX)
            cout << "Vertex " << i << ": No path" << endl;
        else
            cout << "Vertex " << i << ": " << distance[i] << endl;
    }

    cout << "Enter destination: ";
    int dest;
    cin >> dest;

    if (distance[dest] == INT_MAX)
    {
        cout << "No path from " << source << " to " << dest << endl;
        return 0;
    }

    vector<int> path;
    int current = dest;
    while (current != source)
    {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    cout << "Shortest path: ";
    for (int i = path.size() - 1; i > 0; i--)
    {
        cout << path[i] << " --> ";
    }
    cout << path[0] << endl;
    cout << "Total distance: " << distance[dest] << endl;

    return 0;
}